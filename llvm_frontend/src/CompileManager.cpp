//
// Created by cdh on 19-7-8.
//

#include <iostream>
#include <boost/filesystem.hpp>
#include "log.h"
#include "CompileManager.h"
#include "Compiler.h"
#include "CompileInstance.h"

using namespace std;
using namespace boost;
namespace cdh {

void CompileManager::SetProject(Project &project) {
  project_ = &project;
}
void CompileManager::StartCompile() {
  if (!project_) {
    LOG_ERROR << "错误的项目上下文";
    return;
  }
  if (!filesystem::is_directory(filesystem::absolute(project_->Directory()))) {
    LOG_ERROR << "无效的项目文件夹：" << project_->Directory();
    return;
  }
  if (!filesystem::is_directory(filesystem::absolute(compile_context_.OutputDir()))) {
    LOG_ERROR << "无效的输出文件夹：" << compile_context_.OutputDir();
    return;
  }
  for (auto &p: filesystem::recursive_directory_iterator(project_->Directory())) {
    if (filesystem::is_regular_file(p)) {
      string ext = filesystem::extension(p);
      if (ext == ".cdh") {
        string filename = filesystem::path(p).string();
        LOG_TRACE << filename;
        project_->AddSrc(filename);
      } else {
        LOG_INFO << ext << "是未知的文件类型";
      }
    } else {}
  }

  for (auto &filename:project_->Srcs()) {
    compile_context_.AddInstance(CompileInstance(filename));
  }
  Compiler compiler(compile_context_);
  for (auto &instance:compile_context_.CompileInstances()) {
    compiler.GetSymbolTable(instance);
  }
  compiler.CompileAll();
}
void CompileManager::SetOutputDir(const string &output_dir) {
  compile_context_.SetOutputDir(output_dir);
}
}
