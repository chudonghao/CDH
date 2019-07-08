//
// Created by chudonghao on 19-7-8.
//

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include "Project.h"
#include "CompileManager.h"
#include "log.h"

using namespace std;
using namespace cdh;
using cdh::log::InitLogging;
namespace po = boost::program_options;
namespace filesystem = boost::filesystem;


int main(int argc, char *argv[]) {
  InitLogging();
  string project_dir;
  string output_dir;

  po::options_description desc("Allowed options");
  desc.add_options()(
      "help", "produce help message")(
      "project_dir:p", po::value<string>(&project_dir)->default_value("."), "project dir")(
      "output_dir:o", po::value<string>(&output_dir)->default_value("/tmp"), "output dir");
  po::variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
    return 0;
  }

  Project project;
  project.SetDirectory(project_dir);
  CompileManager compile_manager;
  compile_manager.SetProject(project);
  compile_manager.SetOutputDir(output_dir);
  compile_manager.StartCompile();

  return 0;
}
