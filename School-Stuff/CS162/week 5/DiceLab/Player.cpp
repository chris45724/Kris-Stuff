#include "Player.h"
#include <iostream>


//Replaced the origianal constrctor with a default value

void clear(){
    std::cout << "\033[2J\033[1;1H";
}

Player::Player(isCPU = false)
{
    totalScore = 0;
    roundScore = 0;  
}

int Player::getTotalScore()//get the total score for the player 
{return totalScore;}

void Player::resetRoundScore()//set the round score to zero 
{Player::roundScore = 0;}

int Player::getRoundScore()//get the current round score 
{return Player::roundScore;}

void Player::playRound()//check whether the player is human or CPU and call the correct "Turn" function 
{
    if(isCPU){
        cpuTurn();
    }else{
       playerTurn(); 
    }
}

void Player::playerTurn();//Manage a player round of player turns. Complicated function. Continuously ask the player to roll or hold. Evaluate results. 
{

}

void Player::cpuTurn();//Manage a CPU turn. Similar to a player turn but with no input. The CPU will roll until they reach 20 points. 
{

}


int main(){
   Player Test(0);

    
    
    return 0;
}