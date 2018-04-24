#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
#define SHUFFLE 1
#define LOAD 2
void game_loop(card *deck, card *discardPile, card *players[NumOfPlayers]);
int next_turn(int turn, int step);
int check_UNO(card *players[NumOfPlayers]);
void pick_color_wild(card *c);
//== The main function ===========================================================
int main(void) {
	SetConsoleOutputCP(65001);
	card *deck = NULL;
	card *discardPile = NULL;
	card *players[NumOfPlayers];
	int gameAction = 0;
	int gameState = 0;
	char playAgain = NULL;
	printf("Let's play a game of UNO\n");
	printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
	scanf("%d", &gameAction);
	switch (gameAction)
	{
	case 1: // shuffle
		deck = create_deck();
		shuffle(&deck);
		break;
	case 2: // load from file
		load_deck(deck);
		break;
	}
	// Initialize players
	for (int i = 0; i < NumOfPlayers; i++) {
		players[i] = NULL;
		draw_cards(&deck, &discardPile, &players[i], 7);
	}

	// Game loop
	while (1) {
		game_loop(deck, discardPile, players);
		printf("Do you want to play again? (y/n)");
		scanf(" %c", &playAgain);
		if (playAgain == 'y') {
			
		}
		else {
			break;
		}
	}

	printf("Bye~\n");
	return 0;
}
// This function get the next turn based on previous turn and step
// Take two ints and return an int
int next_turn(int turn, int step) {
	turn += step;
	// Make sure not out of range
	if (turn >= NumOfPlayers) {
		turn = 0;
	}
	else if (turn < 0) {
		turn = NumOfPlayers - 1;
	}
	return turn;
}
// Check if any player has UNO
// print messages that shows who have UNO
int check_UNO(card *players[NumOfPlayers]) {
	for (int i = 0; i < NumOfPlayers; i++) {
		if (num_of_cards(players[i]) == 1) {
			printf("Player %d has UNO!\n\n", i+1);
		}
	}
}
// This function prompt player to pick the color for a wild card
// Take a pointer to a card
void pick_color_wild(card *c) {
	int suit = 0;
	printf("\nPick a Suit (0 for %s, 1 for %s, 2 for %s, 3 for %s): ", RED, YELLOW, GREEN, BLUE);
	scanf("%d", &suit);
	printf("\n");
	switch (suit)
	{
	case 0:
		strcpy(c->suit, RED);
		break;
	case 1:
		strcpy(c->suit, YELLOW);
		break;
	case 2:
		strcpy(c->suit, GREEN);
		break;
	case 3:
		strcpy(c->suit, BLUE);
	default:
		break;
	}
}

// This function is the main loop of a game
// Tale two pointers to lists of cards, and an array of list of cards
void game_loop(card *deck, card *discardPile, card *players[NumOfPlayers]) {
	int step = 1;
	int turn = 0;
	int playerAction = 0;
	int numOfCards = 0;
	card *c = remove_card(&deck, 0);
	insert_card(&discardPile, c, 0);
	printf("\nDiscard Pile: ");
	print_cards(discardPile);
	printf("\n");
	while (1) {
		printf("Player %d: ", turn + 1);
		print_cards(players[turn]);
		numOfCards = num_of_cards(players[turn]);
		while (1) {
			printf("Press 1-%d to play any card from your hand, or press 0 to draw a card from the deck: ", num_of_cards(players[turn]));
			scanf("%d", &playerAction);
			// Check special cases of action
			if (playerAction == 0) { // draw 1 card
				draw_cards(&deck, &discardPile, &players[turn], 1);
				printf("\n");
				break;
			}
			else if (playerAction > numOfCards || playerAction < 0) { // Invalid action
				printf("Invalid card index!\n\n");
				continue;
			}
			c = remove_card(&players[turn], playerAction-1);
			// Check if the card played is valid
			if (num_of_cards(discardPile) == 0 ||			// No card in discard
				c->value == WILD ||							// Wild card
				strcmp(c->suit, discardPile->suit) == 0 ||	// Same suit
				c->value == discardPile->value) {			// Same Number
				insert_card(&discardPile, c, 0);
				printf("\nDiscard Pile: ");
				print_cards(discardPile);
				printf("\n");
			}
			else {
				printf("The ");
				print_a_card(c);
				printf(" can't be placed on top of ");
				print_a_card(discardPile);
				printf("\n\n");
				insert_card(&players[turn], c, playerAction-1);
				continue;
			}
			// check if game is over
			if (num_of_cards(players[turn]) == 0) {
				printf("player %d Wins!\n\n", turn+1);
				return;
			}
			switch (c->value)
			{
			case SKIP:
				turn = next_turn(turn, step);
				break;
			case REVERSE:
				if (NumOfPlayers > 2) { // reverse when there's more than 2 players
					if (step == 1) {
						step = -1;
					}
					else {
						step = 1;
					}
				}
				else { // works the same as skip if there is only 2 players
					turn = next_turn(turn, step);
				}
				break;
			case DRAW_TWO:
				turn = next_turn(turn, step);
				draw_cards(&deck, &discardPile, &players[turn], 2);
				break;
			case WILD:
				pick_color_wild(c);
				if (strcmp(c->action, "wild draw four") == 0) {
					turn = next_turn(turn, step);
					draw_cards(&deck, &discardPile, &players[turn], 4);
				}
				break;
			}
			break;
		}
		turn = next_turn(turn, step);
		check_UNO(players);
	}

}


