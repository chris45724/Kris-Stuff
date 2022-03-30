/*
YOUR CODE HERE
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
EQ - determines if quantities are equal
param1 - template -  a -quantity 1
param2 - temmplate - b - quantity 2
return  - boolean - true if the quantities are equal, false if they are not
equal means less than to 10e-7 difference
*/
template <typename T>
bool EQ(T x, T y) {
    return (fabs(x-y)) < 10e-7;
}



/*
isOdd - determines if a number is odd - template function
param1 - template - x - number to be evaluated as odd
return  - boolean - true means it is odd, false means it is even
must use a template
*/
//YOUR CODE HERE





/*
maxof - returns the greater of two quantities
param1 - template -  x - quantity 1
param2 - temmplate -  y - quantity 2
return  - template - the greater of the two params
must use a template
*/
//YOUR CODE HERE




/*
isPrime - determines if a number is prime - template function
param1 - template - number to be evaluated as prime
return  - boolean - true means it is prime, false means it is a composite number
must use a template
*/
//YOUR CODE HERE




//function templates
void testFunctions();
void assertTrue(int, string);


int main() {

    //call unit tests
    testFunctions();

  return 0;
}//main


/*
testFunctions - calls a bunch of template functions found at the top of this file
no params
return  - void - nothing is returned
output is generated using cout
*/
void testFunctions() {
    cout << "Begin testing--------------\n";

    cout << "Testing isOdd--------------\n";
    assertTrue(EQ(isOdd(5), true), "Test isOdd(5) == true");
    assertTrue(EQ(isOdd(8), false), "Test isOdd(9) == false");
    assertTrue(EQ(isOdd(-4), false), "Test isOdd(-4) == false");
    assertTrue(EQ(isOdd(123), true), "Test isOdd(123) == true");
    
    cout << "Testing maxof --------------\n";
    assertTrue(EQ(maxof(45,30), 45), "Test maxof(45,30) == 45");
    assertTrue(EQ(maxof(11, 99), 99), "maxof(11, 99) == 99");
    assertTrue(EQ(maxof(7.3, 5.9), 7.3), "maxof(7.3, 5.9) == 7.3");
    assertTrue(EQ(maxof(-6, 6), 6), "maxof(-6, 6) == 6");

    cout << "Testing isPrime--------------\n";
    assertTrue(EQ(isPrime(5),true), "Test isPrime(5) == true");
    assertTrue(EQ(isPrime(9),false), "Test isPrime(9) == false");
    assertTrue(EQ(isPrime(17),true), "Test isPrime(17) == true");
    assertTrue(EQ(isPrime(27),false), "Test isPrime(27) == false");
    
}//function


/*
assertTrue - prints output for unit tests
param1 - int - predicate - returned from EQ macro - indicates pass or fail in function
param2 - string - the root of the testing message
return  - void - nothing is returned
used in testing - called frequently from testFunctions()
*/
void assertTrue(int predicate, string message) {
	cout <<left << setw(32) <<message;
	if (predicate)
		cout << "PASSED\n";
	else
		cout << "FAILED\n";
}//function



