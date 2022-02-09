/*
Chris Howard
CS 161 Midterm Practice
CS 161
*/


#include <iostream>
#include <time.h>

using namespace std;

int main() {


    /*
    #0
    Prompt the user to enter a number
    If the number was 7, then display "Good guess"
    If the number entered was not a 7, then display "Bad job"
    */
    cout << "#0--------------------\n\n";
    //solution here



    /*
    #1
    Prompt the user to enter a number
    If the number is odd, then display "Odd", otherwise display "Even"
    */
    cout << "#1--------------------\n\n";
    //solution here



    /*
    #2 (10 Pts)
    Prompt the user to enter a number corresponding to their selection given the following menu options
    Feel free to uncomment the text below to use for a menu prompt

    1. Mac & Cheese - 3.99
    2. Burrito - 5.99
    3. Bacon Sandwich - 5.99
    4. Popcorn - 1.99
    5. Cool Ranch Doritos - 1.99

    Once the user has selected an item, prompt the user to enter the quantity ordered

    Calculate the cost of the order
    Format the numeric portion to display two decimal places
    */
    cout << "#2--------------------\n\n";
    //solution here



    /*
    #3 (10 Pts)
    Display the odd numbers from 1 to 100
    */
    cout << "#3--------------------\n\n";
    //solution here



    /*
    #4 (10 Pts)
    Write a loop that generates 10 random numbers
    Display each number as it is generated
    Calculate the sum of the numbers
    Display the sum of the numbers

    */
    cout << "#4--------------------\n\n";
    srand(time(nullptr));

    
    int test1 = rand() % 100 + 1;
    int test2 = rand() % 100 + 1;
    int test3 = rand() % 100 + 1;
    int test4 = rand() % 100 + 1;


    cout << "Num 1:" << test1 << endl;
    cout << "Num 2:" << test2 << endl;
    cout << "Num 3:" << test3 << endl;
    cout << "Num 4:" << test4 << endl;



    //solution here



    /*
    #5 (10 Pts)
    Ask the user to enter an integer greater than 0
    Write a loop which calculates the factorial of a number
    Example 10:
    10! = 10*9*8*7*6*5*4*3*2*1
    Example 3
    3! = 3*2*1

    */
    cout << "#5--------------------\n\n";
    //solution here



    /*
    #6
    Prompt the user to enter a dimension which will serve as a height
    Display a pattern a right-triangle made of *s of the given height
    See example
    Example (4)
    *
    **
    ***
    ****

    */
    cout << "#6--------------------\n\n";
    //solution here



    return 0;
}
