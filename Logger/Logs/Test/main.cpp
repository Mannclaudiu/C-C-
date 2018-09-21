#include <iostream>
#include "Logger.h"


/* Pass-by-value into function (TestPassByValue.cpp) */
int squareValue(int, MyLogger::Logger *);
/* Pass-by-reference using pointer (TestPassByPointer.cpp) */
void squarePointer(int *, MyLogger::Logger *);
/* Pass-by-reference using reference (TestPassByReference.cpp) */
void squareReference(int &, MyLogger::Logger *);

int main() {

	MyLogger::Logger *logger;
	MyLogger::Logger *anotherLogger;
	logger = MyLogger::Logger::getInstance();
	anotherLogger = MyLogger::Logger::getInstance();

	logger->logs(MyLogger::logINFO) << "Pass by value " << std::endl;
	int numberValue = 8;
	logger->logs(MyLogger::logDEBUG) << "Value: " << &numberValue << std::endl;			// 0x22ff1c
	logger->logs(MyLogger::logDEBUG) << numberValue << std::endl;						// 8
	logger->logs(MyLogger::logDEBUG) << squareValue(numberValue, logger) << std::endl;	// 64
	numberValue = squareValue(numberValue,logger);
	logger->logs(MyLogger::logDEBUG) << numberValue << std::endl;			// 8 - no change
	logger->logs(MyLogger::logINFO) << "Pass by value has been done " << std::endl << std::endl;

	logger->logs(MyLogger::logINFO) << "Pass-by-reference using pointer " << std::endl;
	int numberPointer = 8;
	logger->logs(MyLogger::logDEBUG) << "Pointer: " << &numberPointer << std::endl;		// 0x22ff1c
	logger->logs(MyLogger::logDEBUG) << numberPointer << std::endl;					    // 8
	squarePointer(&numberPointer, logger);											    // Explicit referencing to pass an address
	logger->logs(MyLogger::logDEBUG) << numberPointer << std::endl;		// 64
	logger->logs(MyLogger::logINFO) << "Pass-by-reference using pointer has been done" << std::endl << std::endl;

	logger->logs(MyLogger::logINFO) << "Pass-by-reference using reference " << std::endl;
	int numberReference = 8;
	logger->logs(MyLogger::logDEBUG) << "Reference: " << &numberReference << std::endl;	 // 0x22ff1c
	logger->logs(MyLogger::logDEBUG) << numberReference << std::endl;					 // 8
	squareReference(numberReference, logger);											 // Implicit referencing (without '&')
	logger->logs(MyLogger::logDEBUG) << numberReference << std::endl;		 // 64
	logger->logs(MyLogger::logINFO) << "Pass-by-reference using reference has been done " << std::endl << std::endl;
	return 0;
}

int squareValue(int n, MyLogger::Logger *logger) {							  // non-const
	logger->logs(MyLogger::logDEBUG) << "In square() value: " << &n << std::endl;	 // 0x22ff00
	n *= n;										    // clone modified inside the function
	logger->logs(MyLogger::logWARNING) << "The function will exit returning the value " << n << std::endl;
	return n;
}

void squarePointer(int * pNumber, MyLogger::Logger *logger) {						  // Function takes an int pointer (non-const)
	logger->logs(MyLogger::logDEBUG) << "In square() pointer: " << pNumber << std::endl;  // 0x22ff1c
	*pNumber *= *pNumber;								// Explicit de-referencing to get the value pointed-to
	logger->logs(MyLogger::logWARNING) << "The function will exit returning the value " << *pNumber << std::endl;
}

void squareReference(int & rNumber, MyLogger::Logger *logger) {							// Function takes an int reference (non-const)
	logger->logs(MyLogger::logDEBUG) << "In square() reference: " << &rNumber << std::endl;	   // 0x22ff1c
	rNumber *= rNumber;										  // Implicit de-referencing (without '*')
	logger->logs(MyLogger::logWARNING) << "The function will exit returning the value " << rNumber << std::endl;
}
