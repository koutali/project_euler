#include "stdafx.h"
#include "util.h"

uint Util::ConvertCardType(char cardType)
{
	uint cardTypeToReturn = UNDEFINED_CARD_TYPE;

	switch(cardType)
	{
	case 'H':
		cardTypeToReturn = HEART;
		break;

	case 'S':
		cardTypeToReturn = SPADES;

		break;

	case 'D':
		cardTypeToReturn = DIAMONDS;

		break;

	case 'C':
		cardTypeToReturn = CLUB;

		break;

	default:
		break;
	}

	return cardTypeToReturn;
}

uint Util::ConvertCardValue(char cardValue)
{
	uint cardValueToReturn = UNDEFINED_CARD_VALUE;

	switch(cardValue)
	{
	case 'J':
		cardValueToReturn = JACK;
		break;

	case 'K':
		cardValueToReturn = KING;
		break;

	case 'Q':
		cardValueToReturn = QUEEN;
		break;

	case 'A':
		cardValueToReturn = ACE;
		break;

	case 'T':
		cardValueToReturn = TEN;
		break;

	default:
		cardValueToReturn = (uint) (cardValue - '0');
		if (cardValueToReturn < 0 || cardValueToReturn > 10)
		{
			cardValueToReturn = UNDEFINED_CARD_VALUE;
		}

		break;
	}

	return cardValueToReturn;
}

bool Util::isRoyalFlush(std::vector<Card*>& p_cards)
{
	bool royalFlush = true;

	std::vector<Card*>::iterator it = p_cards.begin();
	for (; it != p_cards.end(); ++it)
	{
		if ((*it)->getCardValue() == TEN ||(*it)->getCardValue() == JACK ||
			(*it)->getCardValue() == QUEEN || (*it)->getCardValue() == KING ||
			(*it)->getCardValue() == ACE)
		{
			continue;
		}
		else
		{
			royalFlush = false;
			break;
		}
	}

	return royalFlush;
}

void Util::sortCards(std::vector<Card*>& p_cards)
{
	for (size_t i = 0; i < p_cards.size(); ++i)
	{
		for (size_t j = i + 1; j < p_cards.size(); ++j)
		{
			if (p_cards.at(i)->getCardValue() > p_cards.at(j)->getCardValue())
			{
				std::swap(p_cards.at(i), p_cards.at(j));
			}
		}
	}
}

bool Util::isStraightFlush(std::vector<Card*>& p_cards)
{
	bool straightFlush = true;
	for (size_t i = 0; i < p_cards.size() - 1; ++i)
	{
		if (p_cards.at(i)->getCardType() != p_cards.at(i+1)->getCardType())
		{
			straightFlush = false;
			break;
		}

		if (p_cards.at(i) - p_cards.at(i+1) != 1)
		{
			straightFlush = false;
			break;
		}
	}

	return straightFlush;
}

void Util::determineDuplicateCards(std::vector<Card*>& p_cards)
{
	uint numberOfDuplicates = 0;

	Card * toAdd = NULL;
	for (size_t i = 0; i < p_cards.size() - 1; ++i)
	{
		Card * currentCard = p_cards.at(i);
		Card * nextCard = p_cards.at(i+1);

		if (currentCard->getCardValue() == nextCard->getCardValue())
		{
			++numberOfDuplicates;
			toAdd = currentCard;
		}
		else
		{
			if (numberOfDuplicates != 0)
			{
				m_occurences.insert(std::pair<uint,uint>(toAdd->getCardValue(), numberOfDuplicates));
				numberOfDuplicates = 0;
			}
		}
	}
	if (numberOfDuplicates != 0 && toAdd != NULL)
	{
		m_occurences.insert(std::pair<uint,uint>(toAdd->getCardValue(), numberOfDuplicates));
	}

	for(std::map<uint,uint>::iterator it = m_occurences.begin(); it != m_occurences.end(); ++it ) 
	{
		m_occurencesVector.push_back(it->second);
	}

	std::sort(m_occurencesVector.begin(), m_occurencesVector.end());
}

