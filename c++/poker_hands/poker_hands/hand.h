#pragma once

#include "card.h"

class Hand
{
public:
	Hand(uint handType, const std::vector<Card*>& p_cards);
	virtual ~Hand();
	uint getHandType();
	virtual uint getHighestCardInHand() = 0;
	virtual uint getNextHighestCardInHand() = 0;

protected:
	std::vector<Card*> m_cards;
	uint m_handType;
};

class RepeatedHand : public Hand
{
public:
	RepeatedHand(uint handType, const std::vector<Card*>& p_cards, const std::map<uint, uint>& p_occurrences, const std::vector<uint>& p_occurencesVector);
	virtual ~RepeatedHand();
	virtual uint getHighestCardInHand();
	virtual uint getNextHighestCardInHand();
private:
	std::map<uint, uint> m_occurences;
	std::vector<uint> m_occurencesVector;
};

class NonRepeatedHand : public Hand
{
public:
	NonRepeatedHand(uint handType, const std::vector<Card*>& p_cards);
	virtual ~NonRepeatedHand();
	virtual uint getHighestCardInHand();
	virtual uint getNextHighestCardInHand();

private:
	uint m_nextHighestCardIndex;
};