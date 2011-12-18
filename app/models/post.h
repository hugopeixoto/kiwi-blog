
#ifndef APP_MODELS_POST_H_
#define APP_MODELS_POST_H_

#include <model/base.h>

namespace app {
  namespace models {
    class Post : public kiwi::model::Base<Post> {
      public:
      Post (const std::string& a_name) { name_ = a_name; }
      const std::string& name () const { return name_; }

      protected:
      std::string name_;
    };
  }
}

#endif // APP_MODELS_POST_H_
