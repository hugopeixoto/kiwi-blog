
#ifndef APP_MODELS_POST_H_
#define APP_MODELS_POST_H_

#include <model/base.h>

namespace app {
  namespace models {
    class Post : public kiwi::model::Base<Post> {
      public:
      Post (const uint64_t& a_id, const std::string& a_name) { id_ = a_id; name_ = a_name; }
      const std::string& name () const { return name_; }
      const uint64_t& id () const { return id_; }

      protected:
      uint64_t id_;
      std::string name_;
    };
  }
}

#endif // APP_MODELS_POST_H_
