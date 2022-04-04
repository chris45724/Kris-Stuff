#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <time.h>

using namespace std;
/*
Chris Howard
CS162
Assignment
*/


/*
#7
write a template function called abs
abs - finds the absolute value of a number - template function
param1 - template - the number you want the absolute value of
return  - template - the positive version of the number
must use a template
*/
//YOUR CODE HERE

// Why does this work?		I think because abs is already a base function?
template <typename T>
T abs(T num){
	return num;
}

/* // Here's code to do the same thing. It's called abs2() to not conflict with abs()
template <typename T>
T abs2(T num){
	//return num;
	if (num < 0){
		T positive = num * num;
		num = positive / 2;
	}
	else{
		return num;
	}
}
*/





/*
#8
write a template function called factorial
  factorial - calculates the factorial of a specified number - template function
  param1 - template - the factorial that we want, in n!, it is the n
  return  - template - the factorial result
must use a template
*/
//YOUR CODE HERE
template <typename T>
T factorial(T num){
	// less than 0, and the output would be non real, and I don't want to think about that... If 0, than output 0
	
	if (num <= 0){
		return 0;
	}

	T output = 1;
	for(T x = 1; x <= num; x++){
		output = output * x;
	}
	return output;
}




	/*
	#2
	Write a function called endsWith7 that accepts an integer and returns a boolean
	param1 - the integer that you are analyzing
	The function should return true if the parameter ends with a 7
	The function should return false if the parameter does not end with a 7
	Test your function two times - Be sure that the output from the test is well-formatted
	*/
	//YOUR CODE HERE
bool endsWith7(int x){
	int y = x;
	while(y > 7){
		y = y - 10;
	}
	if((y%7) == 0){
		return true;
	} else {
		return false;
	}
}




/*
#3
Write a function called descendingArray which accepts an array
Param1 - The array to be examined
Param2 - The size of the array
The function will return true if the elements of the array are in descending order
The function will return false if the elements of the array are are not in descending order
Test your two times using the arrays below
Be sure that the output from the test is well-formatted
*/

bool descendingArray(int array[], int size){
	int previous = array[0];
	for(int x = 0; x < size; x++){
		if (previous < array[x]){
			return false;
			break;
		}
		previous = array[x];
	}
	return true;
}



/*
#4
Write a function called howMany() which accepts an array and two integers and returns an integer
Param1 - the array to search
param2 - an integer which is the size of the array
param3 - an integer that you are searching for in the array
return - the number of times that the integer is contained in the array
Test your two times using the arrays above
Be sure that the output from the test is well-formatted
*/

int howMany(int array[], int size, int target){
	int quantity = 0;
	for(int x = 0; x < size; x++){
		if (array[x] == target){
			quantity++;
		}
	}
	return quantity;
}



