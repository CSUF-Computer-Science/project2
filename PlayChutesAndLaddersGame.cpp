//
//  PlayChutesAndLaddersGame.cpp
//

#include <cassert>
#include <iostream>
#include <stdlib.h>     /* srand */
#include <time.h>       /* time */

#include "ChutesAndLaddersGame.hpp"
#include "Player.hpp"

using namespace std;

const int MONTE_CARLO = 100;

void checkGameBoard() {
   // Check if game board is constructed properly
   GameBoard theGameBoard;
   for (int ib = 0; ib < BOARD_SIZE; ib++) {
      switch (ib) {
         case GameBoard::ONE: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 38);
            break;
         case GameBoard::FOUR: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 14);
            break;
         case GameBoard::NINE: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 31);
            break;
         case GameBoard::SIXTEEN: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 6);
            break;
         case GameBoard::TWENTY_ONE: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 42);
            break;
         case GameBoard::TWENTY_EIGHT: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 84);
            break;
         case GameBoard::THIRTY_SIX: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 44);
            break;
         case GameBoard::FORTY_SEVEN: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 26);
            break;
         case GameBoard::FORTY_NINE: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 11);
            break;
         case GameBoard::FIFTY_ONE: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 67);
            break;
         case GameBoard::SIXTY_TWO: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 19);
            break;
         case GameBoard::FIFTY_SIX: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 53);
            break;
         case GameBoard::SIXTY_FOUR: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 60);
            break;
         case GameBoard::SEVENTY_ONE: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 91);
            break;
         case GameBoard::EIGHTY: // Ladder
            assert(theGameBoard.checkChutesLadders(ib) == 100);
            break;
         case GameBoard::EIGHTY_SEVEN: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 24);
            break;
         case GameBoard::NINETY_THREE: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 73);
            break;
         case GameBoard::NINETY_FIVE: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 75);
            break;
         case GameBoard::NINETY_EIGHT: // Chute
            assert(theGameBoard.checkChutesLadders(ib) == 78);
            break;
         default:
            assert(theGameBoard.checkChutesLadders(ib) == ib);
            break;
      } // end switch
   } // end for loop
}  // end checkGameBoard

void checkPlayer() {
   // check parameterized constructor
   Player player("ptester");
   assert(player.getName() == "ptester");
   assert(player.getPostion() == 0);
   cout << "Player name: " << player.getName() << endl;
   cout << "Player's postion: " << player.getPostion() << endl;
   cout << "Player die's face value: " << player.getDie().getFaceValue() << endl;
   
   // set player's position to a new value to test copy constructor
   player.setPostion(9);
   // test copy constructor
   Player aPlayer = player;
   assert(aPlayer.getName() == player.getName());
   assert(aPlayer.getPostion() == player.getPostion());
   assert(aPlayer.getDie().getFaceValue() == player.getDie().getFaceValue());
   cout << ">> test Player's class copy constructor" << endl;
   cout << "Copied player name: " << aPlayer.getName() << endl;
   cout << "Copied player's postion: " << aPlayer.getPostion() << endl;
   cout << "Copied player die's face value: " << aPlayer.getDie().getFaceValue() << endl;

   // test assignment operator
   Player bPlayer;
   bPlayer = aPlayer;
   assert(bPlayer.getName() == aPlayer.getName());
   assert(bPlayer.getPostion() == aPlayer.getPostion());
   assert(bPlayer.getDie().getFaceValue() == aPlayer.getDie().getFaceValue());
   cout << ">> test Player's class assignment operator" << endl;
   cout << "Player name (assignment operator): " << bPlayer.getName() << endl;
   cout << "Player's postion (assignment operator): " << bPlayer.getPostion() << endl;
   cout << "Player die's face value (assignment operator): " << bPlayer.getDie().getFaceValue() << endl;

}

void checkChutesAndLaddersGame() {
   // test destructor
   cout << ">> test destructor" << endl;
   ChutesAndLaddersGame *myGame2 = new ChutesAndLaddersGame();
   delete myGame2;
   
   // check ChutesAndLaddersGame's constructor with number of players input
   cout << ">> my first game:" << endl;
   ChutesAndLaddersGame myGame;
   assert(myGame.getNumberOfPlayers() == MIN_NUMBER_OF_PLAYERS);
   cout << "Number of players: " << myGame.getNumberOfPlayers() << endl;
   
   // test playGame
   // always start with seed 1, so should have the same result each time playGame is executed
   srand( (static_cast<unsigned int>(1)) ); // initialize random seed of 1
   myGame.playGame();

   // test another game - result should be the same as the previous game
   cout << "Results of first game and second game should be the same" << endl;
   cout << ">> Another game:" << endl;
   ChutesAndLaddersGame anotherGame;
   assert(myGame.getNumberOfPlayers() == MIN_NUMBER_OF_PLAYERS);
   cout << "Number of players in another game: " << myGame.getNumberOfPlayers() << endl;
   // always start with seed 1, so should have the same result each time playGame is executed
   srand( (static_cast<unsigned int>(1)) ); // initialize random seed to 1
   anotherGame.playGame();
   // test the winners of the 2 games
   assert(myGame.getWinner() == anotherGame.getWinner());
   

   cout << ">> test resetPlayersPosition:" << endl;
   // reset players position
   string myWinner = myGame.getWinner();
   myGame.resetGame();
   // always start with seed 1, so should have the same result each time playGame is executed
   srand( (static_cast<unsigned int>(1)) ); // initialize random seed to 1
   myGame.playGame();
   assert(myGame.getWinner() == myWinner);
   
}

int main() {
   
   cout << "*** Check GameBoard ***" << endl;
   {
      checkGameBoard();
   }
   cout << endl;

   cout << "*** Check Player ***" << endl;
   {
      checkPlayer();
   }
   cout << endl;
   
   cout << "*** Check ChutesAndLaddersGame ***" << endl;
   {
      checkChutesAndLaddersGame();
   }
   cout << endl;
   
   // Now, do monte carlo simulation of the Chutes and Ladders game
   cout << "===== Play the Chutes and Ladders Game " << MONTE_CARLO << " times =====" << endl;
   cout << "        (results should be different)" << endl << endl;
   ChutesAndLaddersGame *chutesAndLaddersGame = new ChutesAndLaddersGame();
   int iMonteCarlo = 0;
   while (iMonteCarlo < MONTE_CARLO) {
      srand( (static_cast<unsigned int>(iMonteCarlo + time(NULL))) ); // initialize random seed
      chutesAndLaddersGame->playGame();
      // next monte carlo
      iMonteCarlo++;
      // reset players position
      chutesAndLaddersGame->resetGame();
   } // end while(iMonteCarlo)
   delete chutesAndLaddersGame;
   
   
}
