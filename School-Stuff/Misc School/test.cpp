#include <iostream>

using namespace std;

// dynamicly change size of array

//template <typename T>
int arraySize(int *arr){
    return arr[3];

} 

template <typename T>
T appendArray(T *arr, T data , int size){
    return arr;
}

int main(){

    int *testArr;
    testArr = new int[5];
    for(int x; x<5; x++){
        testArr[x] = x;
    }
    cout << testArr[5] << '\n';


    cout << arraySize(testArr);


    //return 0;
}