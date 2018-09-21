#pragma once
#include "Exemplars.h"

Exemplars::Exemplars(Book &_oeuvre){
	this->book = &_oeuvre;
	std::cout << "New exemplar of: " << book->GetTitle() << ", " << book->GetAuthor().GetName()
		<< ", in " << book->GetLanguage() << std::endl;
}

Exemplars::Exemplars(const Exemplars &_copy) : book(_copy.book){
	std::cout << "Copy of one exemplar of: " << book->GetTitle() << ", " << book->GetAuthor().GetName()
		<< ", in " << book->GetLanguage() << std::endl;
}

Exemplars::Exemplars(){
}

Exemplars::~Exemplars(){
	std::cout << "One exemplar of: " << book->GetTitle() << ", " << book->GetAuthor().GetName()
		<< ", in " << book->GetLanguage() << " was removed!" << std::endl;
}

const Book &Exemplars::GetBook() const{
	return *book;
}

void Exemplars::Print(){
	std::cout << "Exemplar of " << book->GetTitle() << ", " << book->GetAuthor().GetName() << ", in " << book->GetLanguage() << std::endl;
}