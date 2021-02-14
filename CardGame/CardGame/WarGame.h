#pragma once
#include "Player.h"



#define MIN_PLAYERS 2
#define MAX_PLAYERS 52
#define NO_OF_CARDS_TAKEN_AT_WAR 2

// This class defines the board where the players play the game of cards
class WarGame {
private:

	// players will be added in a list
	std::vector<Player> players;

	// vector who keeps the cards that are on the board
	std::vector<Card> cards;

	// vector who keeps the index of cards who have maximum value, amoung cards put on the board
	std::vector<int> maxCardValueIndex;

	// keeps a flag to indicate that at war, if some players remain without cards to put on board 
	// (here we talk about those 2 cards that players put on board at war), then only the player who had 
	// cards to put on board, or last player that have to put cards on board even if his deck is empty too, will win
	bool playerWon;

	// flag used to keep the index of card for the player who wins, related to playerWon comments
	size_t indexAt;

	// flag used to signal the war
	bool war;

public:

	// constructor
	WarGame();

	// the function used to create a deck
	void createDeck(Deck& deck);

	// function that takes the name of players at table, and adds them to a list
	void playersAtBoard(const int& numberOfPlayers);

	// function used to take out a player from game. This happens when he lost all of the cards
	void removePlayer(const int&);

	// function used to check the player's deck in order to see if it still contains cards
	void checkPlayerDeck();

	// display the cards of every player
	void displayPlayerCards();

	// function used to give each player an equal amount of cards
	void dealTheCards(Deck&);

	// put the cards from player's deck, on board
	void putCardOnBoard();

	// display the cards that players put on table
	void displayOnBoardCards();

	// function used to get the card value based on rank
	int getCardRank(const std::string&) const;

	// choose the winner who possibly to take all the cards from board, into it's deck
	Player winner();

	// function used to find all the maximum value cards on board
	std::vector<int> findMaximumCardsValue();

	// take all the cards from board into winner's deck
	void winnerTakeAllCards(const Player&);

	// starts the game
	void play(const Deck&);

	// the function that starts the game
	void startTheGame();
};