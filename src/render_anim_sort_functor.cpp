#include "render_anim_sort_functor.hpp"

RenderAnimSortFunctor::RenderAnimSortFunctor(SortAnimator* sort_animator, const SortType sort_type):
                       sort_animator_(sort_animator), sort_type_(sort_type) {
  assert(sort_animator != nullptr);
}

void RenderAnimSortFunctor::SetSortType(const SortType sort_type) {
  sort_type_ = sort_type;
}

void RenderAnimSortFunctor::SetSortAnimator(SortAnimator* sort_animator) {
  assert(sort_animator != nullptr);

  sort_animator_ = sort_animator;
}

void RenderAnimSortFunctor::operator()() {
  
}
