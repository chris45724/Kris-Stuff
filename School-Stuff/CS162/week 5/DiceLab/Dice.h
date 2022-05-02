#ifndef _DICE_H_ 
#define _DICE_H_ 
 
#include <random> 
 
class Dice { 
private: 
    int numSides;//number of sides on the die 
    int value;//the side that is facing "up" on the die 
public: 
    Dice();//default constructor - will be overriden by a more useful one arg constructor 
    Dice(int x);//one arg constructor - this determines the number of faces on the die 
    void roll();//roll the dice. Generate a random number between 1 and numSides and set dice value to that number 
    int getValue();//get the current value of the die 
}; 
 
#endif