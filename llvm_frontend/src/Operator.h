//
// Created by cdh on 19-7-10.
//

#ifndef CDH_LLVM_FRONTED_SRC_OPERATOR_H_
#define CDH_LLVM_FRONTED_SRC_OPERATOR_H_
#include <map>
namespace cdh {

class Operator {
  std::map<char, Operator> sub_operator_{};
  int i_{};
  int priority_{-1};
  bool has_sub_operator_{};
 public:
  Operator(int i, int priority, bool has_sub_operator);
  Operator() = default;
  int I() const;
  int Priority() const;
  bool HasSubOperator() const;
  static const Operator &Helper();
  const Operator &operator[](char ch) const;
};

}

#endif //CDH_LLVM_FRONTED_SRC_OPERATOR_H_
