/*
Chris Howard
1/12/21
CS161
programming lab week 2!


*/
/*
1) East coast sales devision
2) Sales tax
3) Robot memeory
*/



#include <iostream>

using namespace std;

int main()
{
    // Problem 1) East coast sales

    int eastCoastSale = 8600000000;

    cout << "\n\n\n";
    cout << "1) East coast sales\n"<<"\n";
    cout << "The East coast sales division will generate " << eastCoastSale * .58 << "$\n";


    // Problem 2) Sales Tax

    float saleForSalesTax = 95;
/*
    cout << "\n\n\ndebuging:" << "\n" << "saleForSalesTax -->" << saleForSalesTax
         << "\n" << "State tax --> " << saleForSalesTax*0.04
         << "\n" << "County tax --> " << saleForSalesTax*0.02;
*/

    cout << "\n\n\n";
    cout << "2) Sales Tax\n"<<"\n";
    cout << "The sales tax for a " << saleForSalesTax << "$ order is " << (saleForSalesTax * 0.04) + (saleForSalesTax * 0.02) << "$\n"
    << "This brings the total cost to " << saleForSalesTax + ((saleForSalesTax * 0.04) + (saleForSalesTax * 0.02)) << "$";



    cout << "\n\n\n";
    cout << "3) Robot\n"<<"\n";

    cout << "Size of char:" << sizeof(char) << endl;
    cout << "Size of int:" << sizeof(int) << endl;
    cout << "Size of float:" << sizeof(float) << endl;
    cout << "Size of double:" << sizeof(double) << endl;
}

