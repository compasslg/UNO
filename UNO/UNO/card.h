#pragma once
#define RED '♥'
#define YELLOW '♦'
#define GREEN '♣'
#define BLUE '♠'
//== A node type that represent a card ===========================================
typedef struct card_s {
	char suit;
	int value;
	char action[15];
	struct card_s *pt;
	struct card_s *prev;
}card;

/* Remove a card at the certain index from a LinkedList of cards 
   Take a pointer to the list of cards and an int
   return the card that is removed
*/
card *remove_card(card *cards, int index);

/* Insert a card in the certain index of a LinkedList of cards
   Take a pointer to the list of cards, a pointer to a card, and an int
*/
void insert_card(card *cards, card *newCard, int index);

/* Swap two cards in a list of cards
   Take a pointer to the list of cards and two ints as parameters
*/
void swap(card *cards, int i, int j);

// Shuffle a card deck. Take a pointer of card as parameter
void shuffle(card *cards);

// Create a new deck with all cards. Return a pointer of card
card *create_deck();

// Load a deck from file. Return a pointer of card
card *load_deck(); 

// Print a deck. Take a pointer to card as parameter
void print_deck(card *cards);