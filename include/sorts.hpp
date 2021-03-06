#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <random>

template<typename T>
bool CheckAlloc(T* ptr) {
  if (ptr == nullptr) {
    std::cout << "bad alloc\n";
    return false;
  } else {
    return true;
  }
}

template<typename T>
void BubbleSort(T* array, size_t left, size_t right) {
  assert(array != nullptr);

  for (size_t i = left; i <= right; i++) {
    for (size_t j = left; j + i < right + left; j++) {
      if (array[j + 1] < array[j]) {
        std::swap(array[j], array[j + 1]);
      }
    }
  }
}

template<typename T>
void SelectionSort(T* array, size_t left, size_t right) {
  assert(array != nullptr);

  for (size_t i = left; i <= right; ++i) {
    size_t min_id = i;
    for (size_t j = i; j <= right; ++j) {
      if (array[j] < array[min_id]) {
        min_id = j;
      }
    }
    if (i != min_id) {
      std::swap(array[i], array[min_id]);
    }
  }
}

template<typename T>
void QuickSort(T* array, size_t left, size_t right) {
  assert(array != nullptr);

  T pivot = array[(left + right) / 2];

  size_t left_id = left, right_id = right;

  while (left_id <= right_id && right_id <= right) {
    while (array[left_id] < pivot) {
      ++left_id;
    }
    while (pivot < array[right_id]) {
      --right_id;
    }
    if (left_id <= right_id) {
      std::swap(array[left_id], array[right_id]);
      ++left_id;
      --right_id;
    }
  }

  if (left < right_id && right_id <= right) {
    QuickSort(array, left, right_id);
  }
  if (left_id < right) {
    QuickSort(array, left_id, right);
  }
}

template<typename T>
void Merge(T* array, size_t left, size_t mid, size_t right, T* tmp_buffer) {
  assert(array != nullptr);
  assert(tmp_buffer != nullptr);

  size_t left_id = left,
    right_id = mid,
    tmp_buffer_id = 0;

  while (left_id < mid && right_id < right) {
    if (array[left_id] < array[right_id]) {
      tmp_buffer[tmp_buffer_id] = array[left_id++];
    } else {
      tmp_buffer[tmp_buffer_id] = array[right_id++];
    }
    tmp_buffer_id++;
  }

  while (left_id < mid) {
    tmp_buffer[tmp_buffer_id++] = array[left_id++];
  }
  while (right_id < right) {
    tmp_buffer[tmp_buffer_id++] = array[right_id++];
  }

  for (size_t i = left; i < right; ++i) {
    array[i] = tmp_buffer[i - left];
  }
}

template<typename T>
void MergeSortRecursive(T* array, size_t left, size_t right, T* tmp_buffer) {
  assert(array != nullptr);
  assert(tmp_buffer != nullptr);

  if (left + 1 >= right) {
    return;
  }

  size_t mid = (left + right) / 2;

  MergeSortRecursive(array, left, mid, tmp_buffer);
  MergeSortRecursive(array, mid, right, tmp_buffer);

  Merge(array, left, mid, right, tmp_buffer);
}

template<typename T>
void MergeSort(T* array, size_t left, size_t right) {
  assert(array != nullptr);

  T* tmp_buffer = new T[right - left + 1];
  if (!CheckAlloc(tmp_buffer)) {
    return;
  }

  MergeSortRecursive(array, left, right + 1, tmp_buffer);

  delete[] tmp_buffer;
}

template<typename T>
bool CheckIncrease(T* array, size_t left, size_t right) {
  assert(array != nullptr);

  for (size_t i = left; i < right; ++i) {
    if (array[i + 1] < array[i]) {
      return false;
    }
  }

  return true;
}

template<typename T>
void EnterArray(T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

template<typename T>
void PrintArray(const T* array, size_t size) {
  assert(array != nullptr);

  for (size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

#endif /* sorst.hpp */
