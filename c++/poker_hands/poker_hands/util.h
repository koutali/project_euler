#pragma once

#include "card.h"
#include "hand.h"

class Util
{
public:
	uint ConvertCardType(char p_cardType);
	uint ConvertCardValue(char p_cardValue);

	void sortCards(std::vector<Card*>& p_cards);
	bool isRoyalFlush(std::vector<Card*>& p_cards);
	bool isStraightFlush(std::vector<Card*>& p_cards);
	bool isFlush(std::vector<Card*>& p_cards);
	bool isStraight(std::vector<Card*>& p_cards);

	bool isFourOfAKind();
	bool isFullHouse();
	bool isThreeOfAKind();
	bool isTwoPairs();
	bool isOnePair();

	void determineDuplicateCards(std::vector<Card*>& p_cards);
	Hand* determineHandType(std::vector<Card*>& p_cards);

	std::map<uint, uint> m_occurences;
	std::vector<uint> m_occurencesVector;
};