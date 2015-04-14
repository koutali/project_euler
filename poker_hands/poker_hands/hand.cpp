#include "stdafx.h"
#include "hand.h"

Hand::Hand(uint handType, const std::vector<Card*>& p_cards)
{
	std::copy(p_cards.begin(), p_cards.end(), std::back_inserter(m_cards));
	m_handType = handType;
}

Hand::~Hand()
{
	m_cards.clear();
}

uint Hand::getHandType()
{
	return m_handType;
}

RepeatedHand::RepeatedHand(uint handType, const std::vector<Card*>& p_cards, 
	const std::map<uint, uint>& p_occurrences, const std::vector<uint>& p_occurencesVector)
	:Hand(handType, p_cards)
{
	m_occurences.insert(p_occurrences.begin(), p_occurrences.end());
	std::copy(p_occurencesVector.begin(), p_occurencesVector.end(), std::back_inserter(m_occurencesVector));
}

RepeatedHand::~RepeatedHand()
{
	m_occurencesVector.clear();
	m_occurences.clear();
}

uint RepeatedHand::getHighestCardInHand()
{
	uint vectorEnd = m_occurencesVector.at(m_occurencesVector.size() - 1);

	for (std::map<uint, uint>::iterator itMap = m_occurences.begin(); itMap != m_occurences.end(); ++itMap)
	{
		if (itMap->second == vectorEnd)
		{
			return itMap->first;
		}
	}

	return 0;
}

uint RepeatedHand::getNextHighestCardInHand()
{
	uint nextHighestValue = 0;
	if (m_occurencesVector.size() > 1)
	{
		uint nextHighestOccurence = m_occurencesVector.at(1);

		for (std::map<uint, uint>::iterator itMap = m_occurences.begin(); itMap != m_occurences.end(); ++itMap)
		{
			if (itMap->second == nextHighestOccurence)
			{
				nextHighestValue = itMap->first;
				break;
			}
		}
	} 
	else // one repeated number detected
	{
		uint highestCard = getHighestCardInHand();
		for (size_t i = m_cards.size() - 1; i > 0; --i)
		{
			uint currentCardValue = m_cards.at(i)->getCardValue();
			if (currentCardValue != highestCard)
			{
				nextHighestValue = currentCardValue;
				break;
			}
		}
	}

	return nextHighestValue;
}

NonRepeatedHand::NonRepeatedHand(uint handType, const std::vector<Card*>& p_cards)
	:Hand(handType, p_cards)
{
	m_nextHighestCardIndex = m_cards.size() - 1;
}

NonRepeatedHand::~NonRepeatedHand()
{

}

uint NonRepeatedHand::getHighestCardInHand()
{
	Card* endCard = m_cards.at(m_cards.size() - 1);
	return endCard->getCardValue();
}

uint NonRepeatedHand::getNextHighestCardInHand()
{
	Card* nextHighestCar = m_cards.at(m_nextHighestCardIndex);
	--m_nextHighestCardIndex;
	return nextHighestCar->getCardValue();
}