
#include "WarGame.h"

int main() {

	WarGame game = WarGame();

	game.startTheGame();

	return 0;

	/*
	The objective of this game is that from all amount of players, at the end of came the winner is the player
	who have all of the cards.
	Below are listed the steps of the game.

	1. There are 52 cards
	2. Shuffle the cards
	3. Split the cards to number of players and give each player the needed number of cards.
	4. Each player will receive cards by rotation, so the cards will be given one at a time until they are over.
	5. Each user will pick a card from top of the packet, and put it on the table
	6. The user whose card has higher value, takes both cards, and places them in his own packet, faced up.
	7. When the user reaches the cards that are faced up, shuffle them again and continue the game.
	8. If both players take cards that are equal in value, the war begins
		9. War: Both players take another card, and place it flipped down, on the 1st card.
		10. War: Both players take another card, and face it up. The player whose card value is higher,
		         takes all of the cards and put them in packet.
	11. If at war, the cards are of the same value again, then the war continues.
	12. The winer is the player who have all 52 cards in his packet. */
}