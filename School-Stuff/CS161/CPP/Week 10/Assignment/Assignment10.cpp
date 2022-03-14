/*
Chris Howard
CS161
Assignment 10
*/

#include <vector>
#include <iostream>
#include <time.h>
/*
Assignments to do: #2, #3, #9
*/

using namespace std;

void assignment2();

void assignment3();

void assignment9();


int main(){
    assignment2();
    assignment3();
    assignment9();
    return 0;
}


/*
Assignment 9:
Make 2 identical arrays of atleast 20 intigers
Bubble sort 1 array, and keep track of swaps
Selection sort the other, and keep track of the swap
comapre the number of both types swaps
*/


void swap(int &a, int&b){
    //cout << "Swap " << a << " " << b << endl; // uncomment this for a big wall of text
    int c = a;
    a = b;
    b = c; 
}

// takes a vector of values, and prints the number of swaps it took to compleate
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

// takes a vector of values, and prints the number of swaps it took to compleate
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

void assignment9(){
    cout << "\n\n------Problem 9------\n\n";

    srand(time(nullptr));
    int listSize = ((rand() % 100) + 1);
    vector<int> Values;
    for(int x = 0; x < listSize; x++){
        Values.push_back(((rand() % 100) + 1));
    }


    cout << "The list has a size of " << listSize << endl;
    cout << "Unsorted list: ";
    for (int x : Values){
        cout << x << " ";
    }
    cout << endl;
    cout << "\n--Bubble Sort--\n";
    bubbleSort(Values);
    cout << "\n--Selection Sort--\n";
    selectionSort(Values);
}


/*
Assignment 2:
A lottery ticket player always plays the same 5 digit lucky number
let the player enter the number of the winning ticket, and see if it's one of the ones he plays
*/

void assignment2(){
    cout << "\n\n------Problem 2------\n\n";
    int ticket = 0;
    vector<int> playerTickets {13579,26791,26792,33445,55555,62483,77777,79422,85647,93121};
    cout << "Please enter the winning ticket:";
    cin >> ticket;
    bool winner = false;
    for(int x = 0; x < playerTickets.size(); x++){
        if(ticket == playerTickets[x]){
            winner = true;
            break;
        }
    }
    if(winner == true){
        cout << "You won the lottery!\n";
    }else{
        cout << "You did not win :(\n";
    }
}





/*
Assignment 3:
Same thing as problem 2 but with a binary search
*/



// Im reusing code from the lab because i just got off work, and i'm tired
int binarySearch(vector<int> Values, int target){
    int location = -1;
    bool found = false;
    int first = 0;
    int last = Values.size();
    int attepts = 0;
    while(((found == false) && (first <= last)) && (attepts < Values.size())){
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
        attepts++;
        
    }

    return location;
}

void assignment3(){
    cout << "\n\n------Problem 3------\n\n";
    int ticket = 0;
    vector<int> playerTickets {13579,26791,26792,33445,55555,62483,77777,79422,85647,93121};
    cout << "Please enter the winning ticket:";
    cin >> ticket;
    int winner = binarySearch(playerTickets, ticket);
    if(winner != -1){
        cout << "You won the lottery!\n";
    }else{
        cout << "You did not win :(\n";
    }
}



