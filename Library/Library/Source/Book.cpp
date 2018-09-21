#pragma once
#include "Book.h"

Book::Book(std::string _title, const Author &_author, std::string _language) : bookTitle(_title),
																		 bookAuthor(_author),
																		 bookLanguage(_language){
}

Book::Book(){

}

Book::~Book(){
	std::cout << "The book " << GetTitle() << ", " << GetAuthor().GetName() << ", in " << GetLanguage() << " is not available anymore." << std::endl;
};


std::string Book::GetTitle() const{
	return this->bookTitle;
} 

const Author &Book::GetAuthor() const {
	return this->bookAuthor;
}

void Book::Print(){
	std::cout << GetTitle() << ", " << bookAuthor.GetName() << ", in " << GetLanguage();
}

std::string Book::GetLanguage() const{
	return this->bookLanguage;
}