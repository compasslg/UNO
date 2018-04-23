#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
#define SHUFFLE 1
#define LOAD 2
void game_loop(card *deck, card *players[NumOfPlayers]);
//== The main function ===========================================================
int main(void) {
	SetConsoleOutputCP(65001);
	card *deck = NULL;
	card *players[NumOfPlayers];
	int gameAction = 0;
	int gameState = 0;
	printf("Let's play a game of UNO\n");
	printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
	scanf("%d", &gameAction);
	switch (gameAction)
	{
	case 1: // shuffle
		deck = create_deck();
		//shuffle(&deck);
		break;
	case 2: // load from file
		load_deck(deck);
		break;
	}
	// Initialize players
	for (int i = 0; i < NumOfPlayers; i++) {
		players[i] = NULL;
		draw_cards(&deck, &players[i], 7);
	}

	// Game loop
	game_loop(deck, players);
	return 0;
}
void game_loop(card *deck, card *players[NumOfPlayers]) {
	int step = 1;
	int turn = 0;
	int playerAction = 0;
	while (1) {
		printf("Player %d: ", turn + 1);
		print_cards(players[turn]);
		printf("Press 1-%d to play any card from your hand, or press 0 to draw a card from the deck: ", num_of_cards(players[turn]));
		scanf("%d", &playerAction);
		turn += step;
		if (turn >= NumOfPlayers) {
			turn = 0;
		}
		else if (turn < 0) {
			turn = NumOfPlayers - 1;
		}
	}

}

