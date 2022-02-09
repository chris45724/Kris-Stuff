/*
YOUR NAME: Chris Howard

CS 161 Midterm Exam
Programming Portion
*/


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main() {


        /*
    #0 ( 5 Pts)
    Prompt the user to enter a wager amount.
    Prompt the user to pick a color - red or black
    Inform the user that they have lost X dollars, where x is the amount wagered
    */
    cout << "#0--------------------\n\n";
    //solution here

    int wager;
    int color;
    cout << "How many dollars would you like to wager (Whole number only): ";
    cin >> wager;

    

    cout << "Would you like to wager on red or black?" << endl << endl;
    cout << "[1] Red\n[2] Black\n\n";
    cout << "Color: ";
    cin >> color;
    cout << endl;

    if(color == 1){
        cout << "I'm sorry, the color was black\n";
        cout << "You lost: " << wager << " dollars" << endl;
    }else if (color == 2){
        cout << "I'm sorry, the color was red\n";
        cout << "You lost: " << wager << " dollars" << endl;
    }else{
        cout << "Invalid input" << endl;
    }

    cout << endl;



    /*
    #1 (5 Pts)
    Prompt the user to enter the number of hours worked.
    Prompt the user to enter the pay rate.
    Calculate and display the total pay given the pay rate and number of hours worked.
    */
    cout << "#1--------------------\n\n";
    //solution here


    float hoursWorked, pay;
    cout << "How many hours did you work: ";
    cin >> hoursWorked;
    cout << endl;
    cout << "Enter the hourly wage: ";
    cin >> pay;

    cout << "The total amount earned is: $" << pay * hoursWorked << endl;
    cout << "Given hours [" << hoursWorked << "] hours and at a rate of [" << pay << "] dollars per hour \n";


    /*
    #2 (10 Pts)
    Prompt the user to enter a number corresponding to their selection given the following menu options
    Feel free to uncomment the text below to use for a menu prompt

    1. Hamburger - 4.99
    2. Cheeseburger - 5.99
    3. Bacon Cheeseburger - 6.99
    4. Fries - 2.99
    5. Fountain drink - 1.99

    Once the user has selected an item, prompt the user to enter the quantity ordered

    Calculate the cost of the order. Format the numeric portion to display two decimal places
    */
    cout << "#2--------------------\n\n";
    //solution here


    int order, orderQuantity;
    float cost;

    cout << "---- Menu ----\n";

    cout << "[1] Hamburger - 4.99\n[2] Cheeseburger - 5.99\n[3] Bacon Cheeseburger - 6.99\n[4] Fries - 2.99\n[5] Fountain drink - 1.99\n";


    cout << "\nYou may press the number corrsponding with your preferred meal\n";
    cout << "What would you like to order: ";
    cin >> order;
    cout << "\nHow many would you like to order (Input whole number only): " << fixed << showpoint << setprecision(2);
    cin >> orderQuantity;

    switch(order){
        case(1):
            cost = 4.99;
            break;
        
        case(2):
            cost = 5.99;
            break;

        case(3):
            cost = 6.99;
            break;

        case(4):
            cost = 2.99;
            break;

        case(5):
            cost = 1.99;
            break;
        
    }


    cout << "\nAwesome! Your order comes out to $" << cost * orderQuantity << "\n";
    cout << "Your order will be ready in: NEVER\n\n";

    /*
    #3 (10 Pts)
    Display a countdown from 10 to 1 with a line break after reach number
    Display "Blastoff!!!" after the countdown has ended
    */
    cout << "#3--------------------\n\n";
    //solution here
    for(int i = 10; i > 0; i--){
        cout << i << endl;
    }

    cout << "Blastoff!!!\n";
    cout << endl << endl;


    /*
    #4 (10 Pts)
    Write a loop that generates 10 random numbers
    Display each number as it is generated
    Calculate the product of the numbers (product means multiplication)
    Display the product of the numbers

    */
    cout << "#4--------------------\n\n";
    //solution here
    srand(time(nullptr));
    
    int sum = 0;

    for(int x = 10; x > 0; x--){
    int r1 = rand() % 100;
    cout << "Random number " << 11 - x << " generated | " << r1 << endl;
    sum = sum + r1;
    }

    cout << "The total of the all numbers generated is " << sum << endl << endl;





    /*
    #5 (10 Pts + 10 Extra credit points)
    Prompt the user to enter a dimension:number which will serve as a side length
    Display a square made of X's of the specified dimension
    Example (4)
    XXXX
    XXXX
    XXXX
    XXXX

    Extra Credit (5 Pts)
    Alter the pattern to alternate X's and O's
    Example (4)
    XOXO
    XOXO
    XOXO
    XOXO

    More Extra Credit
    Alter the pattern to alternate X's and O's where every row such that the items in the rows alternate X's and O's
    Example (4)
    XOXO
    OXOX
    XOXO
    OXOX


    */
    cout << "#5--------------------\n\n";
    //solution here


    int squareSize;

    bool xo = false;

    cout << "Please enter a square size for an alternating pattern of X's and O's (Whole intiger only)\n";
    cout << "Size: ";
    cin >> squareSize;

    if(squareSize > 0){

        for(int i = 1; i <= squareSize; i++){
            if(squareSize % 2 == 0){
                xo = !xo;
            }


            for(int x = 1; x <= squareSize; x++){


                if(xo){
                    cout << "O";
                    xo = false;
                }
                else{
                    cout << "X";
                    xo = true;
                }
                
            }
        cout << endl;
        }

    }else{
        cout << "Im sorry, but the square has to be an intiger greater than 0!!\n\n";
    }

    cout << endl << endl;

    



    return 0;
}
