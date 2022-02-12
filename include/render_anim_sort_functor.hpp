#ifndef RENDER_ANIM_SORT_FUNCTOR_HPP
#define RENDER_ANIM_SORT_FUNCTOR_HPP

#include "gui.hpp"
#include "sort_animator.hpp"

class RenderAnimSortFunctor: gui::AbstractWidgetFunctor {
 public:
  RenderAnimSortFunctor() = default;
  RenderAnimSortFunctor(SortSystem* sort_system, SortAnimator* sort_animator, const SortType sort_type);

  void SetSortSystem(SortSystem* sort_system);
  void SetSortAnimator(SortAnimator* sort_animator);
  void SetSortType(const SortType sort_type);

  void operator()() override;

 protected:
  SortSystem*     sort_system_ = nullptr;
  SortAnimator* sort_animator_ = nullptr;
  SortType          sort_type_ = SortType::QUICK;
};

#endif /* render_anim_sort_functor.hpp */
