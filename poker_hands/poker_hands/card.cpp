#include "stdafx.h"
#include "card.h"

Card::Card(uint cardValue, uint cardType)
{
	if (cardValue < 2 || cardValue > ACE)
	{
		throw new std::invalid_argument("Card value invalid");
	}

	if (cardType < HEART || cardType > DIAMONDS)
	{
		throw new std::invalid_argument("Card type invalid");
	}

	m_cardValue = cardValue;
	m_cardType = cardType;
}

Card::~Card()
{}

uint Card::getCardValue()
{
	return m_cardValue;
}

uint Card::getCardType()
{
	return m_cardType;
}