#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
//== The main function ===========================================================
int main(void) {
	SetConsoleOutputCP(65001);
	card *deck = NULL;
	card players[NumOfPlayers];
	int gameAction = 0;	
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
	print_deck(deck);
	return 0;
}

