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
