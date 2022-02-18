/*
Chris Howard
Guess a number lab
CS161
*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

# ifndef EQ
# define EQ(A, B) (fabs(A - B) < 10e-7)
# endif


void assertTrue(int predicate, string message) {
	cout <<left << setw(32) <<message;
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

double rectArea(int);
double rectArea(int, int);
bool isPrime(int);
double factorial(int);


int main() {


  cout << "Testing rectArea--------------\n";
	assertTrue(EQ(rectArea(10),100), "Test rect(10) == 100");
	assertTrue(EQ(rectArea(11),121), "Test rect(11) == 121");

	cout << "Testing rectArea overload--------------\n";
	assertTrue(EQ(rectArea(5, 6),30), "Test rect(5, 6) == 30");
	assertTrue(EQ(rectArea(11, 9),99), "Test rect(11, 9) == 99");

  cout << "Testing isPrime--------------\n";
	assertTrue(EQ(isPrime(5),true), "Test isPrime(5) == true");
	assertTrue(EQ(isPrime(9),false), "Test isPrime(9) == false");
  assertTrue(EQ(isPrime(17),true), "Test isPrime(17) == true");
  assertTrue(EQ(isPrime(27),false), "Test isPrime(27) == false");

  cout << "Testing factorial--------------\n";
	assertTrue(EQ(factorial(5),120), "Test factorial(5) == 120");
	assertTrue(EQ(factorial(9),362880), "Test factorial(9) == 362880");

  return 0;
}


/*
rectArea - finds the area of a square
param1 - int side length - should be greater than 0
return  - returns a double
*/
double rectArea(int x) {


	if (x > 0){
		double area = x * x;
		return (area);
	}
	else {
		return 0;
	}
    
}

/*
rectArea - finds the area of a rectangle - overloaded function
param1 - int side length - should be greater than 0
param2 - int side length - should be greater than 0
return  - returns a double
*/
double rectArea(int x, int y) {

	if (x > 0 || y > 0 )
	{
		double area = x * y;
    	return area;
	}
	else{


		
		return 0;


	}
}

/*
isPrime - determines if a number is prime
param1 - int number to be evaluated
return  - returns a boolean - true means it is prime, else false
*/
bool isPrime(int x) {


	if(x < 0) {
		x = -x;
	} else if (x == 0) {
		return false;
		//cout << "Failed 0\n";
	}

	for (int i = 2; i < x; i++)
	{

		if ((x % i) == 0){
			//cout << i << " Failed\n";
			return false;

		}
		else{
		}
		

	}

	


    return true;
}

/*
factorial - calculated the factorial of a number
param1 - int the factorial that we want
return  - returns a double - the factorial result
*/
double factorial(int x) {

	int calc = 1;

	for(int i = 1; i <= x; i++){
		calc = calc * i;
	}

	double product = calc;
	//cout << calc;

  return calc;
}










