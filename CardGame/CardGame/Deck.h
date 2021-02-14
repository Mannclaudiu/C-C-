#pragma once
// cppcheck-suppress missingIncludeSystem
#include <array>

// cppcheck-suppress missingIncludeSystem
#include <iostream>

// cppcheck-suppress missingIncludeSystem
#include <chrono>

// cppcheck-suppress missingIncludeSystem
#include <random>

// cppcheck-suppress missingIncludeSystem
#include <algorithm>

// cppcheck-suppress missingIncludeSystem
#include <list>
#include "Card.h"

// This class defines the deck of cards
class Deck {
private:
	// list of type Card who keeps the cards in deck
	std::list<Card> deck;

public:
	// the Deck constructor
	Deck();

	// add cards on top of the deck
	void addCardsToTop(const Card&);

	// gets a card from top of the deck
	Card getCardFromTop() const;

	// remove cards from top of the deck
	void removeCardFromTop();

	// add cards to bottom of the deck
	void addCardsToBottom(const Card&);

	// gets a card from bottom of the deck
	Card getCardFromBottom() const;

	// remove cards from cards of the bottom
	void removeCardsFromBottom();

	// the function used to shuffle a deck
	void shuffleDeck();

	// the function used to print a deck
	void printDeck();

    // get number of cards in deck
	size_t getDeckSize() const;
};