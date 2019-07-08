//
// Created by cdh on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_COMPILEMANAGER_H_
#define CDH_LLVM_FRONTED_SRC_COMPILEMANAGER_H_
#include "Project.h"
#include "CompileContext.h"
namespace cdh{

class CompileManager {
 public:
  void SetProject(Project &project);
  void StartCompile();
  void SetOutputDir(const std::string &output_dir);
 private:
  Project *project_{};
  CompileContext compile_context_{};
};

}
#endif //CDH_LLVM_FRONTED_SRC_COMPILEMANAGER_H_
