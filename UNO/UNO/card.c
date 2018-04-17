#include <stdio.h>
#include <stdlib.h>
#include "card.h"

card *remove_card(card *cards, int index)
{
	card *temp = cards;
	for (int i = 0; i < index; i++) {
		temp = temp->pt;
	}
	temp->prev->pt = temp->pt;
	temp->pt = NULL;
	return temp;
}
void insert_card(card *cards, card *newCard, int index) {
	card *temp = cards;
	for (int i = 0; i < index; i++) {
		temp = temp->pt;
	}
	newCard->pt = temp;
	temp->prev->pt = newCard;
	newCard->prev = temp->prev;
	temp->prev = newCard;
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
card *create_deck() {
	
}
card *load_deck() {

}
void print_deck(card *cards) {

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
