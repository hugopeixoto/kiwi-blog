
#include "app/controllers/posts.h"

#include "http/request.h"
#include "helpers/core.h"

// models
#include "app/models/post.h"
using app::controllers::PostsController;
using app::models::Post;

// views
#include "app/views/posts/index.cc"
#include "app/views/posts/show.cc"

PostsController::PostsController () : super("posts")
{
  add_action("index", &PostsController::index, &view_posts_index);
  add_action("show", &PostsController::show, &view_posts_show);
}

void PostsController::index (const kiwi::http::Request& a_http_request)
{
  params.set("posts", Post::all());
}

void PostsController::show (const kiwi::http::Request& a_http_request)
{
  Post* post = Post::find(params["id"]);
  params.set("post", post);
}

