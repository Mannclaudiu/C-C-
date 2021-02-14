#pragma once
// cppcheck-suppress missingIncludeSystem
#include <iomanip>

// This class defines each card type in deck
class Card {
private:
	// the name of the card
	std::string suit;

	// the rank of the card
	std::string rank;
public:

	// the constructor 
	Card();

	// the constructor with parameters
	Card(const std::string&, const std::string&); 

	// return suit
	std::string getSuit() const;

	// return rank
	std::string getRank() const;

	// the overloading ostream operator in order to print the cards
	friend std::ostream& operator << (std::ostream&, const Card&);
};