#ifndef SORT_SYSTEM_HPP
#define SORT_SYSTEM_HPP

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

class SortSystem {
 public:
  SortSystem();
  ~SortSystem() = default;

  void Resize(const size_t new_size);
  void SetComparing(const AnimSortElem* first, const AnimSortElem* second);
  void SetAssign(const AnimSortElem* dst, const AnimSortElem* src);

  const std::vector<AnimSortElem>& GetArray() const;

 protected:
  bool sorted_ = false;

  std::vector<AnimSortElem> array_;

  void SetDefaultValues(const size_t left, const size_t right);
  void ShuffleArray(const size_t left, const size_t right);

  void Sort(const SortType sort_type, const size_t left, const size_t right);
};

#endif /* sort_system.hpp */
