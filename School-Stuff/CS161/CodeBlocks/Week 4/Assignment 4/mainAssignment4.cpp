#include <iostream>
#include <iomanip>
#include <string>

/*
Chris Howard
Assignment 4
CS161
*/

/*

1)  Write a program that asks the user to enter two numbers.
    The program should use the conditional operator to
    determine which number is the smaller and which is the larger


2)  Write a program that asks the user to enter a number
    within the range of 1-10. Use a switch statement to display
    the Roman numeral version of that number

    Input validation: Do not accept a number less than 1 or greater than 10

4)  The area of a rectangle is length times its width. Write a program that asks the
    length and width of two rectangles. The program should tell the user which rectangle
    has the greater area, or if the areas are the same.


16) Write a program that asks for the names of three runners and the time
    it took each of them to finish the race. The program should display who
    came in first, second, and third place.



*/




using namespace std;

int main()
{


    // Challenge 1


    float number1, number2, number3, number4;


    cout << endl << "---Challenge 1)---" << endl;
    cout << "---Which number is smaller?---"<< endl << endl;


    cout << "Please input 2 numbers to compare which number is larger" << endl;
    cout << "What is the first number: ";
    cin >> number1;
    cin.ignore();

    cout << "What is the second number: ";
    cin >> number2;
    cin.ignore();

    if (number1 == number2)
    {
        cout << "\nThe first number" << " (" << number1 << ") and the second number"  << " (" << number2 << ") are equal" << endl;
    }
    else if (number1 > number2)
    {
        cout << "\nThe first number" << " (" << number1 << ") is greater than the second number"  << " (" << number2 << ")" << endl;
    }
    else if (number1 < number2)
    {
        cout << "\nThe first number" << " (" << number1 << ") is less than the second number"  << " (" << number2 << ")" << endl;
    }
    else
    {
        cout << "An error has occurred!" << endl;
    }







    /*

    2)  Write a program that asks the user to enter a number
        within the range of 1-10. Use a switch statement to display
        the Roman numeral version of that number
    */
    int number5;

    cout << endl << "---Challenge 2)---" << endl;
    cout << "---Roman numerals using switch?---"<< endl << endl;


    cout << "Please type a number between 1 and 10 to convert to a roman numeral" << endl;
    cout << "What is your number: ";
    cin >> number5;
    cin.ignore();

    switch(number5)
    {
    case 1:
        cout << "The roman numeral for " << number1 << " is I" << endl;

        break;

    case 2:
        cout << "The roman numeral for " << number1 << " is II" << endl;

        break;

    case 3:
        cout << "The roman numeral for " << number1 << " is III" << endl;

        break;

    case 4:
        cout << "The roman numeral for " << number1 << " is IV" << endl;

        break;

    case 5:
        cout << "The roman numeral for " << number1 << " is V" << endl;

        break;

    case 6:
        cout << "The roman numeral for " << number1 << " is VI" << endl;

        break;

    case 7:
        cout << "The roman numeral for " << number1 << " is VII" << endl;

        break;

    case 8:
        cout << "The roman numeral for " << number1 << " is VIII" << endl;

        break;

    case 9:
        cout << "The roman numeral for " << number1 << " is IX" << endl;

        break;

    case 10:
        cout << "The roman numeral for " << number1 << " is X" << endl;

        break;

    default:
        cout << "The number " << number1 << " is an invalid choice" << endl;
    }

    /*
4)  The area of a rectangle is length times its width. Write a program that asks the
    length and width of two rectangles. The program should tell the user which rectangle
    has the greater area, or if the areas are the same.
    */



    cout << endl << "---Challenge 4)---" << endl;
    cout << "---Comparing rectangles---"<< endl << endl;


    cout << "Please provide 2 rectangles to compare" << endl;
    cout << endl <<"What is the length of the first rectangle: ";
    cin >> number1;
    cin.ignore();

    cout << "What is the height of the first rectangle: ";
    cin >> number2;
    cin.ignore();

    cout << endl << "The area of the first rectangle is " << number1*number2 << endl;

    cout << endl <<"What is the length of the second rectangle: ";
    cin >> number3;
    cin.ignore();

    cout << "What is the height of the second rectangle: ";
    cin >> number4;
    cin.ignore();

    cout << endl << "The area of the second rectangle is " << number2*number3 << endl;



    if (number1*number2 != number3*number4)
    {
        cout << endl << "The first rectangle (area:" << number1*number2 << ") is ";

        number1*number2 > number3*number4 ? cout << "greater than " : cout << "less than ";

        cout << "the second rectangle (area:" << number3*number4 << ")" << endl;

    }
    else
    {
        cout << endl << "The first rectangle (area:" << number1*number2 << ") is equal to ";
        cout << "the second rectangle (area:" << number3*number4 << ")" << endl;
    }












    /*
16) Write a program that asks for the names of three runners and the time
    it took each of them to finish the race. The program should display who
    came in first, second, and third place.
    */


    string name1, name2, name3;
    int nameSize;




    cout << endl << "---Challenge 16)---" << endl << fixed << showpoint << setprecision(2);
    cout << "---Runner time and position---"<< endl << endl;


    cout << "Please provide the name of 3 runners, and their time to compare their finishing position" << endl;

    // First Runner ---------------------------

    cout << endl << "What is the name of the first runner: ";
    getline(cin, name1);
    //cin.ignore();

    cout << endl << "What is the time of the first runner: ";
    cin >> number1;
    cin.ignore();

    cout << endl << name1 << " | " << number1 << endl;

    // Second Runner ---------------------------

    cout << endl << "What is the name of the second runner: ";
    getline(cin, name2);
    //cin.ignore();

    cout << endl << "What is the time of the second runner: ";
    cin >> number2;
    cin.ignore();

    cout << endl << name2 << " | " << number2 << endl;

    // Third Runner ---------------------------

    cout << endl << "What is the name of the thrid runner: ";
    getline(cin, name3);
    //cin.ignore();

    cout << endl << "What is the time of the thrid runner: ";
    cin >> number3;
    cin.ignore();

    cout << endl << name3 << " | " << number3 << endl;

   // setw size maker!

    if(name1.length() > name2.length())
    {
        if(name1.length() > name3.length())
        {
            nameSize = name1.length();
        }
        else
        {
            nameSize = name3.length();
        }
    }
    else
    {
      if(name2.length() > name3.length())
        {
            nameSize = name2.length();
        }
        else
        {
            nameSize = name3.length();
        }
    }



    // This is where it happens




    if ((number1 < number2) && (number2 < number3)) // 1 > 2 > 3
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name1 << " | " << number1 << endl
        << "    2) " << setw(nameSize) <<  name2 << " | " << number2 << endl
        << "    3) " << setw(nameSize) <<  name3 << " | " << number3 << endl;
    }
    else if((number1 < number3) && (number3 < number2)) // 1 > 3 > 2
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name1 << " | " << number1 << endl
        << "    2) " << setw(nameSize) <<  name3 << " | " << number3 << endl
        << "    3) " << setw(nameSize) <<  name2 << " | " << number2 << endl;
    }
    else if((number2 < number1) && (number1 < number3)) // 2 > 1 > 3
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name2 << " | " << number2 << endl
        << "    2) " << setw(nameSize) <<  name1 << " | " << number1 << endl
        << "    3) " << setw(nameSize) <<  name3 << " | " << number3 << endl;
    }
    else if((number2 < number3) && (number3 < number1)) // 2 > 3 > 1
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name2 <<  " | " << number2 << endl
        << "    2) " << setw(nameSize) <<  name3 <<  " | " << number3 << endl
        << "    3) " << setw(nameSize) <<  name1 <<  " | " << number1 << endl;
    }
    else if((number3 < number1) && (number1 < number2)) // 3 > 1 > 2
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name3 << " | " << number3 << endl
        << "    2) " << setw(nameSize) <<  name1 << " | " << number1 << endl
        << "    3) " << setw(nameSize) <<  name2 << " | " << number2 << endl;
    }
    else if((number3 < number2) && (number2 < number1)) // 3 > 2 > 1
    {
        cout << "\nPositions for the runners are:\n"
        << "    1) " << setw(nameSize) <<  name3 << " | " << number3 << endl
        << "    2) " << setw(nameSize) <<  name2 << " | " << number2 << endl
        << "    3) " << setw(nameSize) <<  name1 << " | " << number1 << endl;
    }
    else
    {
        cout << "An error has occurred!" << endl;
    }










    return 0;
}
