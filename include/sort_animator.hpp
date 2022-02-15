#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "gui.hpp"
#include "sort_system.hpp"
#include "sort_op_reciever.hpp"

static const int BOUNDING_THICKNESS = 2;

static const glib::ColorRGBA PLAIN_COLUMN_COLOR = glib::BLACK;
static const glib::ColorRGBA SELECTED_COLUMN_COLOR = glib::PINK;

class SortAnimator: public gui::DummyContainerWidget, public SortOpReciever {
 public:
  SortAnimator(const glib::IntRect& location);

  void SetSortSystem(SortSystem* sort_system);
  void Recieve(AnimSortElem* oprnd) override;

 protected:
  void RenderColumn(const size_t pos, const size_t value, bool highlighted);
  void RenderBoundingBox();
  void Clear();

  glib::RenderTexture* render_texture_ = nullptr;
  SortSystem* sort_system_ = nullptr;
};

#endif /* animation.hpp */
