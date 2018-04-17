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
}card;

// Remove a card from a LinkedList. Take a pointer to a card, return the card that is removed
card *remove_card(card *cards);
// Shuffle a card deck. Take a pointer of card as parameter
void shuffle(card *cards);
// Create a new deck with all cards. Return a pointer of card
card *create_deck();
// Load a deck from file. Return a pointer of card
card *load_deck(); 
// Print a deck. Take a pointer to card as parameter
void print_deck(card *cards);