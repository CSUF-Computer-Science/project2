//
//  ChutesAndLaddersGame.hpp
//
#pragma once
#include <stdio.h>
#include <string>
#include "ArrayQueue.h"
#include "Player.hpp"
#include "Gameboard.hpp"
using namespace std;

const int MIN_NUMBER_OF_PLAYERS = 2;
class ChutesAndLaddersGame {
public:

	// TODO: implement the constructor with all your team members

	// constructor with the default value of 2 minimim players

	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS)
	{
		Player Andrew;
		Player Jacob;
		Andrew.setName("Andrew");
		Jacob.setName("Jacob");

		queue.enqueue(Andrew);
		queue.enqueue(Jacob);
	}

	

	// TODO: implement the destructor

	// destructor

	~ChutesAndLaddersGame()
	{
		while (!queue.empty())
		{
			queue.dequeue();
		}

	}



	// accessors

	// TO DO: implement the accessor to get the number Of Players

	long getNumberOfPlayers() {

		return MIN_NUMBER_OF_PLAYERS;

	}

	string getWinner() { return winner; }



	// TODO: implement this function properly

	// reset the game - (1) this will reset the position of each player to zero

	void resetGame()
	{


	}



	// TODO: implement this function properly

	// play the Chutes and Ladders game

	void playGame()
	{
		
		int x = 0;
		while (x != WINNING_POSITION)
		{

			Player * p = new Player("temp");

			*p = queue.front();

			int value = p->rollDieAndMove();

			int newValue = gameBoard.checkChutesLadders(value);


			








		}




	}

private:

	const int WINNING_POSITION = 100;



	string winner;       // the winner

	GameBoard gameBoard; // the game board



	ArrayQueue<Player> queue;				 // TO DO: use ArrayQueue to store the players

};
