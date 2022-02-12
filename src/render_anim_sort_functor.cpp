#include "render_anim_sort_functor.hpp"

RenderAnimSortFunctor::RenderAnimSortFunctor(SortSystem* sort_system, SortAnimator* sort_animator, const SortType sort_type):
                       sort_system_(sort_system), sort_animator_(sort_animator), sort_type_(sort_type) {
  assert(sort_animator != nullptr);
}

void RenderAnimSortFunctor::SetSortSystem(SortSystem* sort_system) {
  assert(sort_system != nullptr);

  sort_system_ = sort_system;
}

void RenderAnimSortFunctor::SetSortType(const SortType sort_type) {
  sort_type_ = sort_type;
}

void RenderAnimSortFunctor::SetSortAnimator(SortAnimator* sort_animator) {
  assert(sort_animator != nullptr);

  sort_animator_ = sort_animator;
}

void RenderAnimSortFunctor::operator()() {
  assert(sort_animator_ != nullptr);
  assert(sort_system_ != nullptr);

  AnimSortElem::SetSortingSystem()
  sort_system_.
}
