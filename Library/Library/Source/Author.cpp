#pragma once
#include "Author.h"
#include <iostream>

Author::Author(std::string _authorName, bool _awarded){
	authorName = _authorName;
	awarded = _awarded;
}

Author::Author(){

}

Author::~Author(){
}

std::string Author::GetName() const{
	return this->authorName;
}

bool Author::GetAward() const{
	if (awarded)
		return true;
	else
		return false;
}