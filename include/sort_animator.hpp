#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "gui.hpp"
#include "sorting_system.hpp"

static const int BOUNDING_THICKNESS = 2;

static const glib::ColorRGBA PLAIN_COLUMN_COLOR = glib::BLACK;
static const glib::ColorRGBA SELECTED_COLUMN_COLOR = glib::PINK;

class SortAnimator: gui::DummyContainerWidget {
 public:
  SortAnimator(const glib::IntRect& location, const size_t array_size = DEFAULT_ARRAY_SIZE);

 protected:
  void InitSoringSystem(const size_t array_size);

  void RenderColumn(const size_t pos, const size_t value, bool highlighted);
  void RenderBoundingBox();
  void Clear();

  glib::RenderTexture* render_texture_ = nullptr;
  SortingSystem* sorting_system_ = nullptr;
};

#endif /* animation.hpp */
