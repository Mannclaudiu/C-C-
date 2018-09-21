#pragma once
#include <string>
#include "Author.h"
#include <iostream>

class Book{
private:

	/**
		Purpose: Variable used in order to store book's title
	*/
	std::string bookTitle;

	/**
		Purpose: Variable used to create an object of type Author
	*/
	Author bookAuthor;

	/**
		Purpose: Variable used to store book's language
	*/
	std::string bookLanguage;

public:

	/**
		Purpose: Book's constructor who takes three parameters:
		         book's title, a constant reference to the author, and book's language
	*/
	Book(std::string _title, const Author &_author, std::string _language);

	/**
		Purpose: Default constructor
	*/
	Book();

	/**
		Purpose: Destructor
	*/
	~Book();

	/**
		Purpose: Method used to get title of the book
	*/
	std::string GetTitle() const;

	/**
		Purpose: Method used to return a constant reference to the author.
				 The 'const' keyword before function, means that the function will return
				 a constant reference to the author. The second 'const' keyword means that
				 the function is constant. 
				 There are many functions declared constant because I needed to call them using 
				 a constant reference. Is not possible to have a const reference who calls a
				 non-const function.
	*/
	const Author &GetAuthor() const;

	/**
		Purpose: Method used to return language of the book
	*/
    std::string GetLanguage() const;

	/**
		Purpose: Method used to print the details of the book
	*/
	void Print();
};