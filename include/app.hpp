#ifndef APP_HPP
#define APP_HPP

static const int APP_WIDTH = 1200;
static const int APP_HEIGHT = 800;

#include "gui.hpp"

class App {
 private:
  App();
  ~App();

  glib::RenderWindow m_render_window;
  gui::WidgetManager& m_widget_manager = gui::WidgetManager::GetInstance();
 public:
  static App& GetInstance();

  glib::RenderWindow* GetRenderWindow();

  void Init();
  void Exec();
};

#endif /* app.hpp */
