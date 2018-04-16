#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "card.h"
//== The main function ===========================================================
int main(void) {
	int numOfPlayers = 2;
    
    printf("%d\n", numOfPlayers);
    printf("%d", numOfPlayers - 1);
    printf("%c", (char)numOfPlayers);
    
	return 0;
}
