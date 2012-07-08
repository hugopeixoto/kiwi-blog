
#ifndef CONFIG_CONTROLLER_H_
#define CONFIG_CONTROLLER_H_

#include <controller/base.h>
#include <http/response.h>
#include <view/base.h>

#include <helpers/forms.h>

// Maybe the includes should go here?

namespace config {
  class ApplicationController : public kiwi::controller::Base,
                                virtual public kiwi::helpers::Forms,
                                virtual public kiwi::view::Base {
    protected:
      typedef kiwi::controller::Base super;

    public:
      ApplicationController (const std::string& a_name) : super(a_name) { }

      /**
       * @brief Derp
       */
      bool render (View& a_view, kiwi::http::Response& a_response);

      /**
       * @brief Views. This should be made automatically, probably.
       */
      void view_posts_show ();
      void view_posts_edit ();
      void view_posts_index ();
      void view_nothing () {}

  };

  inline bool ApplicationController::render (View& a_view, kiwi::http::Response& a_response)
  {
    a_response.start_body();
    with_output_buffer(a_view, a_response);
    a_response.finish_body();

    return true;
  }
}

#endif
