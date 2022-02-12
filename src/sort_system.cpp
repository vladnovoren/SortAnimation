#include "sort_system.hpp"

SortSystem::SortSystem() {
  Resize(DEFAULT_ARRAY_SIZE);
}

void SortSystem::Resize(const size_t new_size) {
  array_.resize(new_size);
}

void SortSystem::SetDefaultValues(const size_t left, const size_t right) {
  for (size_t i = left; i <= right; ++i) {
    array_[i].value_ = i;
  }
}

void SortSystem::ShuffleArray(const size_t left, const size_t right) {
  std::shuffle(array_.begin() + left, array_.begin() + right + 1, std::default_random_engine());
}

void SortSystem::Sort(const SortType sort_type, const size_t left, const size_t right) {
  switch (sort_type) {
    case SortType::BUBBLE:
      BubbleSort(array_.data(), left, right);
      break;
    case SortType::SELECTION:
      SelectionSort(array_.data(), left, right);
      break;
    case SortType::QUICK:
      QuickSort(array_.data(), left, right);
      break;
    case SortType::MERGE:
      MergeSort(array_.data(), left, right);
      break;
    case SortType::STD_SORT:
      std::sort(array_.begin() + left, array_.begin() + right + 1);
      break;
    case SortType::STD_STABLE_SORT:
      std::stable_sort(array_.begin() + left, array_.begin() + right + 1);
      break;
    default:
      std::cout << "invalid SortType\n";
      break;
  }
}

void SortSystem::SetComparing(const AnimSortElem* first, const AnimSortElem* second) {
  assert(first  != nullptr);
  assert(second != nullptr);

  AddActiveElem(first);
  AddActiveElem(second);
}

void SortSystem::SetAssign(const AnimSortElem* dst, const AnimSortElem* src) {
  assert(dst != nullptr);
  assert(src != nullptr);

  AddActiveElem(src);
  AddActiveElem(dst);
}

const std::vector<AnimSortElem>& SortSystem::GetArray() const {
  return array_;
}

void SortSystem::AddActiveElem(const AnimSortElem* active_elem) {
  assert(active_elem != nullptr);


  active_elems_.push(active_elem);
}