/*
Chris Howard
CS162
Week 3
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

/*
EQ - determines if quantities are equal
Param1 - template -  a
Param2 - temmplate - b
Return  - boolean - true if the quantities are equal, false if they are not
Equal means less than to 10e-7 difference
*/
template <typename T>
bool EQ(T x, T y) {
    return (fabs(x-y)) < 10e-7;
}




//function templates
void testFunctions();
void assertTrue(int, string);
int cstringlength(const char*);
bool cStringEQ(const char*, const char*);
int cStringCompare(const char*,const char*);


int main() {

    //call unit tests
    testFunctions();

  return 0;
}//main


/*
cstringlength - determines the length of a c-string
Param1 - const c-string - str - pointer to a char array
Return  - integer - the length of the c-string
Number of characters are counted until we reach the null terminator
Use a loop
DO NOT USE ANY LIBRARY FUNCTIONS
*/
//YOUR CODE HERE
int cstringlength(const char *str){
    int size = 0;
    //int x = 0;
    while(str[size] != '\0'){
        //cout << str[size] << endl;
        size++;
    }
    return size;
}


/*
cStringEQ - determine if two c-strings are equal
Param1 - const c-string - str1 - pointer to an char array
Param1 - const c-string - str2 - pointer to an char array
Return  - boolean - return 1 if the two strings are equal, 0 if they are not
Each character is compared for equality
Use a loop
DO NOT USE ANY LIBRARY FUNCTIONS
*/
//YOUR CODE HERE
bool cStringEQ(const char* str1, const char* str2){
    int size = cstringlength(str1);
    if (size !=  cstringlength(str2)){
        return false;
    }
    
    for(int x = 0; x <= size; x++){
        if(str1[x] != str2[x]){
            return false;
        }
    }
    
    return true;
}



/*
cStringCompare - compare two c-strings
Param1 - const c-string - str1 - pointer to an char array
Param2 - const c-string - str2 - pointer to an char array
Return - int - return 0 if the two strings are equal
Return 1 if the first argument is greater than the second
Return -1 if the second argument is greater than the first
Each character is compared for equality
Use a loop
DO NOT USE ANY LIBRARY FUNCTIONS
*/
//YOUR CODE HERE
int cStringCompare(const char* str1, const char* str2){
    int score1 = 0;
    int score2 = 0;
    int size1 = cstringlength(str1);
    int size2 = cstringlength(str2);
    if (size1 != size2){
        if (size1 > size2){
            return 1;
        }
        return -1;
    }
    if (cStringEQ(str1,str2)){
        return 0;
    }

    for(int x = 0; x < size1; x++){
        if (str1[x] > str2[x]){
            score1++;
        }else if(str1[x] < str2[x]){
            score2++;
        }
    }
    if (score1 > score2){
        return 1;
    }
    return -1;

}




/*
TestFunctions - calls a bunch of template functions found at the top of this file
No params
Return  - void - nothing is returned
Output is generated using cout
*/
void testFunctions() {
    cout << "Begin testing--------------\n";

    cout << "Testing cstringlength--------------\n";
    assertTrue(EQ(cstringlength("0123456789"), 10), "Test cstringlength('0123456789') == 10");
    assertTrue(EQ(cstringlength("slippy"), 6), "Test cstringlength('slippy') == 6");
    assertTrue(EQ(cstringlength("slappy"), 6), "Test cstringlength('slappy') == 6");
    assertTrue(EQ(cstringlength("sampsonite"), 10), "Test cstringlength('sampsonite') == 10");


    cout << "Testing cStringEQ --------------\n";
    assertTrue(EQ(cStringEQ("cat", "cat"), true), "Test cStringEQ('cat', 'cat') == true");
    assertTrue(EQ(cStringEQ("cat", "cats"), false), "Test cStringEQ('cat', 'cats') == false");
    assertTrue(EQ(cStringEQ("cat", "Cat"), false), "Test cStringEQ('cat', 'Cat') == false");
    assertTrue(EQ(cStringEQ("7", "seven"), false), "Test cStringEQ('7', 'seven') == false");
    assertTrue(EQ(cStringEQ("IN", "in"), false), "Test cStringEQ('IN', 'in') == false");



    cout << "Testing cStringCompare--------------\n";
    assertTrue(EQ(cStringCompare("hat", "hat"),0), "Test cStringCompare('hat', 'hat') == 0");
    assertTrue(EQ(cStringCompare("hat", "hats"),-1), "Test cStringCompare('hat', 'hats') == -1");
    assertTrue(EQ(cStringCompare("cat", "hat"),-1), "Test cStringCompare('cat', 'hat') == -1");
    assertTrue(EQ(cStringCompare("Hat", "hat"),-1), "Test cStringCompare('Hat', 'hat') == -1");
    assertTrue(EQ(cStringCompare("hat", "Hat"),1), "Test cStringCompare('hat', 'Hat') == 1");
}//function


/*
AssertTrue - prints output for unit tests
Param1 - int - predicate - returned from EQ macro - indicates pass or fail in function
pParam2 - string - the root of the testing message
Return  - void - nothing is returned
Used in testing - called frequently from testFunctions()
*/
void assertTrue(int predicate, string message) {
	cout <<left << setw(48) <<message;
	if (predicate)
		cout << "PASSED\n";
	else
		cout << "FAILED\n";
}//function

