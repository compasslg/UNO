#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

card *remove_card(card **cards, int index)
{
	card *temp1 = *cards;
	card *temp2 = NULL;
	if (temp1 == NULL) {
		return NULL;
	}
	else if (index == 0) {
		*cards = temp1->pt;
		temp1->pt = NULL;
	}
	else {
		for (int i = 1; i < index; i++) {
			temp1 = temp1->pt;
		}
		temp2 = temp1->pt;
		temp1->pt = temp1->pt->pt;
		temp1 = temp2;
		temp1->pt = NULL;
	}
	return temp1;
}
void insert_card(card **cards, card *newCard, int index) {
	// When inserting to the top
	if (index == 0) {
		newCard->pt = *cards;
		*cards = newCard;
		return;
	}
	card *temp = *cards;
	for (int i = 1; i < index; i++) {
		temp = temp->pt;
	}
	newCard->pt = temp->pt;
	temp->pt = newCard;
}
void draw_cards(card **deck, card **discardPile, card **player, int numOfCards) {
	card *c = NULL;
	for (int i = 0; i < numOfCards; i++) {
		// If there is no card left, shuffle the discard pile and replace deck
		if(num_of_cards(deck == 0)){
			c = remove_card(discardPile, 0);
			shuffle(discardPile);
			*deck = *discardPile;
			*discardPile = c;
		}
		c = remove_card(deck, 0);
		insert_card(player, c, 0);
	}
}
void swap(card **cards, int i, int j) {
	card temp;
	card *curr = cards;
	if (i == j) {
		return;
	}
	else if (i > j) {
		card *iCard = remove_card(cards, i);
		card *jCard = remove_card(cards, j);
		insert_card(cards, iCard, j);
		insert_card(cards, jCard, i);
	}
	else {
		card *jCard = remove_card(cards, j);
		card *iCard = remove_card(cards, i);
		insert_card(cards, jCard, i);
		insert_card(cards, iCard, j);
	}
}
void shuffle(card **cards) {
	int numOfCards = num_of_cards(*cards);
	srand(time(NULL));
	int shuffleCount = 10 * rand() / RAND_MAX + numOfCards;
	int i, j;
	for (int count = 0; count <= shuffleCount; count++) {
		i = rand() % numOfCards;
		j = rand() % numOfCards;
		swap(cards, i, j);
	}
}
//this function creates a deck of uno cards to be used for the game
card *create_deck(){
    const char suits[4][7] = {RED, YELLOW, GREEN, BLUE};
    card *deck = NULL;
	card *temp = NULL;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 14; j++) {
			// each color has two card with the same number
			for (int k = 0; k < 2; k++) {
				temp = (card*)malloc(sizeof(card));
				switch (j) {
				case SKIP:
					strcpy(temp->action, "skip");
					break;
				case REVERSE:
					strcpy(temp->action, "reverse");
					break;
				case DRAW_TWO:
					strcpy(temp->action, "draw two");
					break;
                case WILD:
					if (i < 2) {
						strcpy(temp->action, "wild");
					}
					else {
						strcpy(temp->action, "wild draw four");
					}
                    break;
				default:
					strcpy(temp->action, "");
					break;
				}
				temp->value = j;
				strcpy(temp->suit, suits[i]);
				insert_card(&deck, temp, 0);
				// Only need one card if the number is 0
				if (j == 0) {
					break;
				}
			}
		}
	}
	return deck;
}
//this function loads a deck of cards from a dedicated file
card *load_deck() {
    FILE *inp = NULL;
    char line[100], temp[10];
    int i, j = 0, z =0, temp_int[4];
    card *deck = (card*)malloc(sizeof(card));
    card *temp2 = deck;
    
    inp = fopen("deck.txt", "r");
    
    if(inp == NULL){
        printf("File does not exist");
    }
    
    char sym[10];
    while(!feof(inp)){
        fgets(line, 100, inp);
        for(i = 0; i < 100; i++){

            while(line[i] != ','){
                if(line[i] == ' '){
                    continue;
                }
                temp[j] = line[i];
                j++;
                i++;
            }
            strcpy(sym, temp);
            sym[0] = ' ';
          //  strcpy(temp_int, temp);
            strcpy(temp2->suit, sym);
            j = 0;
        }

    }
    return deck;
}
// this function prints a card. Take a pointer to a card
void print_a_card(card *c) {
	if (c->value <= 9) {
		printf("%d%s", c->value, c->suit);
	}
	else if (c->value == WILD) {
		printf("%s", c->action);
	}
	else {
		printf("%s%s", c->action, c->suit);
	}
}
//this function prints the deck of cards to the console
void print_cards(card *cards) {
    card *temp = cards;
    while (1) {
		print_a_card(temp);
        //printf("%s %d %s\n", temp->suit, temp->value, temp->action);
        temp = temp->pt;
        if (temp != NULL) {
            printf(", ");
        }
        else {
            break;
        }
    }
    printf("\n");
}
int num_of_cards(card *cards) {
	card *temp = cards;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->pt;
	}
	return count;
}


