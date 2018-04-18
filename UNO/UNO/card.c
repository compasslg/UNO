#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include <string.h>
card *remove_card(card **cards, int index)
{
	card *temp = *cards;
	if (temp == NULL) {
		return NULL;
	}
	else if (index == 0) {
		*cards = temp->pt;
		temp->pt = NULL;
	}
	else {
		for (int i = 1; i < index; i++) {
			temp = temp->pt;
		}
		temp->prev->pt = temp->pt;
		temp->pt = NULL;
	}
	return temp;
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
	if (newCard->pt != NULL) {
		newCard->pt->prev = newCard;
	}
	temp->pt = newCard;
}
void swap(card *cards, int i, int j) {
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
void shuffle(card *cards) {
	int numOfCards = num_of_cards(cards);

	rand() / RAND_MAX;
}
card *create_deck(FILE *inp){
    int i;
	const char suits[4][7] = {"Red", "Yellow", "Green", "Blue"};
    card *deck = NULL;
	card *temp = NULL;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			// each color has two card with the same number
			for (int k = 0; k < 2; k++) {
				temp = (card*)malloc(sizeof(card));
				switch (j) {
				case 10:
					strcpy(temp->action, "skip");
					break;
				case 11:
					strcpy(temp->action, "reverse");
					break;
				case 12:
					strcpy(temp->action, "draw two");
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
 
card *load_deck() {
	
}
void print_deck(card *cards) {
	card *temp = cards;
	while (1) {
		if (strlen(temp->action) == 0) {
			printf("%d%s", temp->value, temp->suit);
		}
		else {
			printf("%s", temp->action);
		}
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
