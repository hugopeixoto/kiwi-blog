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
      void index (const kiwi::http::Request& a_http_request);

      void show (const kiwi::http::Request& a_http_request);
    };
  }
}

#endif // APP_CONTROLLERS_POSTS_H_
