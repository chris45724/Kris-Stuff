/*
Chris Howard
CS161
Assignment
*/

#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>




using namespace std;








/*
 #8 


 Write a function that simulates the tossing of a coin. 
 When you call the function, it should generate a random number in the range of 1 through 2. 
 If the random number is 1, the function should display “heads.” If the random number is 2, the function should display “tails.” 
 Demonstrate the function in a program that asks the user how many times the coin should be tossed, 
 then simulates the tossing of the coin that number of times.

*/

void coin(int quantity){
    // Problem 8



    srand(time(NULL));
    int coin = (rand() % 2) + 1;
    string face;

    for (int i = 1; i <= quantity; i++){
        int coin = (rand() % 100) + 1;



        /* // This is for debugging
        if ((coin % 2) == 0){
            coin2 = 2;
        } else {
            coin2 = 1;
        }
        */


        // to make more realistic flips?? It felt a little off without this
        if ((coin % 2) == 0){
            face = "heads";
        } else {
            face = "tails";
        }



        cout << "Coin " << i << " was " << face << endl;


        //cout << coin<< " " << coin2 << " | ";

    }
    //int coin = (rand() % 2) + 1;

    

    //return coin;




}

/*

Challenge 12

This is way too much text to import.

void getJudgeData() This gets a judge's (User input) vote.

void calcScore() This will calculate a score. will take 5 inputs, and drop both the highest, and lowest scores.

int findHighest() This will find the largest number in a list passed to it.

int findLowest() This will find the lowest number in a list passed to it.

*/

// This function takes a variable it changes, and the judge number
void getJudgeData(int &vote, int x){
    
    // the second int is so I can get the judges position: e.g. judge 1 , judge 2, etc...
    
    cout << "What score did judge " << x <<" provide: ";

        cin >> vote;

        cout << endl;

    while(cin.fail() || (vote < 0 || vote > 10)){
        cout << endl << "Invalid input\nplease provide a whole number that is between the range of 0-10\n";
        cin.clear();
        cin.ignore(255,'\n');
        cout <<  "What score did judge " << x <<" provide: ";
        
        cin >> vote;

        cout << endl;

    }



    

}

int findHighest(int votes[]){

    int largest = votes[0];

    for(int i = 0; i < 5; i++){
        if(votes[i] > largest){
            largest = votes[i];
            //cout << "Debug ping at " << i <<" With value of " << votes[i]<< endl;
        }


    }



    return largest;

}



int findLowest(int votes[]){
    //recycled from findHighest

   int smallest = votes[0];

    for(int i = 0; i < 5; i++){
        if(votes[i] < smallest){
            smallest = votes[i];
    
        }


    }


    return smallest;

}





void calcScore(int votes[]){


    int highest = findHighest(votes);
    int lowest = findLowest(votes);

    int votesForMath[7] = {votes[0], votes[1], votes[2], votes[3], votes[4], -highest, -lowest}; //arrays are a cheat code


    float sum = 0;
    for(int x = 0; x < 7; x++){
        sum += votesForMath[x];
    }

    float averageScore = (sum/3);

    //cout << "DEBUG: The sum of votes is " << sum << endl;

    //cout << "DEBUG: The average of votes is " << averageScore << endl;


    cout << "The Calculated score is " << averageScore << endl;




}






/*
Challenge 15

Hospitals

Display hospital stay: ask if inpatient, or outpatient

inpatient:
    Number of days at hospital
    The daily rate
    Hospital Medication charges
    Charges for services

outpatient:
    Charges for services
    Hospital Medication charges

Use two overloaded functions to calculate the total charges:
    One for inpatient
    One for outpatient
    
    --DO NOT ACCEPT NEGATIVE NUMBERS--


*/

// im lazy
void error(){
    cin.clear();
    cin.ignore(255,'\n');
    cout << "Invalid Responce\nPlease try again!\n\n";
}

//      inpatient
float hospitalCost(float medication, float services, int days, float rate){
    float cost = (rate * days) + (medication + services);



    return cost;
}

//      outpatient
float hospitalCost(float medication, float services){
    float cost = medication + services;
    return cost;
}



void valueGetter(string words, float &value){
    do{
        cout << words;
        cin >> value;
        if(cin.fail() || value < 0){
            error();
            cout << "Value must not be negative and must be a number\n";
            value = -1;
        }
    }while(cin.fail() || (value < 0));
    cout << endl;
}




