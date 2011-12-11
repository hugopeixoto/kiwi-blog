
#include <application/base.h>

#include "config/routes.h"
#include "app/controllers/posts.h"

class Application : public kiwi::application::Base
{
  public:
  Application () : kiwi::application::Base()
  {
    set_routing(new config::BlogRouting());
    add_controller(new app::controllers::PostsController());
  }
};

int main()
{
  Application app;
  app.run(3000);
  return 0;
}

