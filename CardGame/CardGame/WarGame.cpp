#include "WarGame.h"

// constructor with parameters
WarGame::WarGame() {
	this->war = 0;
	this->playerWon = 0;
	this->indexAt = 0;
}

// the function used to create the deck
void WarGame::createDeck(Deck& deck) {
	// array of string type, and size 4, used to store the suits
	std::array<std::string, 4> suits = { "Clubs", "Diamonds", "Hearts", "Spades" };

	// array of string type and size 13 used to store the ranks
	std::array<std::string, 13> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

	// the iterator for suits array type
	std::array<std::string, 4>   ::iterator it_suits;

	// the iterator for ranks array type
	std::array<std::string, 13> ::iterator it_ranks;

	// loop through suits
	for (it_suits = suits.begin(); it_suits != suits.end(); ++it_suits) {
		// loop through ranks
		for (it_ranks = ranks.begin(); it_ranks != ranks.end(); ++it_ranks) {

			// push in list, the Card object type who will have the suits, ranks, and value for every card
			deck.addCardsToBottom(Card((*it_suits), (*it_ranks)));
		}
	}
}

// function that takes the name of players at table, and adds them to a list
void WarGame::playersAtBoard(const int& numberOfPlayers) {
	// declare a vriable that keeps the player name
	std::string playerName;
	std::cout << "\nPlease enter the name for each player " << std::endl;

	// iterate for number of players
	for (int i = 1; i <= numberOfPlayers; i++) {
		std::cout << "Player" << i << ":";

		// read the player name
		std::cin >> playerName;

		// check if player's name already exists
		for (unsigned j = 0; j < players.size(); j++) {

			// if name already exists in vector, then ask user to enter the name again,
			while (players.at(j).getName() == playerName) {
				std::cout << "The player name already exists ! " << std::endl;
				std::cout << "Player" << i << ":";

				// read the player name
				std::cin >> playerName;

				// reset the iterator to 0, because we want to check again from the begining
				j = 0;
			}
		}
		// add the player in list
		players.push_back(Player(playerName));
	}
}

// remove player at index
void WarGame::removePlayer(const int& index) {
	players.erase(players.begin() + index);
}

// check if player still have cards in his deck
void WarGame::checkPlayerDeck() {
	for (unsigned i = 0; i < players.size(); i++) {
		if (players.at(i).getDeckSize() == 0) { // if player has no more cards left, he loses the game
			std::cout << "\n" << players.at(i).getName() << " has no more cards left, so it will leave the game.\n" << std::endl;
			removePlayer(i);
			i--;
		}
	}
}

// display each player's deck
void WarGame::displayPlayerCards() {
	// iterate through player list and display the players long with the crds they keep
	for (unsigned j = 0; j < players.size(); j++) {
		players.at(j).displayDeck();
	}
}

// function used to give each player an equal amount of cards
void WarGame::dealTheCards(Deck& deck) {
	// get number of cards in deck
	size_t numberOfCards = deck.getDeckSize();

	// loop through cards in deck. The deck will increment with a step of number of players
	for (size_t i = 0; i < numberOfCards; i += players.size()) {
		// if there are not enough cards to give to each player the same amount, put the cards away from game
		if ((size_t)i + players.size() > numberOfCards) {
			break;
		}
		else {
			// give each player a card
			for (unsigned j = 0; j < players.size(); j++) {
				players.at(j).putCardsInDeck(deck.getCardFromTop());
				deck.removeCardFromTop();
			}
		}
	}
}

// put the cards from player's deck, on board
void WarGame::putCardOnBoard() {

	// keep a counter who decrements each time when a player has to put cards down on board,
	// but don't have any card in deck. When counter reach 1, it means what the player who has
	// cards to put on board, or the player who don't have cards to put on board but is the last player,
	// wins the game
	size_t counter = maxCardValueIndex.size();

	// this variable holds the index of player who wins the battle. It takes as value, the last index of cards,
	// and it may be changed inside of if condition
	size_t haveCards = maxCardValueIndex.size()-1;

	// if there is war, each player will get 2 cards from his deck, and put them on the board
	if (war == 1) {
		for (int i = 0; i < 2; i++) {
			// loop for cards index
			for (unsigned j = 0; j < maxCardValueIndex.size(); j++) {
				// if player at index of card, has cards in deck, put the cards on the board,
				// and set the variable to the index
				if (players.at(maxCardValueIndex.at(j)).getDeckSize() != 0) {
					cards.push_back(players.at(maxCardValueIndex.at(j)).takeCardFromDeck());
					haveCards = j;
				}
				else {
					// since we reached here, means that the playher has no more cards in deck, so we decrement
					// the counter.
					counter--;
					
					// if counter reaches 1, it means we have only one player left, that will be the winner
					if (counter == 1) {
						// set the flag that will return the player at indexAt
						playerWon = 1;

						// set the index which tells which player wins
						indexAt = haveCards;

						// return from function
						return;
					}
				}
			}
		}
	}
	else { // if there is no war, put card from user's deck, on board
		for (unsigned i = 0; i < players.size(); i++) {
			cards.push_back(players.at(i).takeCardFromDeck());
		}
	}
}

