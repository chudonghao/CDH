//
// Created by cdh on 19-7-8.
//

#ifndef CDH_LLVM_FRONTED_SRC_PROJECT_H_
#define CDH_LLVM_FRONTED_SRC_PROJECT_H_

#include <string>
#include <vector>
namespace cdh{

class Project {
 public:
  const std::string &Directory() const;
  void SetDirectory(const std::string &directory);
  void AddSrc(const std::string &filename);
 private:
  std::string directory_;
  std::vector<std::string> srcs_;
 public:
  const std::vector<std::string> &Srcs() const;
};

}
#endif //CDH_LLVM_FRONTED_SRC_PROJECT_H_
