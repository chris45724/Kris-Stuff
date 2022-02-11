/*
Chris Howard
Guess a number lab
CS161
*/


// problems: 1, 2, 4, 6, 22

#include <iostream>
#include <time.h>

using namespace std;


int main(){

    cout << endl << endl;
    cout << "Challenge 1" << endl;
    /* Problem 1 All positive intigers list*/

    int chaNum1 = 1;

    do {
    if(cin.fail()){
        cout << "Invalid choice\nInput must be a positive intiger"<<endl;
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

    for(int i; i < chaNum1; i++){
        cout<< i+1 << endl;
    }




    //Challenge 2
    cout << endl << endl;
    cout << "Challenge 2" << endl;

    

    for(int ascii = 0;ascii < 128; ascii++){
        char a = ascii;
        cout << a;
        
        if(ascii % 16 == 0){
            cout << endl;
        }
        
    }

}