// display the cards that players put on table
void WarGame::displayOnBoardCards() {
	std::cout << "The players took the following cards: " << std::endl;

	// the variable who loops through cards vector
	unsigned i = 0;

	// the variable who loops through cardIndex vector
	int j = 0;

	// loop through cards vector
	while(i < cards.size()){
		// while i is lesser than number of players, display the cards that all players took
		if (i < players.size()) {
			std::cout << players.at(i).getName() << " has drawn " << cards.at(i).getRank() << " of " << cards.at(i).getSuit() << std::endl;
			i++;
		}

		// while i is greater than number of players, then display only the players that fight, by making a modulo operation
		// between j and size of cardIndex vector
		else {
			std::cout << players.at(maxCardValueIndex.at(j % maxCardValueIndex.size())).getName() << " has drawn "
					  << cards.at(i).getRank() << " of " << cards.at(i).getSuit() << std::endl;

			// increment the variables
			j++;
			i++;
		}
	}
}

// function used to convers ranks from string to int
int WarGame::getCardRank(const std::string& card) const {
	if (card == "2")
		return 2;
	if (card == "3")
		return 3;
	if (card == "4")
		return 4;
	if (card == "5")
		return 5;
	if (card == "6")
		return 6;
	if (card == "7")
		return 7;
	if (card == "8")
		return 8;
	if (card == "9")
		return 9;
	if (card == "10")
		return 10;
	if (card == "Jack")
		return 11;
	if (card == "Queen")
		return 12;
	if (card == "King")
		return 13;
	if (card == "Ace")
		return 14;

	return 0;
}

// choose the winner who will take all the cards from board, into it's deck
Player WarGame::winner() {

	// if flag is set, then the only player who remained with cards in the end wins
	if (playerWon) {
		playerWon = 0;
		this->war = 0;
		std::cout << "\n The player who will take all the cards is: "
			<< players.at(maxCardValueIndex.at(indexAt)).getName() << " " << std::endl << std::endl;
		return players.at(maxCardValueIndex.at(indexAt));
	}
	else {
		if (war == 0) {
			// find the maximum card(s) in cards that are on board
			maxCardValueIndex = findMaximumCardsValue();

			// if the vector is greather than 1, it means we have war.
			if (maxCardValueIndex.size() > 1) {
				this->war = 1;
			}
		}
		else if (war == 1) {

			// variable used to find the maximum value of card
			int maximum = 0;

			// variable used to keep the index at which maximum value card was found
			int index = 0;

			// define a vector who keeps last cards that players put on board, in case of war
			std::vector<Card> tempCard;

			// put the last cards that were put on board at war
			for (size_t i = cards.size() - maxCardValueIndex.size(); i < cards.size(); i++) {
				tempCard.push_back(cards.at(i));
			}

			// now find the maximum value amoung those cards
			for (unsigned i = 0; i < tempCard.size(); i++) {
				if (getCardRank(tempCard.at(i).getRank()) >= maximum) {
					if (getCardRank(tempCard.at(i).getRank()) > maximum) {
						maximum = getCardRank(tempCard.at(i).getRank());
						index = i;
						this->war = 0;
					}
					else {
						this->war = 1;
					}
				}
			}

			// once maximum was found, the user whose card had maximum value will get all of the cards from board
			if (war == 0) {
				std::cout << "\n" << players.at(maxCardValueIndex.at(index)).getName() << " will take all the cards from board" << std::endl;
			}
			return players.at(maxCardValueIndex.at(index));
		}

		// if there is only one maximum value amoung all cards on the board, then for sure the cardIndex wil contain only one value
		// so the player at that index will win
		if (war == 0) {
			std::cout << "\n" << players.at(maxCardValueIndex.at(0)).getName() << " will take all the cards from board" << std::endl;
		}
		return players.at(maxCardValueIndex.at(0));
	}
}

// function used to find all the maximum value cards on board
std::vector<int>  WarGame::findMaximumCardsValue(){
	// variable who keeps the maximum card rank found
	int tempMax = 0;

	// vector who keeps all the cards from board, who have maximum or equal to maximum rank
	std::vector<int> maxCardValue;

	// vector that stores the index where maximum value card was found
	std::vector<int> cardIdx;

	// store the minimum value in vector, in the beginning
	maxCardValue.push_back(tempMax);

	// loop through card size
	for (unsigned i = 0; i < cards.size(); i++) {
		// if rank is greather or equal than tempMax
		if (getCardRank(cards.at(i).getRank()) >= tempMax) {
			// if rank is greater
			if (getCardRank(cards.at(i).getRank()) > tempMax) {
				// tempMax gets new value of rank
				tempMax = getCardRank(cards.at(i).getRank());

				// check if last element added in maxCardValue vector is lesser than tempMax
				if (maxCardValue.back() < tempMax) {
					// check if vector size is greather than 0, because in this vector may be stored 
					// values lesser than maximum value in cards vector, so I have to get rid of them.
					// This may happen only unless maximum card rank is found
					if (maxCardValue.size() > 0) {
						// clear the vector
						maxCardValue.clear();
						// clear the vector that stores indexes
						cardIdx.clear();
					}
					// push in vector the maximum rank value
					maxCardValue.push_back(tempMax);

					// push in vector the index of maximum rank value
					cardIdx.push_back(i);
				}
			}
			else{ // if current card rank is equal with tempMax
				// push in vector the maximum rank value
				maxCardValue.push_back(tempMax);

				// push in vector the index of maximum rank value
				cardIdx.push_back(i);
			}
		}
	}

	// return the vector of indexes who store the position where maximum value cards are stored
	return cardIdx;
}


