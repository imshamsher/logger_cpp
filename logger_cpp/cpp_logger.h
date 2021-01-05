#pragma once
#include <iostream>

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/date_time.hpp>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>

//namespace is = ImageStitching;
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;

typedef sinks::synchronous_sink< sinks::text_file_backend > sink_t;

class my_custom_logger
{
public:
	boost::shared_ptr< sink_t > g_file_sink;
	std::string log_filename = "sample";
	void init_logging(std::string logname = "sample");
	void log_msg(std::string msg = "Welcome to boost.logs", int logLevel = 0);
	void StopFileLogging();
};
