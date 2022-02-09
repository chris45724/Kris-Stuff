/*
Chris Howard
Assignment 5
CS161
*/


// problems: 1, 2, 4, 6, 22

#include <iostream>
#include <time.h>

using namespace std;


int main(){

    cout << endl << endl;
    cout << "Challenge 1" << endl << endl;
    /* Problem 1 All positive integers list*/

    int chaNum1 = 1;

    do {
    if(cin.fail()){
        cout << "Invalid choice\nInput must be a positive integer"<<endl;
        cin.clear();
        cin.ignore(255,'\n');
    }
    else if(chaNum1 <= 0){
        cout << "Input must be greater than 1" << endl;
    }
    cout << "Please input a number: ";
    cin >> chaNum1;
    cout << endl;
    } while(cin.fail() || (chaNum1 < 1));

    //cout << chaNum1;

    for(int i; i < chaNum1 - 1; i++){
        cout<< i+1 << " + " <<  chaNum1 - (i+1) << " = " << chaNum1 << endl;
    }




    //Challenge 2 || This challenge kinda breaks because ascii breaks it :(
    cout << endl << endl;
    cout << "Challenge 2" << endl << endl;

    

    for(int ascii = 0;ascii < 128; ascii++){
        char a = ascii;
        cout << "|" << a << " : " << ascii << "|";
        
        if(ascii % 16 == 0){
            cout << endl;
        }
    
    }


    //Challenge 4

    float runnerTime = 0;
    
    cout << endl << endl;
    cout << "Challenge 4" << endl << endl;

    cout << "A runner will burn 3.6 callories per minute\n";

    do{
        runnerTime += 5;
        cout << "After " << runnerTime << " minutes, a runner will burn " << (runnerTime * 3.6) << " callories\n";

    }while(runnerTime < 30);
    



    float time = 0;
    float speed = 0;


    cout << endl << endl;
    cout << "Challenge 6" << endl << endl;

    // Challenge 6
    do {
        
        
        cout << "How fast was the vehicle traveling: ";
        cin >> speed;


        if(cin.fail()){
            cout << "Invalid choice\nInput must be a positive integer"<<endl;
            cin.clear();
            cin.ignore(255,'\n');
        }

        if(speed <= 0){
            cout << "Speed must be greater than 1" << endl;
        }

    }while(cin.fail() || (speed < 1));




    do {
        
        
        cout << "How many hours was the vehicle traveling for: ";
        cin >> time;


        if(cin.fail()){
            cout << "Invalid choice\nInput must be a positive integer"<<endl;
            cin.clear();
            cin.ignore(255,'\n');
        }

        if(time <= 0){
            cout << "Time must be greater than 1" << endl;
        }


    }while(cin.fail() || (time < 1));

    cout << "--------------------------------------------\n";
    for(int i = 0; i < time; i++){

        cout << "After " << time << " hours, the vehicle has traveled " << speed * (i+1) << " Miles\n";

    }



    //Challenge 22

    int squareSize = 0;


    cout << endl << endl;
    cout << "Challenge 22" << endl << endl;

    cout << "Please enter a size for a square to make\nThe size of the square must be less than 15, and greater than 1\n";

    cout << "What size square did you want: ";

    cin >> squareSize;
    cout << endl;

    while(cin.fail() || squareSize <= 0 || squareSize > 15){

        if(cin.fail()){
            cout << "Your input must be a whole integer\n";
            cin.clear();
            cin.ignore(255,'\n');
            }
        
        else if(squareSize <= 0 || squareSize > 15){
            cout << "Your number must be greater than 0 and less than 16\n";
        }
        
        
        
        cout << "Please provide a new input: ";
        cin >> squareSize;
        cout << endl;
    }

    for(int i = 1; i <= squareSize; i++){

        for(int x = 1; x <= squareSize; x++){

            cout << "X";
        }
        cout << endl;
    }
    


}