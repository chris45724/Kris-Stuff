#include <vector>
#include <iostream>
#include <time.h>

using namespace std;





template <typename T>
void swap(T &a, T &b){
    //cout << "Swap " << a << " " << b << endl; // uncomment this for a big wall of text
    T c = a;
    a = b;
    b = c; 
}



void bubbleSort(vector<int> Values){
    bool notSorted = true;
    int loops = 0;
    int swaps = 0;
    while(notSorted){
        notSorted = false;
        for(int x = 0; x < Values.size(); x++){
            if(x+1 >= Values.size()){
                break;
            }
            if(Values[x] > Values[x+1]){
                notSorted = true;
                swap(Values[x],Values[x+1]);
                swaps++;
            }


        }
        
        if(notSorted){
            loops++;
        }
    }
    cout << "Total swaps for bubble sort: " << swaps << endl;
    cout << "Sorted list: ";
    for (int x : Values){
        cout << x << " ";
    }
    cout << endl;
}


void selectionSort(vector<int> Values){
    
    //int minValue = 0;
    int start = 0;
    bool notSorted = true;
    int swaps = 0;
    while(notSorted){
        int minValue = Values[start];
        notSorted = false;
        for(int x = start; x < Values.size(); x++){
            if(Values[minValue] > Values[x]){
                notSorted = true;
                minValue = x;
            }
        }
        if(notSorted){
        swaps++;
        swap(Values[minValue], Values[start]);
        start++;
        }
    }
    cout << "Total swaps for selection sort: " << swaps << endl;
    cout << "Sorted list: ";
    for (int x : Values){
        cout << x << " ";
    }
    cout << endl;
} 