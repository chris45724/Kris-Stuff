/*
Chris Howard
CS161
Binary Search
*/


#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


// This function will read a vector of values, and search for a target number
// this function returns the position in the vector of the target number
// if the number does not exist in the vector, it will return a -1
int linearSearch(vector<int> Values, int target);


// This function will read a vector of values, and search for a target number
// this function returns the position in the vector of the target number
// if the number does not exist in the vector, it will return a -1
int binarySearch(vector<int> Values, int target);



int main(){

    vector<int> Values;
    ifstream valueFile;
    int target;
    valueFile.open("searchLabValues.txt");
    cout << "What number would you like to search for: ";
    cin >> target;
    while (cin.fail()){
        cout << "Input not accepted\n";
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "Please provide a new number: ";
        cin >> target;
    }

    
    if (valueFile.fail()){
        cout << "The value file could not be opened\n";
        return 1;
    }
    int tempNumber;
    while (valueFile >> tempNumber){
        Values.push_back(tempNumber);
        //cout << "Vector size:" << Values.size() << " Number:" << tempNumber << endl;
    }
    cout << endl << "------ Linear Search ------" << endl;
    int index = linearSearch(Values , target);
    cout << "Linear index location:" << index << endl;
    cout << endl << "------ Binary Search ------" << endl;
    index = binarySearch(Values , target);
    cout << "Binary index location:" << index << endl;

    
    
    return 0;
}

int linearSearch(vector<int> Values, int target){
    int location = -1;
    int attempts = 0;
    bool found = false;
    
    for (int x  = 0; x < Values.size(); x++){
        //cout << Values[x] << endl;
        attempts++;
        if(Values[x] == target){
            location = x;
            found = true;
            break;
        }
    }

    cout << "Linear search used " << attempts << " attempts\nTotal list size is " << Values.size() << endl;

    return location;
}

int binarySearch(vector<int> Values, int target){
    int location = -1;
    int attempts = 0;
    bool found = false;
    int first = 0;
    int last = Values.size();
    
    while(((found == false) && (attempts <= Values.size()) && (first <= last))){
        attempts++;
        int search = ((last - first) / 2 + first);
        if(target == Values[search]){
            found = true;
            location = search;
            break;
        } else if (target > Values[search]){
            first = search;
        } else if (target < Values[search]){
            last = search;
        }
        
    }

    cout << "Binary search used " << attempts << " attempts\nTotal list size is " << Values.size() << endl;

    return location;
}