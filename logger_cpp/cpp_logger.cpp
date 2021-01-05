#include "cpp_logger.h"

void my_custom_logger::init_logging(std::string log_filename)
{

	logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

	logging::add_file_log(
		keywords::file_name = log_filename + "_%Y-%m-%d_%H-%M-%S.%2N.log",
		keywords::rotation_size = 10 * 1024 * 1024, // size based rotation (reset logger after file size > 10 MB)
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(18, 8, 0), // time based rotation
		//keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] [%LineID%] %Message%"
		keywords::format = "[%TimeStamp%] [%ThreadID%] [%ProcessID%]  [%LineID%] %Message%"

	);

	logging::add_console_log(std::cout,
		boost::log::keywords::format = ">> %Message%");

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::trace
	);

	logging::add_common_attributes();
}

void my_custom_logger::StopFileLogging() {
	logging::core::get()->remove_sink(g_file_sink);
	g_file_sink.reset();
}

void my_custom_logger::log_msg(std::string msg, int logLevel)
{
	switch (logLevel)
	{
	case 1:
	{
		BOOST_LOG_TRIVIAL(trace) << msg;
		break;
	}

	case 2:
	{
		BOOST_LOG_TRIVIAL(debug) << msg;
		break;
	}

	case 3:
	{
		BOOST_LOG_TRIVIAL(info) << msg;
		break;
	}

	case 4:
	{
		BOOST_LOG_TRIVIAL(warning) << msg;
		break;
	}

	case 5:
	{
		BOOST_LOG_TRIVIAL(error) << msg;
		break;
	}

	case 6:
	{
		BOOST_LOG_TRIVIAL(fatal) << msg;
		break;
	}

	default:
	{
		BOOST_LOG_TRIVIAL(trace) << "This is an informational severity message";
		break;
	}

	}

}

