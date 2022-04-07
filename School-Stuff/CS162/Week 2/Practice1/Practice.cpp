#include <iostream>
#include <random>
#include <time.h>
using namespace std;


int randish(int max){
    //srand(time(nullptr));
    int x = rand()% max + 1;
    return x;
}

template <typename T>
T* arrayPushback(T* arrptr, T value){
    //T x[] = {arrptr, value};
    //cout << "arrayMaker: " << x[0];

    //arrptr = *x;
    return x;
    
}

int main(){
    srand(time(nullptr));
    srand(time(nullptr) * ((rand()%5000) + 321));
    int num = 20;
    //cout << "Please provide a number: ";
    //cin >> num;
    
    for(int x = 0; x < num; x++){
        cout << x + 1 << ": " << randish(num) << "\n";
    }

    int arr[] = {1,2,5,6};
    int* arrptr = arr;
    //int* arrptr = nullptr;
    
    arrayMaker(arrptr, 10);
    //cout << "\nArray 3: " << arrptr[0] << endl;
    cout << endl;
       

    int* intptr = &num;

 

    cout << "Pointer ID: " << intptr << "\nPointer Value: " << *intptr << endl << endl;

    *intptr = 11;
    cout << "Pointer ID: " << intptr << "\nPointer Value: " << *intptr << endl << endl;
    
    
    return 0;
}