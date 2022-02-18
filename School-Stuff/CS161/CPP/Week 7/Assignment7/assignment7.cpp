/*
Chris Howard
CS161
Assignment
*/

#include <iostream>
#include <time.h>
#include <random>




using namespace std;








/*
 #8 


 Write a function that simulates the tossing of a coin. 
 When you call the function, it should generate a random number in the range of 1 through 2. 
 If the random number is 1, the function should display “heads.” If the random number is 2, the function should display “tails.” 
 Demonstrate the function in a program that asks the user how many times the coin should be tossed, 
 then simulates the tossing of the coin that number of times.

*/

void coin(int quantity){
    // Problem 8



    srand(time(NULL));
    int coin = (rand() % 2) + 1;
    string face;

    for (int i = 1; i <= quantity; i++){
        int coin = (rand() % 100) + 1;



        /* // This is for debugging
        if ((coin % 2) == 0){
            coin2 = 2;
        } else {
            coin2 = 1;
        }
        */


        // to make more realistic flips?? It felt a little off without this
        if ((coin % 2) == 0){
            face = "heads";
        } else {
            face = "tails";
        }



        cout << "Coin " << i << " was " << face << endl;


        //cout << coin<< " " << coin2 << " | ";

    }
    //int coin = (rand() % 2) + 1;

    

    //return coin;




}














int main(){
    
    int flips = 1;

    do {

        cout << "How many times would you like to flip a coin: ";
        cin >> flips;
        
        if(cin.fail()){
            cout << "Your input must be a whole integer\n";
            cin.clear();
            cin.ignore(255,'\n');
            }


    }while(cin.fail());


    coin(flips);
    
    
    return 0;
}






