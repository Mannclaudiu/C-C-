#include "Card.h"

Card::Card(){
}

// the constructor
Card::Card(const std::string& _suit, const std::string& _rank) : suit(_suit), rank(_rank){
}

// return suit
std::string Card::getSuit() const{
	return this->suit;
}

// return rank
std::string Card::getRank() const{
	return this->rank;
}

// the overloading ostream operator in order to print the cards
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress *
std::ostream& operator<<(std::ostream& out, const Card& c){
	// each column will be alligned at left and will have a defined width
	out << std::left << std::setw(15) << c.suit
		<< std::left << std::setw(10) << c.rank;
	return out;
}