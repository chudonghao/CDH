//
// Created by cdh on 19-7-8.
//

#include "CompileInstance.h"
cdh::CompileInstance::CompileInstance(const std::string &filename) {
  filename_ = filename;
}

bool cdh::CompileInstance::operator<(const cdh::CompileInstance &compile_instance) const {
  return filename_ < compile_instance.filename_;
}
