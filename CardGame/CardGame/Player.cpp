#include "Player.h"

// constructor
Player::Player(){
}

// constructor with parameters
Player::Player(const std::string& _name) : name(_name){
}

// add cards in deck
void Player::putCardsInDeck(const Card& card){
	deck.addCardsToBottom(card);
}

// get the deck size
size_t Player::getDeckSize() const {
	return deck.getDeckSize();
}

// get the player name
std::string Player::getName() const {
	return this->name;
}

// take a card from deck
Card Player::takeCardFromDeck(){  

	// get first card from deck
	Card card = deck.getCardFromTop();

	// remove the taken card from deck
	deck.removeCardFromTop();

	// return the card
	return card;
}

// display the deck
void Player::displayDeck(){
	std::cout << "\n" << this->getName() << std::endl;
	deck.printDeck();
}
