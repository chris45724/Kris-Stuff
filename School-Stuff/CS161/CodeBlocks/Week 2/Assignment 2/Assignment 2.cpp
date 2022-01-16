// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    /* 
    
    1) Triangle
    
    2) Gas
    
    3) Tempature
    
    4) Soft Drink


    5)Stocks
    */









    /*  1) Make a triangle that looks like this
                  *
                 ***
                *****
               *******
    
    
    
    
    */
    cout << "1) Triangle\n";

    cout << "     *\n" << "    ***\n" << "   *****\n" << "  *******\n";

    /*
    2) Gas tank is 20 gallons
        mpg in city: 23.5
        mpg on hwy: 28.9
        calculate max distance for both mpg's
        a cars range is is calculated by multiplying the mpg by the tank size
    */

    int gasTank = 20;
    int mpgCity = 23.5;
    int mpgHwy = 29.8;

    cout << "\n\n"<< "2) Car miles per gallon\n";
    cout << "A car with a " << gasTank << " gallon gas tank\n"
        << "This car gets " << mpgCity << "miles to the gallon in city\n"
        << "This car gets " << mpgHwy << "miles to the gallon on a highway\n"
        << "\n\n" << "The max range of this car in a city is" << gasTank * mpgCity << " miles\n"
        << "The max range of this car on a highway is" << gasTank * mpgHwy << " miles\n";



    /*
    3) The average tempature in july
        New York City: 85 Degrees
        Denver: 88 Degrees
        Phoenix: 106 Degrees
        
        Calculate new average if tempatures are rased by 2%

        we will want to do this by going like ('Tempature' * 0.02) + Tempature
        */
        
    float nycTemp = 85;
    float denverTemp = 88;
    float phoenixTemp = 106;

    cout << "\n\n" << "3) Averange tempatures\n";

    cout << "The average tempatures for a few cities are:\n"
         << "  New York City: " << nycTemp << " degrees fahrenheit" << endl
         << "  Denver: " << denverTemp << " degrees fahrenheit" << endl
         << "  Phoenix: " << phoenixTemp << " degrees fahrenheit" << endl;
         
    cout << "\n" << "If the average tempature increased by 2%, The new temperatures would be:\n"
         << "  New York City: " << (nycTemp * 0.02) + nycTemp << " degrees fahrenheit" << endl
         << "  Denver: " << (denverTemp * 0.02) + denverTemp << " degrees fahrenheit" << endl
         << "  Phoenix: " << (phoenixTemp * 0.02) + phoenixTemp << " degrees fahrenheit" << endl;



    /*
    
    4) Soft drink survey found that 15% of its 16500 customers buy 1 or more energy drink per week
       58% of these customers prefer citris flavors
       Find the amount of customers who buy more than 1 per week
       Find the amount of customers who prefer citris flavors out of the people who buy more than 1 per week


       To find the aprox customers, we go (customers * .15) = moreOneWeek
       To find the amount of people who buy more than 1 a week, and prefer citris we go (moreOneWeek * .58)
    
    
    
    
    
    */

    int drinkCustomers = 16500;
    int moreOneWeek = (drinkCustomers * .15);

    cout << "\n\n" << "4) Energy drink\n";

    cout << "An energy drink sells to 16500 customers a week\n"
         << "The amount of customers who buy more than 1 energy drink are" << moreOneWeek << endl
         << "Of these people, " << moreOneWeek * .58 << " prefer citris flavors" << endl;



    /*
    5) Kathryn bought 750 stocks for 35$ per. She pays her broker a 2% commission

    Find the cost of the stocks alone
    Find the cost of the commission
    Find the total of both
    
    
    
    To find the cost of the stocks alone, you do 750*35
    The cost of the commission is 750*35*0.02
    The total is the sum of both
    
    */
    
    
    int totalStocks = 750 * 35;
    float commissionCost = totalStocks * 0.02;



    cout << "\n\n" << "5) Stock prices\n";

    cout << "Kathryn bought 750 shares for a total price of " << totalStocks << "$\n"
         << "She paid a broker" << commissionCost << "$ to buy the shares\n"
         << "In total she paid" << totalStocks + commissionCost << "$";

    cout << "\n\n";


}

