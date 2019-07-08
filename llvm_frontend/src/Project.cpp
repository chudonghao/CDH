//
// Created by cdh on 19-7-8.
//

#include "Project.h"
namespace cdh {

const std::string &Project::Directory() const {
  return directory_;
}
void Project::SetDirectory(const std::string &directory) {
  Project::directory_ = directory;
}
void Project::AddSrc(const std::string &file_name) {
  srcs_.push_back(file_name);
}
const std::vector<std::string> &Project::Srcs() const {
  return srcs_;
}

}
