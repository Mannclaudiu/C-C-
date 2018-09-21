#pragma once
#include <string>

class Author{
private:

	/**
		Purpose: Variable used in order to store auhtor's name
	*/
	std::string authorName;

	/**
		Purpose: Variable used in order to find out if the author was awarded (true) or not (false)
	*/
	bool awarded;
public:
	/**
		Purpose: The constructor taking as parameters author's name, and award, which is false by default
	*/
	Author(std::string _authorName, bool _awarded = false);

	/**
		Purpose: Defalut constructor
	*/
	Author();

	/**
		Purpose: Destructor
	*/
	~Author();

	/**
		Purpose: Method who returns the name of the author
	*/
	std::string GetName() const;

	/**
		Purpose: Method who returns award status of the author
	*/
	bool GetAward() const;
};