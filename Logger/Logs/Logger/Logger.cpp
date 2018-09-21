#include "Logger.h"

namespace MyLogger{

	bool Logger::instanceFlag = false;
	Logger* Logger::logger = NULL;

	Logger::Logger(){
		//std::cout << "Constructor" << std::endl;
		file.open("log.txt", std::ios_base::app);
	}

	Logger::~Logger(){
		//std::cout << "Destructor" << std::endl;
		instanceFlag = false;
		delete logger;
	}


	Logger* Logger::getInstance(){
		if (!instanceFlag){
			logger = new Logger();
			instanceFlag = true;
			return logger;
		}
		else{
			logger->logs(MyLogger::logERROR) << "There is already an instance of this class!" << std::endl << std::endl;
			return logger;
		}
	}
	
	std::string Logger::getData(ErrorLevels level){
		std::string str = "- " + getTime() + " " + getThreadID() + " " + getErrorLevel(level);
		return str;
	}

	std::string Logger::getTime(){
		SYSTEMTIME t;	
		GetLocalTime(&t);
		std::ostringstream buffer;

		buffer << t.wMonth << "/" << t.wDay << "/" << t.wYear << " " <<
			   t.wHour << ":" << t.wMinute << ":" << t.wSecond << ":" << t.wMilliseconds;

		return buffer.str();
	}

	std::string Logger::getErrorLevel(ErrorLevels level){
		std::ostringstream buffer;

		switch (level){
		case 1: buffer << "ERROR: ";
			break;
		case 2: buffer << "WARNING: ";
			break;
		case 3: buffer << "INFO: ";
			break;
		case 4: buffer << "DEBUG: ";
			break;
		case 5: buffer << "TRACE: ";
			break;
		default:
			buffer << "Invalid option! ";
		}

		return buffer.str();
	}

	std::string Logger::getThreadID(){
		std::ostringstream buffer;
		std::thread::id this_id = std::this_thread::get_id();
		buffer << this_id;
		return buffer.str();
	}


	Streaming Logger::logs(ErrorLevels level){
		Streaming h(file, std::cout);
		h << getData(level);
		return h;
	}
}



