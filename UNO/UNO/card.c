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
	int shuffleCount = 10 * rand() / RAND_MAX + numOfCards;
	int i, j;
	for (int count = 0; count <= shuffleCount; count++) {
		i = rand() % numOfCards;
		j = rand() % numOfCards;
		swap(cards, i, j);
	}
}

card *create_deck(){
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
    FILE *inp = NULL;
    char line[1000], temp[20];
    int i, j = 0;
    card *deck = (card*)malloc(sizeof(card));
    card *temp2 = deck;
    
    inp = fopen("deck.txt", "r");
    
    if(inp == NULL){
        printf("File does not exist");
    }
    char sym[10];
    while(!feof(inp)){
        fgets(line, 1000, inp);
        //char *arr[] = {strtok(line, ',')};
        for(i = 0; i < 1000; i++){
            while(line[i] != ','){
                temp[j] = line[i];
                j++;
                i++;
            }
            i--;
            j = 0;
        }
        
    }
    return deck;
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
