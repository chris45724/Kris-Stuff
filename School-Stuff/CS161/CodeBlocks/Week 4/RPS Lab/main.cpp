/*
Chris Howard
RPS Lab (Lab 4)
CS161
*/

#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
using namespace std;

string choiceToWords(int player)
{
    string playerChoice;

    switch(player)
    {
    case 1:
        playerChoice = "rock";
        break;


    case 2:
        playerChoice = "paper";
        break;


    case 3:
        playerChoice = "scissors";
        break;
    default:
        playerChoice = "Invalid";
    }

    return playerChoice;
}

int main()
{


    srand(time(nullptr));

    //I got sick of writing rock paper and scissors
    string r = "rock";
    string p = "paper";
    string s = "scissors";

    int player;
    int computer = 2;
    //int computer = (rand() % 3) + 1;
    string playerChoice, computerChoice;
    bool win;


    cout << computer;



    cout << endl;

    cout << "Hello!\nLet's play rock paper scissors" << endl << endl;

    cout << "   For rock please enter 1" << endl << endl;
    cout << "   For paper please enter 2" << endl << endl;
    cout << "   For scissors please enter 3" << endl << endl;

    cout << "Your choice is: ";

    cin >> player;


    playerChoice = choiceToWords(player);
    cout << playerChoice;


/*
    switch(player)
    {
    case 1:
        playerChoice = r;
        break;


    case 2:
        playerChoice = p;
        break;


    case 3:
        playerChoice = s;
        break;
    default:
        playerChoice = "Invalid";
        dumb = true;
    }
*/
    if(playerChoice == "Invalid")
    {
       cout << "You picked an invalid choice!" << endl;
       cout << "The program will now end";
       exit(1);
    }

    //cout << playerChoice;

    if(player != computer)
    {


        if(player == 1 && computer == 2) // r-s 1-3
        {
            win = true;
        }
        else if (player == 2 && computer == 1) //p-r 2-1
        {
            win = true;
        }
        else if (player == 3 && computer == 2) //s-p 3-2
        {
            win = true;
        }
        else if (player == 3 && computer == 1) // s-r 3-1
        {
            win = false;
        }
        else if (player == 1 && computer == 2) // r-p 1-2
        {
           win = false;
        }
        else if (player == 2 && computer == 3) // p-s 2-3
        {
            win = false;
        }
        else
        {
            cout << "An unknown error has occurred" << endl;
            exit(1);

        }


    }

     if (win==true)
        {
            cout << endl << "You won!!"<<endl;
            cout << "The computer chose ";
        }


    return 0;
}
