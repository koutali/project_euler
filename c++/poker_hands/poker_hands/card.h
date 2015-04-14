#pragma once

#include <vector>

typedef enum HAND_TYPE
{
	HIGHEST_CARD,
	ONE_PAIR,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH,
	UNDEFINED_HAND_TYPE
};

typedef enum CARD_VALUE
{
	TEN = 10,
	JACK, 
	QUEEN, 
	KING, 
	ACE,
	UNDEFINED_CARD_VALUE
};

typedef unsigned int uint;

typedef enum CARD_TYPE
{
	HEART,
	CLUB,
	SPADES,
	DIAMONDS,
	UNDEFINED_CARD_TYPE
};

class Card
{
public:
	Card(uint cardValue, uint cardType);
	~Card();
	uint getCardValue();
	uint getCardType();

private:
	uint  m_cardValue;
	uint  m_cardType;
};
