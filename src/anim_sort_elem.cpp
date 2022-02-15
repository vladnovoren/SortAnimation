#include "anim_sort_elem.hpp"
#include "sort_system.hpp"

AnimSortElem::AnimSortElem(const int& value): value_(value) {}

AnimSortElem::AnimSortElem(const AnimSortElem& other): value_(other.value_) {}

AnimSortElem& AnimSortElem::operator=(const AnimSortElem& other) {
  assert(sorting_system_ != nullptr);

  value_ = other.value_;
  sorting_system_ = other.sorting_system_;
  sorting_system_->SetAssign(this, &other);
  return *this;
}

bool AnimSortElem::operator<(const AnimSortElem& right) const {
  assert(sorting_system_ != nullptr);

  sorting_system_->SetComparing(this, &right);
  return value_ < right.value_;
}

bool AnimSortElem::operator>(const AnimSortElem& right) const {
  assert(sorting_system_ != nullptr);

  sorting_system_->SetComparing(this, &right);
  return value_ > right.value_;
}

bool AnimSortElem::operator<=(const AnimSortElem& right) const {
  assert(sorting_system_ != nullptr);

  sorting_system_->SetComparing(this, &right);
  return value_ <= right.value_;
}

bool AnimSortElem::operator>=(const AnimSortElem& right) const {
  assert(sorting_system_ != nullptr);

  sorting_system_->SetComparing(this, &right);
  return value_ >= right.value_;
}

std::ostream& operator<<(std::ostream& os, const AnimSortElem& elem) {
  os << elem.value_;
  return os;
}

std::istream& operator>>(std::istream& is, AnimSortElem& elem) {
  is >> elem.value_;
  return is;
}

void AnimSortElem::SetSortingSystem(SortSystem* sorting_system) {
  assert(sorting_system != nullptr);

  sorting_system_ = sorting_system;

}

AnimSortElem::operator int() const {
  return value_;
}

SortSystem* AnimSortElem::sorting_system_ = nullptr;
