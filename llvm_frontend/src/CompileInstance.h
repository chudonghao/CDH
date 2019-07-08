//
// Created by cdh on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_COMPILEINSTANCE_H_
#define CDH_LLVM_FRONTED_SRC_COMPILEINSTANCE_H_

#include <string>
#include <vector>
#include "Compiler.h"
#include "CompileTarget.h"

namespace cdh {

class CompileInstance {
 public:
  explicit CompileInstance(const std::string &filename);
  bool operator<(const CompileInstance &compile_instance) const;
 private:
  std::string filename_;
  friend Compiler;
};

}
#endif //CDH_LLVM_FRONTED_SRC_COMPILEINSTANCE_H_
