/*
Chris Howard
Guess a number lab
CS161
*/

#include <iostream>
#include <time.h>

using namespace std;


int main()
{
    int target, guess;
    int tries = 0;
    int invalidLoop = 0;
    int numGuesses = 0;
    //cout << "Target is: " << target << endl;
    char gameOn = 'y';
    srand(time(nullptr));
    //target = (rand()%100)+1;

    while(gameOn != 'n'){

        target = (rand()%100)+1;
        tries = 0;
        cout << endl;

        do {
            //cout << "Target is: " << target << endl;

            cout << "Enter a guess (1-100): ";
            cin >> guess;

            while(cin.fail()){
                cout << endl;
                
                cin.clear();
                cin.ignore(255,'\n');
                cout <<"invalid choice\n";
                cout << 5-invalidLoop << " attempts remaining\n";
                cout << "Enter a guess (1-100): ";
                cin >> guess;
                invalidLoop++;
                if(invalidLoop > 5){
                    cout << "Maximum attempts reached\nExiting\n";
                    return 1;
                }
                cout << endl;
            }


            if(guess > target){
                cout << endl;
                cout << guess <<" Too high" << endl;
            }
            else if(guess == target){
                cout << endl;
                cout << guess <<" Hit target!" << endl;
                cout << "Guess was: " << guess << endl;

                if(tries == 0){
                    cout << "It took you " << tries + 1<<" try!" << endl;
                    cout << "you good, or do you cheat?" << endl;
                }
                else if(tries < 2){
                    cout << "It took you " << tries + 1<<" tries!" << endl;
                    cout << "Amazing!" << endl;
                }
                else if(tries < 5){
                    cout << "It took you " << tries + 1<<" tries!" << endl;
                    cout << "Awesome!" << endl;
                }
                else if(tries < 10){
                cout << "It took you " << tries + 1<<" tries!" << endl;
                cout << "Good job!" << endl;
                }
                else{
                    cout << "It took you " << tries + 1<<" tries!" << endl;
                }
                

                
            }
            else if(guess < target)
            {
                cout << endl;
                cout << guess << " Too low" << endl;
            }
            else{
                cout << endl;
                cout << "This is an error\nYou should not see this\n";
            }
            


            // I'm too lazy to make this more efficient 
            if(target != guess){
                if(tries == 0){
                    cout << "you've made " << tries+1 << " guess\n";
                }
                else{
                cout << "you've made " << tries+1<< " guesses\n";
            }
            tries++;

            }

            

        }while(guess != target);

        cout << "\nWould you like to play again?\n[y]es [n]o: ";
        cin >> gameOn;
        cin.clear();
        cin.ignore(255,'\n');


    }

    



    return 0;
}