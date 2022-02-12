#ifndef SORTING_SYSTEM_HPP
#define SORTING_SYSTEM_HPP

#include "sorts.hpp"
#include "anim_sort_elem.hpp"
#include <queue>

enum class SortType {
  SELECTION,
  QUICK,
  MERGE,
  STD_SORT,
  STD_STABLE_SORT,
  BUBBLE,
  SORTS_CNT
};

static const size_t DEFAULT_ARRAY_SIZE = 100;

class SortingSystem {
 public:
  SortingSystem();
  ~SortingSystem() = default;

  void Resize(const size_t new_size);
  void SetComparing(const AnimSortElem* first, const AnimSortElem* second);
  void SetAssign(const AnimSortElem* dst, const AnimSortElem* src);

  const std::vector<AnimSortElem>& GetArray() const;

 protected:
  bool sorted_ = false;

  std::vector<AnimSortElem> array_;
  std::queue<size_t> active_elems_ids_;

  void AddActiveElem(const AnimSortElem* active_elem);

  void SetDefaultValues(const size_t left, const size_t right);
  void ShuffleArray(const size_t left, const size_t right);

  void Sort(const SortType sort_type, const size_t left, const size_t right);
};

#endif /* sorting_system.hpp */
