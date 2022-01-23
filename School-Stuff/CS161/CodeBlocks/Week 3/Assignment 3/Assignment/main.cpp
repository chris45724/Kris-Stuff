#include <iostream>
#include <iomanip>


/*
    Chris Howard
    Assignment 3
    CS161

*/
/*
    We will be completing specific programming challenges from the text book.
    The challenges are:
        #2) There are three seating categories at a stadium.
            For a softball game, Class A seats cost $15, Class B seats cost $12, and Class C seats cost $9.
            Write a program that asks how many tickets for each class of seats were sold, then displays the amount of income generated from ticket sales.
            Format your dollar amount in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed.

        #3) Write a program that asks for five test scores. The program should calculate the average test score and display it.
            The number displayed should be formatted in fixed-point notation, with one decimal point of precision


        #6) A cookie recipe calls for the following ingredients:
            � 1.5 cups of sugar
            � 1 cup of butter
            � 2.75 cups of flour

            The recipe produces 48 cookies with this amount of the ingredients.
            Write a program that asks the user how many cookies he or she wants to make,
            then displays the number of cups of each ingredient needed for the specified number of cookies.



        #9) A bag of cookies holds 30 cookies.
            The calorie information on the bag claims there are 10 �servings� in the bag and that a serving equals 300 calories.
            Write a program that asks the user to input how many cookies he or she actually ate,
            then reports how many total calories were consumed.



        #13) Write a program that will convert U.S. dollar amounts to Japanese yen and to Euros,
             storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
             To get the most up-to-date exchange rates, search the Internet using the term �currency exchange rate�.
             If you cannot find the most recent exchange rates, use the following:

                1 Dollar=98.93 Yen
                1 Dollar=0.74 Euros

             Format your currency amounts in fixed-point notation, with two decimal places of precision,
             and be sure the decimal point is always displayed.

*/




using namespace std;

int main()
{


    //Project 2)
    //Quantity of A,B,C tickets
    int quantATicket;
    int quantBTicket;
    int quantCTicket;

    //cin.ignore();
    cout << "Challenge 2)"<< endl << "--Softball tickets" << endl << endl;
    cout << "How many A class tickets were purchased? ";
    cin >> quantATicket;
    cout << quantATicket << " A class tickets sold\n";
    cin.ignore();


    cout << "How many B class tickets were purchased? ";
    cin >> quantBTicket;
    cout << quantBTicket << " B class tickets sold\n";
    cin.ignore();

    cout << "How many C class tickets were purchased? ";
    cin >>quantCTicket;
    cout << quantCTicket << " C class tickets sold\n";
    cin.ignore();

    cout << "The total price of A class tickets was: " << quantATicket * 15 << "$" << endl;
    cout << "The total price of B class tickets was: " << quantBTicket * 12 << "$" << endl;
    cout << "The total price of C class tickets was: " << quantCTicket * 9 << "$" << endl << endl;
    cout << "The total price of all tickets sold is: " << (quantATicket * 15) + (quantBTicket * 12) + (quantCTicket * 9) << "$" << endl;


    //Project 3)
    //Test
    float test1,test2,test3,test4,test5;




    cout << endl << endl << "Challenge 3)"<< endl << "--Test score average" << endl << endl;


    cout << "Please enter the score for the first test: ";
    cin >> test1;
    cin.ignore();
    cout << endl;

    cout << "Please enter the score for the second test: ";
    cin >> test2;
    cin.ignore();
    cout << endl;

    cout << "Please enter the score for the thrid test: ";
    cin >> test3;
    cin.ignore();
    cout << endl;

    cout << "Please enter the score for the forth test: ";
    cin >> test4;
    cin.ignore();
    cout << endl;

    cout << "Please enter the score for the fifth test: ";
    cin >> test5;
    cin.ignore();
    cout << endl;

    cout << endl << "The average score is: " << fixed << showpoint << setprecision(2) << (test1+test2+test3+test4+test5) / 5;









    //Project 6)


    /*

            A cookie recipe calls for the following ingredients:
                � 1.5 cups of sugar
                � 1 cup of butter
                � 2.75 cups of flour

            The recipe produces 48 cookies with this amount of the ingredients.
            Write a program that asks the user how many cookies he or she wants to make,
            then displays the number of cups of each ingredient needed for the specified number of cookies.

    */




    cout << endl << endl << "Challenge 6)"<< endl << "--cooking recipe" << endl << endl;

    float cupsOfSugar = 1.5;
    float cupsOfButter = 1.0;
    float cupsOfFlour = 2.75;
    float quantCookiesMake;

    cout << "How many cookies would you like to make? " << fixed << showpoint << setprecision(2) ;
    cin >> quantCookiesMake;
    cin.ignore();


    cout << "You will need " << cupsOfSugar * (quantCookiesMake/48) << " cups of sugar " << endl;
    cout << "You will need " << cupsOfButter * (quantCookiesMake/48) << " cups of butter " << endl;
    cout << "You will need " << cupsOfFlour * (quantCookiesMake/48) << " cups of flour " << endl;




    // project 9)


    cout << endl << endl << "Challenge 6)"<< endl << "  More cookies!?" << endl << endl;

    /*
    A bag of cookies holds 30 cookies.
    The calorie information on the bag claims there are 10 �servings� in the bag and that a serving equals 300 calories.
    Write a program that asks the user to input how many cookies he or she actually ate,
    then reports how many total calories were consumed.
    */


    // each cookies is 300/3 calories! that's 100 calories per cookie

    float cookiesAte;


    cout << "How many cookies did you eat?";

    cin >> cookiesAte;

    cout << fixed << noshowpoint << setprecision(0) << "You consumed " << cookiesAte * 100 << " calories!" << endl;









    // project 13)

    /*

    Write a program that will convert U.S. dollar amounts to Japanese yen and to Euros,
    storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
    To get the most up-to-date exchange rates, search the Internet using the term �currency exchange rate�.
    If you cannot find the most recent exchange rates, use the following:

                1 Dollar=98.93 Yen
                1 Dollar=0.74 Euros

    Format your currency amounts in fixed-point notation, with two decimal places of precision,
    and be sure the decimal point is always displayed.


    */


    cout << endl << endl << "Challenge 13)"<< endl << "  Exchange rates" << endl << endl;

    // I'm using the exchange rates provided to me by the text book aa


    float EUROS_PER_DOLLAR = 0.74;
    float YEN_PER_DOLLAR = 98.93;
    float dollars;


    cout << "How many dollars for conversion?: " << fixed << showpoint << setprecision(2);
    cin >> dollars;
    cin.ignore();

    cout << dollars << " Dollars are " << dollars * EUROS_PER_DOLLAR << " Euros when converted" << endl;
    cout << dollars << " Dollars are " << dollars * YEN_PER_DOLLAR << " Yen when converted" << endl;
    cout << endl << endl << endl;






















}
