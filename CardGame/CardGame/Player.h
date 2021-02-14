#pragma once
#include "Deck.h"

// This class defines the players that are playing the game
class Player {
private:
	// player's name
	std::string name;

	// player's deck of cards
	Deck deck;
	
public:
	// constructor
	Player();

	// constructor with parameters
	explicit Player(const std::string&);

	// add cards in deck
	void putCardsInDeck(const Card&);

	// get the deck size
	size_t getDeckSize() const;

	// get the player name
	std::string getName() const;

	// take a card from deck
	Card takeCardFromDeck();

	// display the deck
	void displayDeck();
};