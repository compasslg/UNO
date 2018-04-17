#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
//== The main function ===========================================================
int main(void) {
	card *cards;
	card c1, c2, c3, c4;
	c1.value = 1;
	c2.value = 2;
	c3.value = 3;
	insert_card(cards, &c1, 0);
	insert_card(cards, &c2, 1);
	insert_card(cards, &c4, 2);
	insert_card(cards, &c3, 2);
	/*
	card players[NumOfPlayers];
	int gameAction = 0;
	card *deck = create_deck();
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
	*/
	return 0;
}
