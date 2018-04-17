#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
#define NumOfPlayers 2
//== The main function ===========================================================
int main(void) {
	card players[NumOfPlayers];
	int gameAction = 0;
	printf("Let's play a game of UNO\n");
	printf("Press 1 to shuffle the UNO deck or 2 to load a deck from a file: ");
	scanf("%d", &gameAction);
	if (gameAction == 1) {

	}
	return 0;
}
