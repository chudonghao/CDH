//
// Created by chudonghao on 19-1-20.
//
#include <iostream>
#include <boost/log/common.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/trivial.hpp>
#include "log.h"
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
// TODO Clion Error of expr: High CPU USAGE
//namespace expr = boost::log::expressions;

using namespace std;
namespace cdh {
namespace log {
void InitLogging(boost::log::trivial::severity_level l) {
  logging::register_simple_formatter_factory<logging::trivial::severity_level,
                                             char>("Severity");
  logging::add_console_log(cout,
                           keywords::format =
                               "[%TimeStamp%][%ThreadID%][%Severity%] %File%:%Line% %Message%",
                           keywords::auto_flush = true);
  logging::core::get()->set_filter(logging::trivial::severity >= l);
  logging::core::get()
      ->add_global_attribute("Line", attrs::mutable_constant<int>(0));
  logging::core::get()
      ->add_global_attribute("File", attrs::mutable_constant<std::string>(""));
  logging::core::get()->add_global_attribute("Function",
                                             attrs::mutable_constant<std::string>(
                                                 ""));
  logging::add_common_attributes();
}
void UpdateSourceLocation(const std::string &file,
                          const std::string &func,
                          int line) {
  logging::attribute_cast<attrs::mutable_constant<std::string>>
      (logging::core::get()->get_global_attributes()["File"]).set(file);
  logging::attribute_cast<attrs::mutable_constant<std::string>>
      (logging::core::get()->get_global_attributes()["Function"]).set(func);
  logging::attribute_cast<attrs::mutable_constant<int>>
      (logging::core::get()->get_global_attributes()["Line"]).set(line);
}
}
}
