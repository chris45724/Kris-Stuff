#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

void swap(int &a, int&b);

//void vectorToArray(vector<int> &myVector[], int &myArray[]);


int main(){
    srand(time(nullptr));

    long long int arraySize = (10000);

    //int testArray[arraySize];

    vector<long long int> testArray;

    /*for (long long int x = 0; x < arraySize; x++){
        testArray[x] = rand() % 100;
        //cout << testArray[x] << " ";
    }*/ 
    
    for (long long int x = 0; x < arraySize; x++){
        testArray.push_back(rand() % 10000);
        //cout << testArray[x] << " ";
    }

    cout << endl << endl;
    cout << "Running\n";

    bool notSorted = true;
    vector<int> swapOps;
    while (notSorted){
        int swaps = 0;
        notSorted = false;
        //cout << "\n\nStarting loop " << swapOps.size()+1 << endl << endl;
        for(int x = 0; x < arraySize; x++) {
            if(x+1 >= arraySize){
                break;
            }
            if (testArray[x+1] < testArray[x]){
                notSorted = true;
                for (int i = 0; i < arraySize; i++){
                    /*if(x == i){
                        cout << "[" <<testArray[i] << "] ";
                        cout << "[" <<testArray[i+1] << "] ";
                        i++;
                    }else{
                        cout << testArray[i] << " ";
                    }*/
                }
                //cout << endl;
                //cout << "On swap " << swaps+1 << ": " << testArray[x] << ", " << testArray[x+1] << " swapped\n";
                swaps++;
                swap(testArray[x+1],testArray[x]);
                //cout << endl;
                //cout << endl;
                
            }
        }
        if(notSorted){
            swapOps.push_back(swaps);
        }else{
            cout << "Finished sorting\n";
        }
        
    }
    cout << endl << endl;
    cout << "It took " << swapOps.size() << " loops\n";
    int accumulator = 0;
    for(int x = 0; x < swapOps.size(); x++){
        //cout << "For loop " << x+1 << " the amount of swaps was " << swapOps[x] << endl;
        accumulator += swapOps[x];
    }
    cout << "\nTotal required swaps was " << accumulator << endl << endl;
    /*for (int x = 0; x < arraySize; x++){
        cout << testArray[x] << " ";
    }*/
    cout << endl;
    system ("pause");
    
    return 0;
}



void swap(int &a, int&b){
    int c = a;
    a = b;
    b = c; 
}

