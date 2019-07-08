//
// Created by cdh on 19-7-10.
//

#include "Operator.h"
#include <map>
using namespace std;
namespace cdh {

const Operator &Operator::operator[](char ch) const {
  auto iter = sub_operator_.find(ch);
  if (iter == sub_operator_.end()) {
    const static Operator operator_ = Operator();
    return operator_;
  } else {
    return (*iter).second;
  }
}
const Operator &Operator::Helper() {
  static Operator *operator__ = nullptr;
  if (!operator__) {
    operator__ = new Operator(0, -1, true);
    auto &operator_ = *operator__;
    operator_.sub_operator_[','] = Operator(0, 100, false);
    operator_.sub_operator_[';'] = Operator(0, 100, false);
    operator_.sub_operator_['('] = Operator(0, 100, false);
    operator_.sub_operator_[')'] = Operator(0, 1, false);
    operator_.sub_operator_['['] = Operator(0, 2, false);
    operator_.sub_operator_[']'] = Operator(0, 3, false);
    operator_.sub_operator_['{'] = Operator(0, 4, false);
    operator_.sub_operator_['}'] = Operator(0, 5, false);
    operator_.sub_operator_[':'] = Operator(0, 6, true);

    operator_.sub_operator_['='] = Operator(0, 7, true);
    operator_.sub_operator_['+'] = Operator(0, 8, true);
    operator_.sub_operator_['-'] = Operator(0, 9, true);
    operator_.sub_operator_['*'] = Operator(0, 10, true);
    operator_.sub_operator_['/'] = Operator(0, 11, true);

    operator_.sub_operator_['+'].sub_operator_['='] = Operator(0, 12, false);
    operator_.sub_operator_['-'].sub_operator_['='] = Operator(0, 13, false);
    operator_.sub_operator_['*'].sub_operator_['='] = Operator(0, 14, false);
    operator_.sub_operator_['/'].sub_operator_['='] = Operator(0, 15, false);

    operator_.sub_operator_['='].sub_operator_['='] = Operator(0, 16, false);

    operator_.sub_operator_[':'].sub_operator_[':'] = Operator(0, 17, false);
  }
  return *operator__;
}
int Operator::I() const {
  return i_;
}
int Operator::Priority() const {
  return priority_;
}
bool Operator::HasSubOperator() const {
  return has_sub_operator_;
}
Operator::Operator(int i, int priority, bool has_sub_operator) : i_(i), priority_(priority), has_sub_operator_(has_sub_operator) {}

}
