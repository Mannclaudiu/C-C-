#pragma once
#include "Book.h"

class Exemplars{
private:
	/**
		Purpose: variable used to create an object of type Book
	*/
	Book *book;
public:

	/**
		Purpose: Constructor who takes as parameter a reference to an object of type Book
	*/
	Exemplars(Book &_oeuvre);

	/**
		Purpose: Copy constructor
	*/
	Exemplars(const Exemplars &_copy);

	/**
		Purpose: Default constructor
	*/
	Exemplars();

	/**
		Puspose: Destructor
	*/
	~Exemplars();

	/**
		Purpose: Method used to return a constant reference to book;
	*/
	const Book &GetBook() const;

	/**
		Purpose: Method used to print the details of the exemplars
	*/
	void Print();
};