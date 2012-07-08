
#include "app/controllers/posts.h"

#include "http/request.h"
#include "helpers/core.h"

// models
#include "app/models/post.h"
using app::controllers::PostsController;
using app::models::Post;

// views: not sure where these should go. I need the previous includes |:
#include "app/views/posts/index.cc"
#include "app/views/posts/show.cc"
#include "app/views/posts/edit.cc"

PostsController::PostsController () : super("posts")
{
  add_action<PostsController>("index",  &PostsController::index,  &PostsController::view_posts_index);
  add_action<PostsController>("show",   &PostsController::show,   &PostsController::view_posts_show);
  add_action<PostsController>("edit",   &PostsController::edit,   &PostsController::view_posts_edit);
  add_action<PostsController>("update", &PostsController::update, &PostsController::view_nothing);
}

void PostsController::index ()
{
  params.set("posts", Post::all());
}

void PostsController::show ()
{
  Post* post = Post::find(params["id"]);
  params.set("post", post);
}

void PostsController::edit ()
{
  Post* post = Post::find(params["id"]);
  params.set("post", post);
}

void PostsController::update ()
{
  Post* post = Post::find(params["id"]);
}
