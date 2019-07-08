//
// Created by cdh on 19-7-8.
//

#include "CompileContext.h"

namespace cdh {

void CompileContext::AddInstance(CompileInstance &&compile_instance) {
  compile_instances_.push_back(std::move(compile_instance));
}
std::list<CompileInstance> &CompileContext::CompileInstances() {
  return compile_instances_;
}
const std::string &CompileContext::OutputDir() const {
  return output_dir_;
}
void CompileContext::SetOutputDir(const std::string &output_dir) {
  output_dir_ = output_dir;
}
}
