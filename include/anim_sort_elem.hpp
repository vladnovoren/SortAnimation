#ifndef ANIM_SORT_ELEM_HPP
#define ANIM_SORT_ELEM_HPP

#include <iostream>

class SortingSystem;

class AnimSortElem {
 public:
  int value_ = 0;

  AnimSortElem() = default;
  AnimSortElem(const int& value);
  AnimSortElem(const AnimSortElem& other);
  ~AnimSortElem() = default;

  AnimSortElem& operator=(const AnimSortElem& other);

  bool operator<(const AnimSortElem& right) const;

  bool operator>(const AnimSortElem& right) const;

  bool operator<=(const AnimSortElem& right) const;

  bool operator>=(const AnimSortElem& right) const;

  void SetSortingSystem(SortingSystem* sorting_system);

  operator int() const;

 protected:
  static SortingSystem* sorting_system_;
};

std::ostream& operator<<(std::ostream& os, const AnimSortElem& elem);

std::istream& operator>>(std::istream& is, AnimSortElem& elem);

#endif /* anim_sort_elem.hpp */
