/**
 * @file config/routes.cc
 *
 * Contains the application routes.
 */
#include "config/routes.h"

config::BlogRouting::BlogRouting ()
{
  resource("posts");
  root("posts", "index");
}

