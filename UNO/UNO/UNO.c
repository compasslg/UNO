#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
//== The main function ===========================================================

int main(void) {
	//SetConsoleOutputCP(65001);
	//printf("\xe2\x99\xa5\n");
	card players[NumOfPlayers];
	int gameAction = 0;
	//card *deck = load_deck(NULL);
	card *deck = create_deck();
	printf("Before Shuffle: \n");
	print_deck(deck);
	printf("\nAfterShuffle: \n");
	shuffle(&deck);
	print_deck(deck);

	return 0;
	/*
	printf("Let's play a game of UNO\n");
	printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
	scanf("%d", &gameAction);
	switch (gameAction)
	{
	case 1: // shuffle
		shuffle(deck);
		break;
	case 2: // load from file
		load_deck(deck);
		break;
	}
	print_deck(deck);
	return 0;
	*/
}

