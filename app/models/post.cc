
#include "post.h"

using app::models::Post;

template<>
const char kiwi::model::Base<Post>::model_name_[] = "post";

template<>
const kiwi::model::Base<Post>::ColumnList kiwi::model::Base<Post>::columns_ = {
  "id",
  "name",
  "body"
};

