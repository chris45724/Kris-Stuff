/*
Chris Howard
CS161
Vector Lab
*/

// I wanted to try and get better at comments, so please let me know how I did, and what I can improve

#include <vector>
#include <time.h>
#include <iostream>

using namespace std;


// This function will print the vector provided to it
void printVector(vector<int> input){
    for( int i : input){
        cout << i << endl;
    }
}

// Finding the maximum value of a provided vector
int maxVecValue(vector<int> input){
    int maxValue = input[0]; // initializing maxValue and setting it to the first value in the vector
    for( int i : input){
        
        if (i > maxValue){ // once a value larger than the previous max value is found, reassign maxValue to the new value
            maxValue = i;
        }
    }
    return maxValue;
}


int main(){
    vector<int> randomInt; // initializing the vector we will fill with random values
    srand(time(nullptr));
    
    for(int i = 0; i < 1000; i++){ // Generating and filling the randomInt vector with random intigers
        randomInt.push_back(rand()%(rand()%100000)); // Using a double rand() function for fun
    }
    
    printVector(randomInt);
    cout << "\nThe largest number in the vector is " << maxVecValue(randomInt) << endl;
    return 0;
}