//

//  Player.hpp

//



#pragma once



#include <stdio.h>

#include <string>



#include "Die.hpp"

#include "Gameboard.hpp"



using namespace std;



class Player {

public:

	

	Player() : playerName("no name"), position(0), die() {}



	Player(string name) : playerName(name), position(0), die() {}




	Player(const Player &p) : playerName(p.playerName), position(p.position) {}



	Player& operator=(const Player& p)
	{
		playerName = p.playerName;
		position = p.position;
		die = p.die;
		return *this;
	}



	

	~Player() { }



	// getters and setters

	void setName(string name) { playerName = name; }

	void setPostion(int location) { position = location; }

	string getName() const { return playerName; }

	int getPostion() const { return position; }

	Die getDie() { return die; }



	// return player's new position after player rolls die

	// If the new position is outside of the board, player stays put

	// If not, player moves to the new square = player's postion + die's face value

	// TO DO: implement this function to move player to the new postion

	//        after player rolls die. Position must be inside the board

	int rollDieAndMove()
	{
		die.roll();
		position = position + die.getFaceValue();
		if ((position < 0) || (position >= BOARD_SIZE)) {

			throw range_error("index out of bounds");

		}
		return position;
	}

private:

	string playerName;

	int position;

	Die die;

};
