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

        do {
            cout << "Target is: " << target << endl;

            cout << "Enter a guess (1-100): ";
            cin >> guess;

            while(cin.fail()){
                cout << endl;
                
                cin.clear();
                cin.ignore(255,'\n');
                cout <<"invalid choice\n";
                cout << 5-invalidLoop << " attempts remaining";
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
            
            tries++;

        }while(guess != target);

        cout << "Would you like to play again?\n[y]es [n]o: ";
        cin >> gameOn;


    }

    



    return 0;
}