// take all the cards from board into winner's deck
void WarGame::winnerTakeAllCards(const Player& winnerPlayer) {

	// the winner player
	Player winner;

	// the winner will take all of the cards
	// loop through player's size
	for (unsigned i = 0; i < players.size(); i++) {
		// once the winner player is found in players vector
		if (players.at(i).getName() == winnerPlayer.getName()) {
			// loop through cards on the board
			for (unsigned j = 0; j < cards.size(); j++) {
				// put each card in player's deck
				players.at(i).putCardsInDeck((cards.at(j)));
				// select the winner
				winner = players.at(i);
			}
			break;
		}
	}
}

// function that starts the game
void WarGame::play(const Deck& deck){

	// the winner player
	Player winnerPlayer = Player();

	// a round counter that will count each round. A round consists of an iteration of while loop
	int roundCounter = 0;

	std::cout << "The players have the following cards in deck " << std::endl;
	displayPlayerCards();

	// iterate until there are only one player left at the board (the winner)
	while (players.size() > 1) {
		std::cout << "\n\n\n\n********************* ROUND " << roundCounter << " **********************" << std::endl;
		// call the function that fills the cards vector with cards that players put on board
		putCardOnBoard();

		// while there are more players than one, print the cards that they taken
		if (players.size() > 1) {
			// display the cards that players took
			displayOnBoardCards();
		}
		else { // when only one player left, just take all the cards from board and break the loop
			winnerTakeAllCards(winnerPlayer);
			break;
		}

		//std::cout << "\nPlayers will remain with following cards" << std::endl;
		//displayPlayerCards();
		// display the cards left in user's deck

		
		// choose the winner
		winnerPlayer = winner();

		if (this->war == 1) { // if there is war
			std::cout << "\n ******************************************************************************"
				<< "\n > > > > > > > > > > > > > > > > > >  WAR < < < < < < < < < < < < < < < < < < <"
				<< "\n ******************************************************************************" << std::endl;

			std::cout << "The war is between ";
			// get the names of the players that fight
			for (unsigned i = 0; i < maxCardValueIndex.size(); i++) {
				std::cout << players.at(maxCardValueIndex.at(i)).getName() << " " ;
			}
		}
		else { // if there is no war
			// the winner will take all of the cards
			winnerTakeAllCards(winnerPlayer);
			checkPlayerDeck();
			// empty the cards vector (there re no cards on the board)
			cards.clear();
		}

		// increment the round counter
		roundCounter++;

		//std::cout << "\nPlayers have the following cards in deck" << std::endl;
		//displayPlayerCards();

	}

	std::cout << "THE GAME WINNER IS :  " << winnerPlayer.getName() << std::endl;
	std::cout << "The winner have the following cards in deck " << std::endl;
	displayPlayerCards();
}

// the function that starts the game
void WarGame::startTheGame(){

	int numberOfPlayers;
	// read from keyboard the number of players, also the game must be player between 2 and 5 players
	std::cout << "Please enter the number of players that play the game (> " << MIN_PLAYERS << " && <= " << MAX_PLAYERS << "):";

	std::cin >> numberOfPlayers;

	// if the condition is false, then repeat until it is true
	while (numberOfPlayers < MIN_PLAYERS || numberOfPlayers > MAX_PLAYERS) {
		std::cout << "\nThere needs to be at least " << MIN_PLAYERS << " players and maximum " << MAX_PLAYERS << " players. Please try again !"
			<< "\nPlease enter the number of players: ";
		std::cin >> numberOfPlayers;
	}

	std::cout << "\nThe game will be played by " << numberOfPlayers << " players" << std::endl;




	// call the function that gives each player a name and then adds them in a list
	playersAtBoard(numberOfPlayers);

	// declare the Deck handle
	Deck deck = Deck();

	// call function that creates a deck
	createDeck(deck);

	std::cout << "\nThe deck" << std::endl;
	// call function that prints the deck
	deck.printDeck();

	// call function that shuffles the deck
	deck.shuffleDeck();

	std::cout << "\nThe shuffled deck" << std::endl;
	// print the shuffled deck
	deck.printDeck();

	// function used to give each player an equal amount of cards
	dealTheCards(deck);

	std::cout << std::endl;
	// call the function that displays all the players that will play the game, and their cards
	//game.displayPlayerCards();

	play(deck);
}