void valueGetter(string words, int &value){
    do{
        cout << words;
        cin >> value;
        if(cin.fail() || value < 0){
            error();
            cout << "Value must not be negative and must be a whole number\n";
            value = -1;
        }
    }while(cin.fail() || (value < 0));
    cout << endl;
}







int main(){

    cout << fixed << showpoint << setprecision(2);
    cout << "Problem 8\n";
    
    int flips = 1;

    do {

        cout << "How many times would you like to flip a coin: ";
        cin >> flips;
        
        if(cin.fail()){
            cout << "Your input must be a whole integer: ";
            cin.clear();
            cin.ignore(255,'\n');
            cin >> flips;
            }


    }while(cin.fail());



    coin(flips);
    if (flips <= 0){
        cout << "No flips for you then\n";
    }


    //cout << "Test 1\n";

    cout << "\n\nProblem 12\n";

    //float vote1, vote2, vote3, vote4, vote5;

    cout << "\nJudge scores must be a whole number\n\n";



    /*

    // Old code; I did this, than realized an array was easier


    getJudgeData(vote1, 1);

    //cout<< endl << endl << score1; 
    // testing
    getJudgeData(vote2, 2);
    getJudgeData(vote3, 3);
    getJudgeData(vote4, 4);
    getJudgeData(vote5, 5);
    */


    //int votes[5] = {vote1, vote2, vote3, vote4, vote5};
    // array testing | will be used in calcScore()
    
    int votes[5] = {0, 0, 0, 0, 0};



    for(int x = 0; x < 5; x++){
        int y;
        getJudgeData(y,x+1);
        votes[x] = y;

        //cout << votes[x] << endl;
    }

    

    //cout << "DEBUG: The largest vote was: " << findHighest(votes) << endl;
    //cout << "DEBUG: The smallest vote was: " << findLowest(votes) << endl;


    

    calcScore(votes); 
















    cout << "\n\nProblem 15\n";
    cin.clear();
    cin.ignore(255,'\n');

    
    

    int stayType;
    do{
        stayType = 2; // sanity check
        cout << "Please press 0 for inpatient\nPlease press 1 for outpatien\n";
        cin >> stayType;

        
        if(cin.fail() || (stayType != 0 && stayType != 1)){
            error();
            stayType = 2;
        }


    }while(cin.fail() || (stayType != 0 && stayType != 1));

    if(stayType == 0){
        int days;
        float rate, services, medication;
        valueGetter("How many days were spent in the hospital: ", days);
        //cout << "DEBUG: Days spent in hospital was: " << days << endl;


        valueGetter("What is rate for staying at the hospital (Dollars per day) (provid in dollars): ", rate);
        //cout << "DEBUG: Daily rate for hospital is: " << rate << endl;


        valueGetter("How much was the hospital services fee (provid in dollars): ",services);
        //cout << "DEBUG: Hospital services fee is: " << services << endl;


        valueGetter("What did the medication cost (provid in dollars): ", medication);
        //cout << "DEBUG: Hospital mediccation charges is: " << medication << endl;

        //cout << "DEBUG: The hospital cost equation is: ( " << days << " [Days] * " << rate << " [Rate]) + " << services << " [Services] + " << medication << " [Medication]" << endl; 
        //cout << "DEBUG: Hospital total cost is: " << hospitalCost(medication, services, days, rate) << endl;

        cout << "Your total charge for staying at the hospital is $" << hospitalCost(medication, services, days, rate) << endl;
    }
    
    if(stayType == 1){
        float services, medication;


        valueGetter("How much was the hospital services fee (provid in dollars): ",services);
        //cout << "DEBUG: Hospital services fee is: " << services << endl;


        valueGetter("What did the medication cost (provid in dollars): ", medication);
        //cout << "DEBUG: Hospital mediccation charges is: " << medication << endl;


        //cout << "DEBUG: The hospital cost equation is: " << services << " [Services] + " << medication << " [Medication]" << endl; 
        //cout << "DEBUG: Hospital total cost is: " << hospitalCost(medication, services) << endl;

        cout << "Your total charge for staying at the hospital is $" << hospitalCost(medication, services) << endl;
    }
    
    
    return 0;
}






