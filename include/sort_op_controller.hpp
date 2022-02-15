#ifndef SORT_OP_CONTROLLER_HPP
#define SORT_OP_CONTROLLER_HPP

#include "anim_sort_elem.hpp"
#include "sort_op_reciever.hpp"
#include "reciever.hpp"
#include <queue>
#include <cassert>

class SortOpController {
 public:
  SortOpController() = default;
  ~SortOpController() = default;

  void AddElem(AnimSortElem* new_elem);
  void SignInReciever(SortOpReciever* new_reciever);
  void SignOutReciever(SortOpReciever* reciever);

 private:
  void Dispense();
  void DispenseForOne(Reciever* reciever);

  std::queue<AnimSortElem*> elems_;
  std::vector<SortOpReciever*> recievers_;
};

#endif /* last_sort_op_controller.hpp */
