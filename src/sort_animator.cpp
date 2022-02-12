#include "sort_animator.hpp"

SortAnimator::SortAnimator(const glib::IntRect& location, const size_t array_size):
              gui::DummyContainerWidget(location) {
  render_texture_->Resize(location.m_size);
  InitSoringSystem(array_size);
}

void SortAnimator::InitSoringSystem(const size_t array_size) {
  sorting_system_ = new SortingSystem;
  sorting_system_->Resize(array_size);
}

void SortAnimator::RenderColumn(const size_t pos, const size_t value, bool highlighted) {
  const std::vector<AnimSortElem>& array = sorting_system_->GetArray();

  double pp_column_x = static_cast<double>(m_location.m_size.x / array.size());
  double pp_column_y = static_cast<double>(m_location.m_size.y / *std::max_element(array.begin(), array.end()));
  double column_height = static_cast<double>(pp_column_y * value);

  glib::IntRect column_rect(glib::Vector2i(pp_column_x * pos, m_location.m_size.y - column_height),
                            glib::Vector2i(pp_column_x, column_height));
  render_texture_->RenderRect(column_rect, highlighted ? SELECTED_COLUMN_COLOR : PLAIN_COLUMN_COLOR);
}

void SortAnimator::RenderBoundingBox() {
  glib::IntLine upper_line(0, 0.5 * BOUNDING_THICKNESS, m_location.m_size.x, 0.5 * BOUNDING_THICKNESS, BOUNDING_THICKNESS);
  glib::IntLine right_line(m_location.m_size.x - 0.5 * BOUNDING_THICKNESS, 0, m_location.m_size.x - 0.5 * BOUNDING_THICKNESS, m_location.m_size.y, BOUNDING_THICKNESS);
  glib::IntLine lower_line(0, m_location.m_size.y - 0.5 * BOUNDING_THICKNESS, m_location.m_size.x, m_location.m_size.y - 0.5 * BOUNDING_THICKNESS, BOUNDING_THICKNESS);
  glib::IntLine left_line(0.5 * BOUNDING_THICKNESS, 0, 0.5 * BOUNDING_THICKNESS, m_location.m_size.y ,BOUNDING_THICKNESS);

  glib::ColorRGBA black;

  render_texture_->RenderLine(lower_line, black);
  render_texture_->RenderLine(upper_line, black);
  render_texture_->RenderLine(right_line, black);
  render_texture_->RenderLine(left_line, black);

  render_texture_->Display();
}
