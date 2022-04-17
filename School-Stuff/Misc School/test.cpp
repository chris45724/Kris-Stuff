#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>


using namespace std;

// dynamicly change size of array

//template <typename T>
void swapArray(int *arr[],int a, int b){
    int c = a;
    arr[a] = arr[b];
    arr[b] = arr[c];
    
}
template <typename T>
void arraySort(T* array[], int size){
    bool sorted = false;
    int minimum = 0;
    int place = 0;
    while(place < size){
        minimum = place;
        for(int x = place; x < size; x++){
            if (array[minimum] > array[x]){
                minimum = x;
                sorted = false;
            }
        }
        cout << "swapping " << array[minimum] << " with "  << array[place] << endl;
        swapArray(array,minimum,place);
        place++;
        //cout << "Sorted : " << sorted << endl;

    }


}



int main(){
    srand(time(nullptr));
    int size = 20;
    int* array[size];
    for(int x = 0; x < size; x++){
        *array[x] = (rand()%40+1);
        cout << array[x] << " ";
    }
    cout << '\n';
    arraySort(array,size);
    for(int x = 0; x < size; x++){
        cout << array[x] << " ";
    }
    cout << '\n';

}