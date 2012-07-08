#ifndef APP_CONTROLLERS_POSTS_H_
#define APP_CONTROLLERS_POSTS_H_

#include <controller/base.h>
#include <config/controller.h>

namespace app {
  namespace controllers {
    class PostsController : public config::ApplicationController {
      protected:
      typedef config::ApplicationController super;

      public:
      PostsController ();

      protected:
      void index ();
      void show ();
      void edit ();
      void update ();
    };
  }
}

#endif // APP_CONTROLLERS_POSTS_H_