bool Util::isFourOfAKind()
{
	return m_occurencesVector.size() == 1 && m_occurencesVector.at(0) == 3;
}

bool Util::isTwoPairs()
{
	return m_occurencesVector.size() == 2 && m_occurencesVector.at(0) == 1 && m_occurencesVector.at(1) == 1;
}

bool Util::isOnePair()
{
	const std::vector<uint>::iterator it = std::find(m_occurencesVector.begin(), m_occurencesVector.end(), 1);
	return it != m_occurencesVector.end();}

bool Util::isThreeOfAKind()
{
	const std::vector<uint>::iterator it = std::find(m_occurencesVector.begin(), m_occurencesVector.end(), 2);
	return it != m_occurencesVector.end();
}

bool Util::isFullHouse()
{
	return (isThreeOfAKind() && isOnePair());
}

bool Util::isFlush(std::vector<Card*>& p_cards)
{
	bool flush = true;

	std::vector<Card*>::iterator it = p_cards.begin();
	uint cardSuite = (*it)->getCardType();

	for (; it != p_cards.end(); ++it)
	{
		if (cardSuite != (*it)->getCardType())
		{
			flush = false;
			break;
		}
	}

	return flush;
}

bool Util::isStraight(std::vector<Card*>& p_cards)
{
	bool straightFlush = true;
	for (size_t i = 0; i < p_cards.size() - 1; ++i)
	{
		if (p_cards.at(i+1)->getCardValue() - p_cards.at(i)->getCardValue() != 1)
		{
			straightFlush = false;
			break;
		}
	}

	return straightFlush;
}

#if 0
uint CardConverter::getHighestCardInHand()
{
	if (m_handType == ONE_PAIR || m_handType == TWO_PAIRS || m_handType == THREE_OF_A_KIND || m_handType == FOUR_OF_A_KIND || m_handType == FULL_HOUSE)
	{
		
	}
	else
	{

	}
}
#endif 

// TODO //
Hand* Util::determineHandType(std::vector<Card*>& p_cards)
{
	determineDuplicateCards(p_cards);

	Hand * newHand = nullptr;

	uint handType = HIGHEST_CARD;

	if (isRoyalFlush(p_cards))
	{
		newHand = new NonRepeatedHand(ROYAL_FLUSH, p_cards);
	}
	else if (isStraightFlush(p_cards))
	{
		newHand = new NonRepeatedHand(STRAIGHT_FLUSH, p_cards);
	}
	else if (isFourOfAKind())
	{
		newHand = new RepeatedHand(FOUR_OF_A_KIND, p_cards, m_occurences, m_occurencesVector);
	}
	else if (isFullHouse())
	{
		newHand = new RepeatedHand(FULL_HOUSE, p_cards, m_occurences, m_occurencesVector);
	}
	else if (isFlush(p_cards))
	{
		newHand = new NonRepeatedHand(FLUSH, p_cards);
	}
	else if (isStraight(p_cards))
	{
		newHand = new NonRepeatedHand(STRAIGHT, p_cards);
	}
	else if (isThreeOfAKind())
	{
		newHand = new RepeatedHand(THREE_OF_A_KIND, p_cards, m_occurences, m_occurencesVector);
	}
	else if (isTwoPairs())
	{
		newHand = new RepeatedHand(TWO_PAIRS, p_cards, m_occurences, m_occurencesVector);
	}
	else if (isOnePair())
	{
		newHand = new RepeatedHand(ONE_PAIR, p_cards, m_occurences, m_occurencesVector);
	}
	else
	{
		newHand = new NonRepeatedHand(HIGHEST_CARD, p_cards);
	}

	m_occurences.clear();
	m_occurencesVector.clear();
	return newHand;
}