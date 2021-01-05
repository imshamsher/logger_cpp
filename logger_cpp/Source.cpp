//#include <iostream>
//#include <boost/log/trivial.hpp>
//
//int main(int, char*[])
//{
//	BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
//	BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
//	BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
//	BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
//	BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
//	BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
//	std::cin.get();
//	return 0;
//}

//#include <iostream> 
//#include <boost/log/core.hpp> 
//#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp> 
//namespace logging = boost::log; 
//void init_logging() 
//{    
//	logging::core::get()->set_filter (logging::trivial::severity >= logging::trivial::info); 
//} 
//
//int main(int, char*[]) 
//{     
//	init_logging();          
//	BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";     
//	BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";     
//	BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";     
//	BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";     
//	BOOST_LOG_TRIVIAL(error) << "This is an error severity message";     
//	BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";    
//	std::cin.get();     
//	return 0; 
//}

//#include <iostream>
//
//#include <boost/log/trivial.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/expressions.hpp>
//
//namespace logging = boost::log;
//
//void init_logging()
//{
//	logging::add_file_log("sample.log");
//
//	logging::core::get()->set_filter
//	(
//		logging::trivial::severity >= logging::trivial::info
//	);
//}
//
//int main(int, char*[])
//{
//	init_logging();
//
//	BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
//	BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
//	BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
//	BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
//	BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
//	BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
//	std::cin.get();
//	return 0;
//}

//#include <iostream>
//
//#include <boost/log/core.hpp>
//#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/utility/setup/common_attributes.hpp>
//
//namespace logging = boost::log;
//namespace keywords = boost::log::keywords;
//
//void init_logging()
//{
//	logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
//
//	logging::add_file_log(
//		keywords::file_name = "sample.log",
//		keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] [%LineID%] %Message%"
//	);
//
//	logging::core::get()->set_filter
//	(
//		logging::trivial::severity >= logging::trivial::info
//	);
//
//	logging::add_common_attributes();
//}
//
//int main(int, char*[])
//{
//	init_logging();
//
//	BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
//	BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
//	BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
//	BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
//	BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
//	BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
//
//	std::cin.get();
//	return 0;
//}

#include "cpp_logger.h"

int main(int, char*[])
{
	my_custom_logger obj1;
	obj1.init_logging("logs/MyLogger_A");

	while (1)
	{
		obj1.log_msg("Hi this is test message from a", 5);
		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
	}

	std::cin.get();

	return 0;
}