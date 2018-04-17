#include <stdio.h>
#include <stdlib.h>
#include "card.h"

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
<<<<<<< HEAD
card *create_deck() {
	
=======

void create_deck(card *deck, FILE *inp){
    int i;
    char suit_color = 'R';
    card *temp = deck;
    
    for(i = 0; i < 10; i++){
        temp->value = i;
        strcpy(temp->action, "basic");
        temp->suit = suit_color;
        temp = temp->pt;
    }
>>>>>>> 1835dd0a2444d266d3e086381581da42f9a2adb7
}
 
card *load_deck() {

}
void print_deck(card *cards) {
	card *temp = cards;
	while (temp != NULL) {
		printf("%d ", temp->value);
		//printf("%s %d %s\n", temp->suit, temp->value, temp->action);
		temp = temp->pt;
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
<<<<<<< HEAD
=======

>>>>>>> 1835dd0a2444d266d3e086381581da42f9a2adb7
