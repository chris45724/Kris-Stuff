#ifndef _PLAYER_H_ 
#define _PLAYER_H_ 
 
#include "Dice.h" 
 
class Player { 
private: 
    int totalScore;//the total score for the game 
    int roundScore;//the score for the round at the moment 
    bool isCPU;//is this player a human or a CPU 
    //int playerSlot; //For more than 2 players
public: 
    //Player();//default constructor 
    Player(bool b);//one arg constructor - sets isCPU to true or false 
    int getTotalScore();//get the total score for the player 
    void resetRoundScore();//set the round score to zero 
    int getRoundScore();//get the current round score 
    void playRound();//check whether the player is human or CPU and call the correct "Turn" function 
    void playerTurn();//Manage a player round of player turns. Complicated function. Continuously ask the player to roll or hold. Evaluate results. 
    void cpuTurn();//Manage a CPU turn. Similar to a player turn but with no input. The CPU will roll until they reach 20 points. 
}; 
 
#endif