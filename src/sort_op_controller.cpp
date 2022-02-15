#include "sort_op_controller.hpp"

void SortOpController::AddElem(AnimSortElem* new_elem) {
  assert(new_elem != nullptr);

  elems_.push(new_elem);
  while (elems_.size() > 2) {
    elems_.pop();
  }
  Dispense();
}

void SortOpController::Dispense() {
  for (auto& reciever: recievers_) {
    assert(reciever != nullptr);

    DispenseForOne(reciever);
  }
}

void SortOpController::DispenseForOne(SortOpReciever* reciever) {
  assert(reciever != nullptr);

  for (auto& elem: elems_) {
    reciever->Recieve(elem);
  }
}

void SortOpController::SignInReciever(SortOpReciever* reciever) {
  assert(reciever != nullptr);

  auto found = std::find(recievers_.begin(), recievers_.end(), reciever);
  if (found == recievers_.end()) {
    recievers_.push_back(reciever);
  }
}

void SortOpController::SignOutReciever(SortOpReciever* reciever) {
  assert(reciever != nullptr);

  auto found = std::find(recievers_.begin(), recievers_.end(), reciever);
  if (found != recievers_.end()) {
    recievers_.erase(found);
  }
}
