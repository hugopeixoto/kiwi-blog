
#include "post.h"

using app::models::Post;

template<>
const char Post::super::model_name_[] = "post";

template<>
const Post::super::ColumnList Post::super::columns_ = {
  "id",
  "name",
  "body"
};

