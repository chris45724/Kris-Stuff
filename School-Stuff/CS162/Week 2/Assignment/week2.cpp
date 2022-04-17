/*
Chris Howard
CS162
Week 2
*/

#include <iostream>

using namespace std;


/*
This function just clears the cin.fail() flag
*/
void clear(){
    cin.clear();
    cin.ignore(255,'\n');
}


/*
This function will prompt the user if they input invalid data, it will then try to get valid data from the user
variables:
    Data - This is a template data type to allow it to work with any type of data, this varable is passed by reference and will overwrite the origianal
    response - This takes a string that the function will print to the terminal every time. This should be instructions for what the user should input
    limit - This limits how many times the function will run
*/
template <typename T>
void responseFail(T &data, string respose, int limit = 20){
    while((limit > 0) && (cin.fail())){
        clear();
        cout << "Invalid response!\n";
        cout << respose;
        cin >> data;
    }
}


/* ----- 1 -----
Array Allocator:    
Write a function that dynamically allocates an array of integers. 
The function should accept an integer argument indicating the number of elements to allocate. 
The function should return a pointer to the array.
*/
int* arrayAllocator(int size){
    int* array = nullptr;
    array = new int[size];
    return array;
}


void problem1(){
    cout << " ---- Problem 1 ----\n";
    int size = 5;
    int* array = arrayAllocator(size);
    for(int x = 0; x < size; x++ ){
        array[x] = rand()%10;
    }
    for(int x = 0; x < size; x++ ){
        cout << array[x] << " ";
    }
    cout << endl;
}


/*  ----- 2 -----
Test Scores #1:
Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores. 
Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. 
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with appropriate headings.
Use pointer notation rather than array notation whenever possible.
    
Input Validation: Do not accept negative numbers for test scores.
*/


void Sswap(int &a, int &b){
    int c = a;
    a = b;
    b = c; 
}

void arraySort(int array[], int size){
    bool sorted = false;
    int minimum = 0;
    int place = 0;
    while(sorted == false){
        sorted = true;
        minimum = place;
        for(int x = place; x < size; x++){
            if (array[minimum] > array[x]){
                minimum = x;
                sorted = false;
            }
        }
        Sswap(array[minimum],array[place]);
        place++;

    }


}
void arrayAverage(int arr[], int size){
    float sum = 0;
    for(int x = 0; x<size;x++){
        sum += arr[x];
    }
    cout << "The average score is " << (sum/size) << "\n";
}


template <typename T>
T* testScores(int size){
    T* scores = nullptr;
    scores = new T[size];
    for(int x = 0; x<size; x++){
        scores[x] = 0;
    }
    cout << "Please input testscores:\n";
    T input;
    for(int x = 0; x<size; x++){
        cout << "   What is the score of test " << x+1 << ": ";
        cin >> input;
        responseFail(input,"Please re-input the score: ");
        while(input < 0){
            cout << "   What is the score of test " << x+1 << ": ";
            cin >> input;
            responseFail(input,"Please re-input the score: ");
        }
        scores[x] = input;
    }
    

    return scores;
}


void problem2(){
    cout << " ---- Problem 2 ----\n";
    int size = 0;
    cout << "How many scores would you like to processes: ";
    cin >> size;
    responseFail(size, "How many scores would you like to processes: ");
    int* testArray = testScores <int> (size);
    arraySort(testArray,size);
    cout << endl;
    cout << "The scores in sorted order are\n";
    for(int x = 0; x<size;x++){
        cout << (x+1) << " : "<< testArray[x] << endl;
    }
    cout << '\n';
    arrayAverage(testArray,size);
}


/*  ----- 5 -----
Pointer Rewrite:
The following function uses reference variables as parameters.
Rewrite the function so it uses pointers instead of reference variables, 
then demonstrate the function in a complete program.
*/
int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
void problem5(){
    cout << " ---- Problem 5 ----\n";
    int *x = nullptr;
    int *y = nullptr;
    int a = 26;
    int b = 30;
    x = &a;
    y = &b;

    cout << "Problem 5: " << doSomething(x,y) << endl;
}


/*  ----- 10 -----
Reverse Array:
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a copy of the array, except that the element values should be reversed in the copy. 
The function should return a pointer to the new array. 
Demonstrate the function in a complete program.
*/
int* reverseArray(int *arr, int size){
    int *newarr = nullptr;
    newarr = new int[size];
    for(int x = 0; x < size; x++){
        newarr[x] = arr[(size - 1) - x];
    }
    return newarr;
}
void problem10(){
    cout << " ---- Problem 10 ----\n";
    int size = 10;
    int *array = nullptr;
    array = new int[size];
    cout << "Array: ";
    for(int x = 0; x < size; x ++){
        array[x] = rand()%100;
        cout << array[x] << " ";
    }
    cout << endl;
    int *newarr = nullptr;
    newarr = reverseArray(array,size);
    cout << "reversed: ";
    for(int x = 0; x < size; x ++){
        cout << newarr[x] << " ";
    }
    cout << endl;
}



int main(){
    problem1();
    problem2();
    problem5();
    problem10();


    return 0;
}