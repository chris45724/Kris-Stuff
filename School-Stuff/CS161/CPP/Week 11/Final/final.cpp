#include <iostream>
#include <time.h>
#include <vector>

using namespace std;



bool endsWith7(int param1){
	int param2 = param1;
	while(param2 > 7){
		param2 = param2 - 10;
	}
	//cout << param1 << " into " << param2 <<"\n"<< param2<< " % 7 = " << param2%7 << endl;
	if((param2%7) == 0){
		return true;
	} else {
		return false;
	}
}





int howMany(int theArray[],int arraySize, int target){

	/*
	#3 - 10 Pts
	Write a function called howMany() which accepts an array and two integers and returns an integer
	Param1 - the array to search
	param2 - an integer which is the size of the array
	param3 - an integer that you are searching for in the array
	return - the number of times that the integer is contained in the array
	Test your two times - Be sure that the output from the test is well-formatted. I gave you two arrays to test on below.
	*/


	int quantity = 0;
	for(int x = 0; x < arraySize; x++){
		if(theArray[x] == target){
			quantity++;
		}
	}
	return quantity;


}




int main() {
	cout << "#0" << endl;		
	/*
	#0 - 5 Pts
	Create a variable and initialize it to your name
	Create a variable and initialize it to today's date
	Print out the following output using your variables where applicable
	Name - MyName
	Date - TodaysDate
	CS 161 Final
	*/


	string name = "Chris Howard";
	string date = "3/16/2022";
	cout <<"Name - " << name << "\n" << "Date - "<< date << "\nCS 161 Final\n"; 



	
	cout << "\n#1" << endl;		
	/*
	#1 - 5 Pts
	Write a program that repeatedly prompts the user to the password until the user enters, "shazam"
	*/
	
	string password = "aaaaaaaaaa";
	while(true){
		cout << "Please enter the password: ";
		cin >> password;
		if(password == "shazam"){
			cout << "Password Accepted\n";
			break;
		}
		else{
			cout << "Incorrect password\n";
		}
	}
	


	
	cout << "\n#2" << endl;

	
	cout << "1047 ends with 7: ";
	if(endsWith7(1047)){
		cout << "true\n";
	}else{
		cout << "false\n";
	}
	cout << "13 ends with 7: ";
	if(endsWith7(13)){
		cout << "true\n";
	}else{
		cout << "false\n";
	}	
	/*
	#2 - 10 Pts
	Write a function called endsWith7 that accepts an integer and returns a boolean
	param1 - the integer that you are analyzing
	The function should return true if the parameter ends with a 7
	The function should return false if the parameter does not end with a 7
	Test your function two times - Be sure that the output from the test is well-formatted
	*/

	
	cout << "\n#3" << endl;		
	/*
	#3 - 10 Pts
	Write a function called howMany() which accepts an array and two integers and returns an integer
	Param1 - the array to search
	param2 - an integer which is the size of the array
	param3 - an integer that you are searching for in the array
	return - the number of times that the integer is contained in the array
	Test your two times - Be sure that the output from the test is well-formatted. I gave you two arrays to test on below.
	*/
	int myArray[] = {3,2,3,5,4,7,11,23,13,1,2,4,5,8,10,12,13,8,7,6};//size 20
	int myOtherArray[] = {4,5,6,3,2,7,8,9,4,2,10,11,6,5,3,4,9,7,5,15,21,3,4,6,7};//size 25

	cout << "The number 3 occurs in 'myArray' " << howMany(myArray,20,3) << " times" << endl;
	//cout << "The number 1 occurs in 'myArray' " << howMany(myArray,20,1) << " times" << endl;
	cout << "The number 6 occurs in 'myOtherArray' " << howMany(myOtherArray,25,6) << " times" << endl;
	//cout << "The number 9000 occurs in 'myOtherArray' " << howMany(myOtherArray,25,9000) << " times" << endl;
	
	/* //To make testing easier VVV
	int number = 3;
	cout << "The number "<< number <<" occurs in 'myArray' " << howMany(myArray,20,number) << " times" << endl;
	cout << "The number "<< number <<" occurs in 'myOtherArray' " << howMany(myOtherArray,25,number) << " times" << endl;
	*/
	
	cout << "\n#4" << endl;		
	/*
	#4 - 10 Pts
	Given the array below - find the minimum value and the average value
	Display the minimum and average values
	Use a loop
	*/

	double theArray[] = {2.5,4.5,6.5,5.8,2.62,1.17,3.12,4.35,4.65,7.0,5.66,9.86,3.48};//size 13
	double min = theArray[0];
	double max = theArray[0];
	double sum = 0;
	int pos = 0;
	for(double x : theArray){
		if(min > x){
			min = x;
		}
		if(max < x){
			max = x;
		}
		sum += x;
	}
	cout << "Minimum value in 'theArray' :" << min <<" | average value in 'theArray' :" << sum/13 << endl;

	cout << "\n#5" << endl;	
	/*
	#5 - 10 Pts
	Given the parallel arrays below - display the names of the students with scores above 70
	Display the students name and the students score for each name in, names
	Example - Karl - 69
	Use a loop
	*/


	
	string names[] = {"Karl", "Luis", "Mary Sue", "Antonio", "Kendra", "Marquis"};
	int scores[] = {69,82,100,62,90,84};
	int arraySize = 6;
	cout << "The students who scored above a 70 are:\n";
	for(int x = 0; x < arraySize; x++){
		if(scores[x] > 70){
			cout << "Student: " << names[x] << " | Score: " << scores[x] << endl;
		}
	}
	cout << "\nThe students who did not score above a 70:\n";
	for(int x = 0; x < arraySize; x++){
		if(scores[x] <= 70){
			cout << "Student: " << names[x] << " | Score: " << scores[x] << endl;
		}
	}



	
	cout << "\n#6" << endl;	
	/*
	#6 - 10 Pts
	Create a vector of integers
	Add the values from scores to the vector - must use a loop to manually copy the values
	Print out the values in the newly populated vector
	*/
	vector<int> scores2;

	for(int x : scores){
		scores2.push_back(x);
	}
	for(int x : scores2){
		cout << x << endl;
	}

	return 0;
}//main
