//
// Created by cdh on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_COMPILECONTEXT_H_
#define CDH_LLVM_FRONTED_SRC_COMPILECONTEXT_H_

#include <list>
#include "CompileInstance.h"
#include "CompileTarget.h"
namespace cdh {

class CompileContext {
 public:
  void AddInstance(CompileInstance &&compile_instance);
  std::list<CompileInstance> &CompileInstances();
  const std::string &OutputDir() const;
  void SetOutputDir(const std::string &output_dir);
 private:
  std::list<CompileInstance> compile_instances_;
  std::list<CompileTarget> compile_targets_;
  std::string output_dir_{};
};

}
#endif //CDH_LLVM_FRONTED_SRC_COMPILECONTEXT_H_
