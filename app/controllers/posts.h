#ifndef APP_CONTROLLERS_POSTS_H_
#define APP_CONTROLLERS_POSTS_H_

#include <controller/base.h>

namespace app {
  namespace controllers {
    class PostsController : public kiwi::controller::Base {
      protected:
      typedef kiwi::controller::Base super;

      public:
      PostsController ();

      protected:
      void index ();

      void show ();
    };
  }
}

#endif // APP_CONTROLLERS_POSTS_H_
