#pragma once
#define RED "\xe2\x99\xa5"
#define YELLOW "\xE2\x99\xA6"
#define GREEN "\xE2\x99\xA3"
#define BLUE "\xE2\x99\xA0"
#define SKIP 10
#define REVERSE 11
#define DRAW_TWO 12
#define WILD 13
//== A node type that represent a card ===========================================
typedef struct card_s {
    char suit[7];
	int value;
	char action[15];
	struct card_s *pt;
}card;

/* Remove a card at the certain index from a LinkedList of cards 
   Take a pointer to the list of cards and an int
   return the card that is removed
*/
card *remove_card(card **cards, int index);

/* Insert a card in the certain index of a LinkedList of cards
   Take a pointer to the list of cards, a pointer to a card, and an int
*/
void insert_card(card **cards, card *newCard, int index);

/* Draw cards from one list of cards to another
   Take two pointer to the lists of cards, 
   and an int represents number of cards to be drawn
*/
void draw_cards(card **deck, card **discardPile, card **player, int numOfCards);

/* Swap two cards in a list of cards
   Take a pointer to the list of cards and two ints as parameters
*/
void swap(card **cards, int i, int j);

// Shuffle a card deck. Take a pointer of card as parameter
void shuffle(card **cards);

// Create a new deck with all cards. Return a pointer of card
card *create_deck();

// Load a deck from file. Return a pointer of card
card *load_deck(); 

// Print a card. Take a pointer to a card
void print_a_card(card *c);

// Print a deck. Take a pointer to list of cards as parameter
void print_cards(card *cards);

// Take a pointer to a list of cards and return a int represents number of cards in the list
int num_of_cards(card *cards);