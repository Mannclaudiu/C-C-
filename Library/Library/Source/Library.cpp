#pragma once
#include "Library.h"

using namespace std;

/*******************************************
* Write your implementation starting here.
* Read documentation for further details.
*******************************************/
Library::Library(std::string _name){
	name = _name;
	std::cout << "The library " << _name << " is open! " << std::endl;
}

Library::Library(){

}

Library::~Library(){
	std::cout << "The library " << GetName() << " closes its gates, and remove its books." << std::endl;

	for (iter = myVector.begin(); iter != myVector.end(); iter++)
		delete *iter;	
	myVector.clear();
}

std::string Library::GetName(){
	return name;
}

void Library::Store(Book &book, int n = 1){
	for (int i = 0; i < n; i++){
		myVector.push_back(new Exemplars(book));
	}
}

void Library::PrintBooks(std::string _language = ""){
	for (iter = myVector.begin(); iter != myVector.end(); iter++){
		if ((*iter)->GetBook().GetLanguage() == _language){
			(*iter)->Print();
		}
		else if (_language == "")
			(*iter)->Print();
	}	
}

int Library::CountExemplars(Book &copies){
	int copy = 0;
	for (iter = myVector.begin(); iter != myVector.end(); iter++){
		if ((*iter)->GetBook().GetTitle() == copies.GetTitle()){
			copy++;
		}
	}
	return copy;
}

void Library::ShowAuthors(bool condition = false){
	if (condition){
		for (iter = myVector.begin(); iter != myVector.end(); iter++){
			if ((*iter)->GetBook().GetAuthor().GetAward()){
				std::cout << (*iter)->GetBook().GetAuthor().GetName() << std::endl;
			}
		}
	}
}


/*******************************************
* Do not modify anything after this line.
*******************************************/

int main()
{
	Author author01("Victor Hugo");							// Author class have to be implemented
	Author author02("Alexandre Dumas");
	Author author03("Raymond Queneau", true);

	Book book01("Les Misérables", author01, "français"),	// Book class have to be implemented
		book02("L'Homme qui rit", author01, "français"),
		book03("Le Comte de Monte-Cristo", author02, "français"),
		book04("Zazie dans le métro", author03, "français"),
		book05("The Count of Monte-Cristo", author02, "english");

	Library biblio("Public Library");						// Library class have to be implemented
	biblio.Store(book01, 2);
	biblio.Store(book02);
	biblio.Store(book03, 3);
	biblio.Store(book04);
	biblio.Store(book05);

	std::cout << std::endl << std::endl;
	cout << "The library " << biblio.GetName()
	<< " have the following books in collection:" << endl;
	biblio.PrintBooks();

	std::cout << std::endl << std::endl;
	const string language("english");
	cout << " The books in " << language << " are:" << endl;
	biblio.PrintBooks(language);

	cout << " The most prolific authors are:" << endl;
	biblio.ShowAuthors(true);

	cout << " There are " << biblio.CountExemplars(book03) << " books of "
		<< book03.GetTitle() << endl;

	std::cout << std::endl << std::endl;

	return 0;

}
