
#ifndef APP_MODELS_POST_H_
#define APP_MODELS_POST_H_

#include <model/base.h>

namespace app {
  namespace models {
    class Post : public kiwi::model::Base<Post> {
      public:
      typedef kiwi::model::Base<Post> super;

      // C++11 specifies constructor inheritance, but g++ doesn't support it yet :-(
      Post (const AttributeMap& a_params) : super(a_params) { }

      protected:
    };
  }
}

#endif // APP_MODELS_POST_H_
