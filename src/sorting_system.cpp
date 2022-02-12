#include "sorting_system.hpp"

SortingSystem::SortingSystem() {
  Resize(DEFAULT_ARRAY_SIZE);
}

void SortingSystem::Resize(const size_t new_size) {
  array_.resize(new_size);
}

void SortingSystem::SetDefaultValues(const size_t left, const size_t right) {
  for (size_t i = left; i <= right; ++i) {
    array_[i].value_ = i;
  }
}

void SortingSystem::ShuffleArray(const size_t left, const size_t right) {
  std::shuffle(array_.begin() + left, array_.begin() + right + 1, std::default_random_engine());
}

void SortingSystem::Sort(const SortType sort_type, const size_t left, const size_t right) {
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

void SortingSystem::SetComparing(const AnimSortElem* first, const AnimSortElem* second) {
  assert(first  != nullptr);
  assert(second != nullptr);

  AddActiveElem(first);
  AddActiveElem(second);
}

void SortingSystem::SetAssign(const AnimSortElem* dst, const AnimSortElem* src) {
  assert(dst != nullptr);
  assert(src != nullptr);

  AddActiveElem(src);
  AddActiveElem(dst);
}

const std::vector<AnimSortElem>& SortingSystem::GetArray() const {
  return array_;
}

void SortingSystem::AddActiveElem(const AnimSortElem* active_elem) {
  assert(active_elem != nullptr);


  active_elems_.push(active_elem);
}