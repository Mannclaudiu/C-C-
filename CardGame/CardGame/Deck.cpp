#include "Deck.h"

Deck::Deck(){
}

// add cards on top of the deck
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress *
void Deck::addCardsToTop(const Card& card){
	deck.push_front(card);
}

// get a card from top of the deck
Card Deck::getCardFromTop() const{
	return deck.front();
}

// remove cards from top of the deck
void Deck::removeCardFromTop(){
	deck.pop_front();
}

// add cards to bottom of the deck
void Deck::addCardsToBottom(const Card& card){
	deck.push_back(card);
}

// get card from bottom
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress *
Card Deck::getCardFromBottom() const{
	return deck.back();
}

// remove cards from cards of the bottom
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress *
void Deck::removeCardsFromBottom(){
	deck.pop_back();
}



// the function used to shuffle the deck
void Deck::shuffleDeck(){
	// define a temp vector and store the elements of deck in it
	std::vector<Card> tempVector = { deck.begin(), deck.end() };

	// clear the deck
	deck.clear();

	// shuffle the elements of vector
	std::shuffle(tempVector.begin(), tempVector.end(), std::mt19937{ std::random_device{}() });
	
	// copy the elements of vector in list
	deck = { tempVector.begin(), tempVector.end() };

	// clear the temp vector
	tempVector.clear();
}

// the function used to print the deck
void Deck::printDeck() {
	// the iterator for card type items
	std::list<Card>::iterator it;
	int card_id = 0;

	// loop through cards in deck
	for (it = deck.begin(); it != deck.end(); ++it) {

		// increment this variable in order to print each card of packet
		card_id++; 

		// print the card
		std::cout << card_id << ".\t" << *it << "\n";
	}
}

// get deck size
size_t Deck::getDeckSize() const {
	return deck.size();
}