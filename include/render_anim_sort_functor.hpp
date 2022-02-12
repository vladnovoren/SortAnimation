#ifndef RENDER_ANIM_SORT_FUNCTOR_HPP
#define RENDER_ANIM_SORT_FUNCTOR_HPP

#include "gui.hpp"
#include "sort_animator.hpp"

class RenderAnimSortFunctor: gui::AbstractWidgetFunctor {
 public:
  RenderAnimSortFunctor() = default;
  RenderAnimSortFunctor(SortAnimator* sort_animator, const SortType sort_type);

  void SetSortAnimator(SortAnimator* sort_animator);
  void SetSortType(const SortType sort_type);

  void operator()() override;

 protected:
  SortAnimator* sort_animator_ = nullptr;
  SortType          sort_type_ = SortType::QUICK;
};

#endif /* render_anim_sort_functor.hpp */
