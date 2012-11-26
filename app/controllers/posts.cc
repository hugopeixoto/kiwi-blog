
#include "app/controllers/posts.h"

#include "http/request.h"
#include "helpers/core.h"
#include <stdlib.h>

// models
#include "app/models/post.h"
using app::controllers::PostsController;
using app::models::Post;

// views: not sure where these should go. I need the previous includes |:
#include "app/views/posts/index.cc"
#include "app/views/posts/show.cc"
#include "app/views/posts/edit.cc"

#include "activerecord/base.h"
#include "activerecord/postgresql/connection.h"

#include <iostream>

Post::AttributeMap post_params (const PostsController::Parameters& a_params)
{
    Post::AttributeMap params;

    params["title"] = kiwi::model::Attribute("Pokemon");
    params["body"] = kiwi::model::Attribute("These are so cute!");

    for (auto x : a_params) {
      std::cout << x.first << "=" << x.second << std::endl;
    }

    return params;
}

PostsController::PostsController () : super("posts")
{
  kiwi::activerecord::Base::connection = new kiwi::activerecord::postgresql::Connection();
  kiwi::activerecord::Base::connection->connect("blog");

  add_action<PostsController>("index",  &PostsController::index,  &PostsController::view_posts_index);
  add_action<PostsController>("show",   &PostsController::show,   &PostsController::view_posts_show);
  add_action<PostsController>("edit",   &PostsController::edit,   &PostsController::view_posts_edit);
  add_action<PostsController>("update", &PostsController::update, &PostsController::view_nothing);
}

void PostsController::index ()
{
  view.set("posts", Post::all());
}

void PostsController::show ()
{
  Post* post = Post::find(atoi(params["id"].c_str()));
  view.set("post", post);
}

void PostsController::edit ()
{
  Post* post = Post::find(atoi(params["id"].c_str()));
  view.set("post", post);
}

void PostsController::update ()
{
  Post* post = Post::find(atoi(params["id"].c_str()));
  post->update_attributes(post_params(params));
}

