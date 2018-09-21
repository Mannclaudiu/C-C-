#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "Exemplars.h"

/*******************************************
* Write your implementation starting here.
* Read documentation for further details.
*******************************************/

class Library{
private:

	/**
		Purpose: Stores the name of the library
	*/
	std::string name;

	/**
		Purpose: A vector who stores a set of pointers to Exemplars
	*/
	std::vector<Exemplars*> myVector;

	/**
		Purpose: Create an iterator
	*/
	std::vector<Exemplars*>::iterator iter;
public:

	/**
		Purpose: Constructor who takes as parameter the name of the library
	*/
	Library(std::string name);

	/**
		Purpose: Default constructor
	*/
	Library();

	/**
		Purpose: Destructor
	*/
	~Library();

	/**
		Purpose: A method who stores the books taken as parameter, and number of copies
	*/
	void Store(Book &book, int n);

	/**
		Purpose: A method who display all copies of a book written in a given language.
		         If no language is given (empty string), all copies of the library will be displayed
	*/	
	void PrintBooks(std::string _language);

	/**
		Purpose: Return the number of copies of a given book passed as parameter
	*/
	int CountExemplars(Book &copies);

	/**
		Purpose: If boolean is true, displays only the name of awarded authors. If boolean is false
		         this method should display the authors who have a copy of their book in library
				 (but this feature is not implemented yet)
	*/
	void ShowAuthors(bool condition);

	/**
		Purpose: Returns the name of the library.
	*/
	std::string GetName();
};