int main() {
	int num = -1;

    cout << "#0" << endl;
    /*
	#0
	Create a variable and initialize it to your name
	Create a variable and initialize it to today's date
	Print out the following output using your variables where applicable
	Name - MyName
	Date - TodaysDate
	CS 161 Review
	*/
	//YOUR CODE HERE

	string name = "Chris Howard";
	string date = "4/1/2022";
	cout << "Name: " << name << "\nDate: " << date << "\nCS 161 Review\n";


	cout << "\n#1" << endl;
	/*
	#1
	Write a program that repeatedly prompts the user to the password until the user enters, "Please"
	Count the number of attempts
	If the user does not get the password right in 3 attempts, then end the loop and display "Access Denied"
	If the user does enter the correct password, then end the loop and display "Access Granted"
	*/
	//YOUR CODE HERE
	
	string password = "Please";
	string guess = "banana";
	guess = password;
	while (guess != password){
		cout << "Please enter the password:";
		cin >> guess;
	}
	
	
	
	
	cout << "\n#2" << endl;
	/*
	#2
	Write a function called endsWith7 that accepts an integer and returns a boolean
	param1 - the integer that you are analyzing
	The function should return true if the parameter ends with a 7
	The function should return false if the parameter does not end with a 7
	Test your function two times - Be sure that the output from the test is well-formatted
	*/
	//YOUR CODE HERE
	num = 11;

	cout << num << " ends with 7: ";
	if (endsWith7(num)){
		cout << "Yes\n";
	} 
	else {
		cout << "No\n";
	}

	num = 2007;

	cout << num << " ends with 7: ";
	if (endsWith7(num)){
		cout << "Yes\n";
	} 
	else{
		cout << "No\n";
	}


	
	
	
	cout << "\n#3" << endl;
	/*
	#3
	Write a function called descendingArray which accepts an array
	Param1 - The array to be examined
  	Param2 - The size of the array
	The function will return true if the elements of the array are in descending order
	The function will return false if the elements of the array are are not in descending order
	Test your two times using the arrays below
	Be sure that the output from the test is well-formatted
	*/
	int myArray[] = {33,32,30,25,24,17,11,13,12,11,11,10,9,7,6,5,4,2,1,0,-6};//size 20
	int myOtherArray[] = {54,45,42,39,38,37,31,29,24,22,19,17,16,15,13,11,9,7,5,4,3,0,-2,-6,-7};//size 25
	//YOUR CODE HERE
	cout << "The array \"myArray\" is in decending order: ";
	if (descendingArray(myArray, 20)){
		cout << "Yes\n";
	} 
	else{
		cout << "No\n";
	}

	cout << "The array \"myOtherArray\" is in decending order: ";
	if (descendingArray(myOtherArray, 25)){
		cout << "Yes\n";
	} 
	else{
		cout << "No\n";
	}
	
	
    cout << "\n#4" << endl;
	/*
	#4
	Write a function called howMany() which accepts an array and two integers and returns an integer
	Param1 - the array to search
	param2 - an integer which is the size of the array
	param3 - an integer that you are searching for in the array
	return - the number of times that the integer is contained in the array
	Test your two times using the arrays above
	Be sure that the output from the test is well-formatted
	*/
	//YOUR CODE HERE

	//howMany()
	num = 11;
	cout << "The number " << num << " occurs in \"myArray\" " << howMany(myArray,20,num) << " times\n";
	cout << "The number " << num << " occurs in \"myOtherArray\" " << howMany(myOtherArray,20,num) << " times\n";
	
	
	
	cout << "\n#5" << endl;
	/*
	#5
	Given the parallel arrays below - find the students with a score greater than or equal to 70
	For each student with a score greater than or equal to 70, display the students name and the students score for each
	Example - Kent - 98
	Use a loop
	*/
	string names[] = {"Karl", "Luis", "Mary Sue", "Antonio", "Kendra", "Marquis", "Kent"};
	int scores[] = {69,82,100,62,90,84,98};
	//YOUR CODE HERE
	int sizeOfArray = 7;
	for(int x = 0; x < sizeOfArray; x++){
		if (scores[x] >= 70){
			cout << names[x] << " - " << scores[x] << endl;
		}
	}
	
	

	
	
	cout << "\n#6" << endl;
	/*
	#6
	Create a vector of integers
	Populate the vector with 25 random integers from 0 to 100
	Print out the values in the newly populated vector
	Print out the maximum value in the array
	*/
	//YOUR CODE HERE
	srand(time(nullptr));
	vector<int> coolVector;
	for(int x = 0; x < 25; x++){
		coolVector.push_back(rand()%100 + 1);
	}
	int previous = coolVector[0];
	cout << "The values in the vector are: ";
	for(int x : coolVector){
		cout << " " << x;
		if (previous < x){
			previous = x;
		}
	}
	cout << endl;
	cout << "The largest value in the vector is: " << previous << endl;

	
	cout << "\n#7" << endl;
	
	
	num = 6;
	cout << "abs of " << num << " is " << abs(num) << endl;

	num = (1 - 7);
	cout << "abs of " << num << " is " << abs(num) << endl;


	cout << "\n#8" << endl;
	
	
	num = 600; // lol overflow. I spent a good minute trying to figure this one out
	cout << "factorial of " << num << " is " << factorial(num) << endl;\
	cout << "^^ data overflow!\n";

	num = (1 - 70);
	cout << "factorial of " << num << " is " << factorial(num) << endl;

	num = (1);
	cout << "factorial of " << num << " is " << factorial(num) << endl;

	num = (5);
	cout << "factorial of " << num << " is " << factorial(num) << endl;

    return 0;
}//main
