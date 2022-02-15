#ifndef SORT_OP_RECIEVER_HPP
#define SORT_OP_RECIEVER_HPP

#include "reciever.hpp"
#include "anim_sort_elem.hpp"

class SortOpReciever: public Reciever {
 public:
  SortOpReciever() = default;

  virtual void Recieve(AnimSortElem* oprnd) = 0;
};

#endif /* sort_op_reciever.hpp */
