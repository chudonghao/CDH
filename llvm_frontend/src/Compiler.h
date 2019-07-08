//
// Created by cdh on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_COMPILER_H_
#define CDH_LLVM_FRONTED_SRC_COMPILER_H_

namespace cdh {
class CompileContext;
class CompileInstance;
class Compiler {
 public:
  explicit Compiler(const CompileContext &compile_context);
  void GetSymbolTable(CompileInstance &instance);
  void CompileAll();
 private:
  void Compile(cdh::CompileInstance &instance);
  const CompileContext &compile_context_;
};

}
#endif //CDH_LLVM_FRONTED_SRC_COMPILER_H_
