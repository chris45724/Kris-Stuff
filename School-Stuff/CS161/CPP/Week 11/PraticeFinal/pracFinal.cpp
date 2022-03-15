#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

//1

void problem1(){
  /*
  #1
  Write a loop that prints out the odd numbers from 1 to 99
  */
  cout << "Problem 1\n";

  for(int x = 0; x < 100; x++){
    if((x % 2) == 1){
      cout << x << " ";
    }
  }
  cout << endl;

}

//2

void problem2(){
  /*
  #2
  Ask the user to enter a number, n
  Print out the sum of the numbers from 1 to n
  Must use a loop
  */
  int number = 0;
  cout << "Problem 2\n";

  cout << "Please provide a number: ";
  cin >> number;
  while(cin.fail()){
    cout << "Invalid input!\n";
    cin.clear();
    cin.ignore(255,'\n');
    cout << "Please provide a number: ";
    cin >> number;
  }
  int sum = 0;
  for(int x = 0; x <= number; x++){
    sum += x;
  }
  cout << "The total of all number between 1 and " << number << " is " << sum << endl;
}

//3

bool divByThree(int value){
  if((value % 3) == 0){
    return true;
  }
  else{
    return false;
  }
}

void problem3(){
  /*
  #3
  Write a function called divByThree() that accepts an integer and returns a boolean
  The function should return true if the parameter is divisible by three - example 3, 6, 9, etc
  The function should return false if the parameter is not divisible by three
  Test your function
  */

  cout << "Problem 3\n";
  int number = 0;
  cout << "Please provide a number to divide by 3: ";
  cin >> number;
  while(cin.fail()){
    cout << "Invalid input!\n";
    cin.clear();
    cin.ignore(255,'\n');
    cout << "Please provide a number: ";
    cin >> number;
  }
  if(divByThree(number)){
    cout << "The number is divisible by 3\n";
  } else{
    cout << "The number is not divisible by 3\n";
  }


}

//4

bool arrayContains(int array1[], int arraySize, int target){

  for(int x = 0; x < arraySize; x++){
    if(array1[x] == target){
      return true;
    }
  }
  return false;
  



}


void problem4(){
  /*
  #4
  Write a function called arrayContains() that accepts an array of integers, the size of the array and the value that you are looking for
  The function will return true if the value is found, and false if it is not
  Test your function
  */

  cout << "Problem 4\n";

  int theArray[] = {22,40,65,58,42,1};
  int size = 42;
  int target;
  cout << arrayContains(theArray,size,target);

}

//5

void problem5(){
  /*
  #5
  Given the array below - find the minimum and maximum value
  Display the minimum and maximum values
  Use a loop
  */

  cout << "Problem 5\n";
  int theArray[] = {22,40,65,58,42,1,12,35,45,7,56,96,58,45,21,16,58,41};
  int smallest = theArray[0];
  int largest = theArray[0];
  int position = 0;
  for(int x : theArray){
    if(x < smallest){
      smallest = theArray[position];
    }
    if(x > largest){
      largest = theArray[position];
    }
    position++;
  }
  cout << "The largest number in the array is: " << largest << "\nThe smallest number in the array is: " << smallest << endl;
}

//6

void problem6(){
  
  /*
  #6
  Given the array below - find the average value
  Display the values in the array that are greater than the average value
  Use a loop
  */
  

  cout << "Problem 6\n";
  int theOtherArray[] = {23,14,76,89,80,11,23,74,53,42,72,40,66,34,26,28,7};
  float count = 0;
  float sum = 0;

  for(int x : theOtherArray){
    sum += x;
    count++;
    //cout << count << " ping\n";
  }
  //cout << "Sum of all numbers: " << sum << "\nCount of numbers in array: " << count << endl;
  float average = sum/count;
  //cout << average;


  cout << "All numbers over " << average << " in the list are: ";
  for(int x : theOtherArray){
    if(x > average){
      cout << x << " ";
    }
  }
  cout << endl;
}

//7

void problem7(){
  /*
  #7
  Create a vector of integers
  Add the values from theOtherArray to the vector - must use a loop to manually copy the values
  */
  int theOtherArray[] = {23,14,76,89,80,11,23,74,53,42,72,40,66,34,26,28,7};

  vector<int> aVector;

  for(int x : theOtherArray){
    aVector.push_back(x);
  }
  /*
  for(int x : aVector){
    cout << x << " ";
  }
  cout << endl;
  */

}

//8

int arrayRange(int array[], int size){
  int min = array[0];
  int max = array[0];

  for(int x = 0; x < size; x++){
    if(array[x] < min){
      min = array[x];
    }
    if(array[x] > max){
      max = array[x];
    }

  }
  int range = max - min;
  return range;

}


void problem8(){
  /*
  #8
  Write a function called arrayRange() that accepts an array of integers as a parameter and returns the range of the values in the array
  Range is max - min
  */


  int theArray[] = {22,40,65,58,42,1};
  int size = 5;
  cout << arrayRange(theArray, size);


}


int main() {

  problem1();
    
  problem2();

  problem3();

  problem4();
  
  problem5();

  problem6();

  problem7();

  problem8();
  

    return 0;
}//main
