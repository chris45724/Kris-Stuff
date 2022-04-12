#include <iostream>

using namespace std;

//Document this function
//YOUR CODE HERE
void printArr(int* ptr, int size) {
    //for loop is used to print the values in ptr
    for(int i  = 0;i<size;i++) {
        cout << *(ptr+i) << " ";
    }//for
    cout << endl;
}//function


/*
mean - returns the mean from an array received as a parameter
param1 - int* - a pointer to an integer. An pointer to an integer array
param2 - int - size - the size of the array
return - double - the resulting division of sum/count
*/
double mean(int *ptr, int size) {
	//YOUR CODE HERE

}//function



/*
mode - returns the mode of an array received as a parameter
param1 - int* - a pointer to an integer. An pointer to an integer array
param2 - int - size - the size of the array
return - int - the mode value in the array
an array called freq is allocated - elements are initialized to zero
a nested loop is used to count the number of times that index i is the same value as index j
The maximum value in freq is used to access the value sored in the array received as a parameter
*/
int mode(int *ptr, int size) {
    //declare a pointer to an integer and allocate memory to a new array
	//YOUR CODE HERE


    //init array elements to zero
	//YOUR CODE HERE


    //a nested loop is used to count the frequency or values in the array
    //frequency is incremented when the value of index i is the same as the value of index j
	//YOUR CODE HERE


    //uncomment to test frequency table
    //printArr(freq, size);

    //max oriented variables
	//YOUR CODE HERE


    //find the max in freq
    //keep track of index and value
	//YOUR CODE HERE


    //if maxVal is 1 then there is no mode
	//YOUR CODE HERE
	
	//free dynamically allocated memory & set pointer to nullptr
	//I DID NOT DO THIS IN RHE SOLUTION VIDEO BUT YOU NEED TO


    //return
	//YOUR CODE HERE
	return 0;

}//function


int main()
{
    //get size
    const int SIZE = 50;


    //create an array pointer called, arr, to an integer array of the specified size
    int* arr = new int[SIZE];

    //assign random values from 0 to 100 to arr
    for(int i = 0;i<SIZE;i++) {
        arr[i] = rand()%100;
    }//for

    //print arr
    cout << "Print array" << endl;
    printArr(arr, SIZE);

    //testing functions
    cout << "---Function Testing Results---" << endl;
    cout << "mean is: " << mean(arr, SIZE) << endl;
    cout << "mode is: " << mode(arr, SIZE) << endl;

    //clean up pointers
    delete [] arr;
    arr = nullptr;

    return 0;
}//main
