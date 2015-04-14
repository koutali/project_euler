#include "stdafx.h"
#include "card.h"
#include "hand.h"
#include "util.h"

int main()
{
	std::ifstream file("poker.txt", std::ios::in);
	if (!file)
	{
		std::cout << "File could not be opened!" << std::endl;
		return EXIT_FAILURE;
	}

	// parse input data 
	std::string card;
	const uint NUMBER_OF_CARDS_IN_A_LINE = 10;

	Util util;
	uint firstPlayerWins = 0;

	int game = 1;
	while (!file.eof())
	{
		uint numberOfCardsRead = 0;
		
		// create hands 
		std::vector<Card*> firstPlayerCards;
		std::vector<Card*> secondPlayerCards;

		// use one line in file to fill out the hands
		while(numberOfCardsRead < NUMBER_OF_CARDS_IN_A_LINE)
		{
			file >> card;

			uint cardNumber = util.ConvertCardValue(card.at(0));
			uint cardType = util.ConvertCardType(card.at(1));

			Card * newCard = new Card(cardNumber, cardType);
			if (numberOfCardsRead < NUMBER_OF_CARDS_IN_A_LINE / 2)
			{
				// add to first player's hand
				firstPlayerCards.push_back(newCard);
			}
			else
			{
				// add to second player's hand
				secondPlayerCards.push_back(newCard);
			}
			
			++numberOfCardsRead;
		}

		// sort hands to make processing easier
		util.sortCards(firstPlayerCards);
		util.sortCards(secondPlayerCards);

		Hand* firstPlayer = util.determineHandType(firstPlayerCards);
		Hand* secondPlayer = util.determineHandType(secondPlayerCards);

		// determine winner
		if (firstPlayer->getHandType() > secondPlayer->getHandType())
		{
			std::cout << "First player wins game " << game << std::endl;
			++firstPlayerWins;
		}
		else if (firstPlayer->getHandType() < secondPlayer->getHandType())
		{
			//std::cout << "Second player wins" << std::endl;
		}
		else
		{
			if (firstPlayer->getHighestCardInHand() > secondPlayer->getHighestCardInHand())
			{
				std::cout << "First player wins game " << game << std::endl;
				++firstPlayerWins;
			}
			else if (firstPlayer->getHighestCardInHand() < secondPlayer->getHighestCardInHand())
			{
				//std::cout << "Second player wins" << std::endl;
			}
			else
			{
				if (firstPlayer->getNextHighestCardInHand() > secondPlayer->getNextHighestCardInHand())
				{
					std::cout << "First player wins " << game << std::endl;
					++firstPlayerWins;
				} 
				else if (firstPlayer->getNextHighestCardInHand() < secondPlayer->getNextHighestCardInHand())
				{
					//std::cout << "Second player wins" << std::endl;
				}
				else
				{
					std::cout << "It's a tie!" << std::endl;
				}
			}
		}
		
		++game;

		delete firstPlayer;
		firstPlayer = nullptr;

		delete secondPlayer;
		secondPlayer = nullptr;

		//std::cout << std::endl; 
		Sleep(100);
	}

	std::cout << "Number of total wins for first player: " << firstPlayerWins << std::endl;

	return EXIT_SUCCESS;
}