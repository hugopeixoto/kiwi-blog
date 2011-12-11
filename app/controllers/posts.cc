
#include "app/controllers/posts.h"

#include "http/request.h"
#include "helpers/core.h"

// views
#include "app/views/posts/index.cc"
#include "app/views/posts/show.cc"

using app::controllers::PostsController;

PostsController::PostsController () : super("posts")
{
  add_action("index", &PostsController::index, &view_posts_index);
  add_action("show", &PostsController::show, &view_posts_show);
}

void PostsController::index (const kiwi::http::Request& a_http_request)
{
  params.set("name", a_http_request.params["name"]);
}

void PostsController::show (const kiwi::http::Request& a_http_request)
{
  params.set("name", a_http_request.params["name"]);
}

