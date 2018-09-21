#pragma once
#include<iostream>
#include<sstream>
#include "windows.h"
#include <fstream>
#include <thread>

#ifdef LIBRARY_EXPORT
#define LOGGER_API __declspec(dllexport)
#else
#define LOGGER_API __declspec(dllimport)
#endif

/**
	Purpose: MyLogger is a namespace used to organize code into logical groups 
	and to prevent name collisions that can occur
*/
namespace MyLogger{

	/**
		Purpose: ErrorLevels ia a enum type, used to store the logging levels
	*/
	enum ErrorLevels{logERROR = 1, logWARNING, logINFO, logDEBUG, logTRACE};

	/**
		Purpose: Streaming is a structure, which I use in order to send the same data
		to console and at the same time, write it to specified log file.
	*/
	struct LOGGER_API Streaming{
		Streaming(std::ostream& _file, std::ostream& _ostream) : file(_file), ostream(_ostream) {}
		std::ostream& file;
		std::ostream& ostream;
	};

	/**
		Purpose: Overloading operator << in order to accept as right-hand operand, 
		native type of data: int, string, double etc. Notice that because we used 'typename',
		it is configured for native types as int, string, double etc, and purpose was not 
		defined for class objects.
		This function is used to handle right-hand data type.
	*/
	template <typename T> Streaming& operator<<(Streaming& h, T const& t){
		h.file << t;
		h.ostream << t;
		return h;
	}

	/**
		Purpose: This is a special function used to handle the application of 'std::endl'.
		'std::ostream&(*f)(std::ostream&)' is the type of a function accepting and returning a 'Streaming'
		object by reference.
	*/
	Streaming& operator<<(Streaming& h, std::ostream&(*f)(std::ostream&)){
		h.file << f;
		h.ostream << f;
		return h;
	}

	/**
		Purpose: Logger class is where the magic of logging happens
	*/
	class LOGGER_API Logger{
	private:

		/**
			Purpose: A bllo variable used to find out if there are one or multiple 
			instances of same class.
		*/
		static bool instanceFlag;

		/**
			Purpose: A pointer used to instantiate a class object.
		*/
		static Logger *logger;

		/**
			Purpose: Constructor of the class 'Logger'. Because is a singleton class,
			it requires a privare constructor.
		*/
		Logger();

		/**
			Purpose: A variable of type 'fstream' used to log messages into a file.
		*/
		std::fstream file;

	public:

		/**
			Purpose: getInstance() is a function used to create a instance of the class.
			If there is no instance, then a new instance is created, the variable 'instanceFlag'
			is set to true, and we return the created object. If there already exists a instance,
			(instanceFlag = true), then we log an error message.
		*/
		static Logger* getInstance();

		/**
			Purpose: The destructor for Logger class
		*/
		~Logger();

		/**
			Purpose: Returns a string which contains the message returned by 
			'getTime()', 'getThreadID()', 'getErrorLevel(ErrorLevels)'
		*/
		std::string getData(ErrorLevels);

		/**
			Purpose: A function used to get the date and time in format
			MM/DD/YYYY hr:min:sec:milisec
		*/
		std::string getTime();

		/**
			Purpose: A function used to return the thread ID
		*/
		std::string getThreadID();

		/**
			Puspose: A function used to get the error levels stored in enum.
		*/
		std::string getErrorLevel(ErrorLevels);

		/**
			Purpose: Main function used to log on the console and in file all the details
		*/
		Streaming logs(ErrorLevels);
	};
}