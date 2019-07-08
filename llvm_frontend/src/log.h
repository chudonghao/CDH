/**
 * Created by chudonghao on 19-1-20.
 * Dependence: Boost::log Boost::setup [pthread[linux](if multithreading log enabled)]
 * Compile Definitions: -DBOOST_LOG_DYN_LINK
 */

#ifndef THESIS_LOG_H
#define THESIS_LOG_H
#include <boost/log/trivial.hpp>
#include <sstream>
namespace cdh {
namespace log {
void InitLogging(boost::log::trivial::severity_level l = boost::log::trivial::severity_level::trace);
void UpdateSourceLocation(const std::string &file,
                          const std::string &func,
                          int line);
class Logger {
 public:
  template<typename T>
  Logger &operator<<(const T &t) {
    ss_ << t;
    return *this;
  }
  Logger(const boost::log::trivial::severity_level lvl,
         const char *file,
         const char *func,
         const int line) : lvl_(lvl), file_(file), func_(func), line_(line) {
  }
  ~Logger() {
    UpdateSourceLocation(file_, func_, line_);
    BOOST_LOG_STREAM_WITH_PARAMS(::boost::log::trivial::logger::get(),
                                 (::boost::log::keywords::severity = lvl_))
      << ss_.str();
  }
  const ::boost::log::trivial::severity_level lvl_;
  const char *file_;
  const char *func_;
  const int line_;
  std::stringstream ss_;
};

}
}
#if defined(LOG_TRACE) || defined(LOG_DEBUG) || defined(LOG_INFO) || defined(LOG_WARNING) || defined(LOG_ERROR) || defined(LOG_FATAL)
#error "LOG_* micros are defined.(TODO)"
#else
//#define LOG_TRACE cdh::log::UpdateSourceLocation(__FILE__,__PRETTY_FUNCTION__,__LINE__);BOOST_LOG_TRIVIAL(trace)
#define LOG_TRACE cdh::log::Logger(::boost::log::trivial::trace,__FILE__,__func__,__LINE__)
#define LOG_DEBUG cdh::log::Logger(::boost::log::trivial::debug,__FILE__,__func__,__LINE__)
#define LOG_INFO cdh::log::Logger(::boost::log::trivial::info,__FILE__,__func__,__LINE__)
#define LOG_WARNING cdh::log::Logger(::boost::log::trivial::warning,__FILE__,__func__,__LINE__)
#define LOG_ERROR cdh::log::Logger(::boost::log::trivial::error,__FILE__,__func__,__LINE__)
#define LOG_FATAL cdh::log::Logger(::boost::log::trivial::fatal,__FILE__,__func__,__LINE__)
#endif
#endif //THESIS_LOG_H
