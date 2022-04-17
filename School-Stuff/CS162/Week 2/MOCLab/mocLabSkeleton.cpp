/*
Chris Howard
CS162
MOC Lab
*/



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
    
    int sum = 0;
    for(int x; x<size;x++){
        sum += ptr[x];
    }
    return (float(sum)/float(size));

}//function


// For some reason, I could not make a for loop inside the mode() function, so I had to make it here
// If you happen to see why I couldn't declare 'x', please let me know, it's been stumping me
void arrayZeroer(int *arr, int size){
    for(int position = 0; position < size; position++){
        arr[position] = 0;
    }
}

/*
mode - returns the mode of an array received as a parameter
param1 - int* - a pointer to an integer. An pointer to an integer array
param2 - int - size - the size of the array
return - int - the mode value in the array
an array called freq is allocated - elements are initialized to zero
a nested loop is used to count the number of times that index i is the same value as index j
The maximum value in freq is used to access the value stored in the array received as a parameter
*/
int mode(int *ptr, int size) {
    //return 1;
    //declare a pointer to an integer and allocate memory to a new array
	//YOUR CODE HERE
    int *freq = nullptr;
    freq = new int[size];

    //init array elements to zero
	//YOUR CODE HERE
    arrayZeroer(freq, size);

    /*
    // error: ‘x’ was not declared in this scope || WHY? Why isn't it declaring

    for(int x = 0; x < size; x++){
        freq[x] = 0;
    }
    */
    /* // AGAIN... I don't get it
    int x = 0; // <--- It's declared right here
    while(x < size){
        freq[x] = 0;
        x++
    }
    */ 

    //a nested loop is used to count the frequency or values in the array
    //frequency is incremented when the value of index i is the same as the value of index j
	//YOUR CODE HERE
    for(int searchIndex = 0; searchIndex < size; searchIndex++){
        for(int targetIndex = 0; targetIndex < size; targetIndex++){
            if (ptr[searchIndex] == ptr[targetIndex]){
                freq[searchIndex]++;
                //cout << ptr[searchIndex] << " Hit " << freq[searchIndex] << " Times\n";
            }
        }
    }
    


    //uncomment to test frequency table
    //printArr(freq, size);

    //max oriented variables
	//YOUR CODE HERE
    int maxVal =  0;

    //find the max in freq
    //keep track of index and value
	//YOUR CODE HERE
    // why does it work now? I must've done somthing stupid somewhere
    for(int x = 0; x < size; x++){
        if (freq[maxVal] < freq[x]){
            maxVal = x;
            //cout << "\nNew maxVal: " << ptr[maxVal] << ":" << freq[maxVal] << endl;
            
        }
    }

    //if maxVal is 1 then there is no mode
	//YOUR CODE HERE
    
    if(freq[maxVal] == 1){
        return 0;
    }




	
	//free dynamically allocated memory & set pointer to nullptr
	//I DID NOT DO THIS IN RHE SOLUTION VIDEO BUT YOU NEED TO
    freq = nullptr;
    delete freq;

    //return
	//YOUR CODE HERE
	return ptr[maxVal];

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
        //arr[i] = rand()%5;
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
