/*
Chris Howard
CS161
Assignment 8 (9?)
*/
// Problems 1, 3, 4, 7, 10, 19


#include <vector>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

// Problem 1

/*
User will input 10 values into array, then the program will find the largest and smallest numbers in array
*/
void problem1(){
    int userArray[10];

    for(int x = 0; x < 10; x++){
        cout << "Provive a value for position " << x <<" in the array: ";
        cin >> userArray[x];
        cout << userArray[x] << endl;
    }
    
    int maxValue = userArray[0];
    for(int x : userArray){
        if (maxValue < userArray[x]){
            maxValue = userArray[x];
        }
    }
    int minValue = userArray[0];
    for(int x : userArray){
        if (minValue > userArray[x]){
            minValue = userArray[x];
        }
    }
    cout << "The maximum value for the array is " << maxValue << endl;
    cout << "The minimum value for the array is " << minValue << endl;

}
// End of problem 1


// Problem 3

// this function find the largest value in an array
// the function requires the input the array which you want to search, and the array's size
// the function returns the position of the largest value
int maxValueArray(const int Array[], int arraySize){
    int largestValue = Array[0];
    int valuePostion = 0;
    for(int x = 0; x < arraySize; x++){
        if (largestValue < Array[x]){
            largestValue = Array[x];
            valuePostion = x;
        }
    }
    return valuePostion;
}




/*
Program will use 2 parallel arrays to sort and quantify sales of salsa by flavor
Store the flavors on one list, and store the quantity sold on another list
Quantity sold will be input by user
*/


// this function find the smallest value in an array
// the function requires the input the array which you want to search, and the array's size
// the function returns the position of the smallest value
int minValueArray(const int Array[], int arraySize){
    int smallestValue = Array[0];
    int valuePostion = 0;
    for(int x = 0; x < arraySize; x++){
        if (smallestValue > Array[x]){
            smallestValue = Array[x];
            valuePostion = x;
        }
    }
    return valuePostion;
}


void problem3(){
    string salsaFlavors[5] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int salsaSold[5];
    for(int x = 0; x < 5; x++){
        cout << "How much " << salsaFlavors[x] << " salsa was sold: ";
        cin >> salsaSold[x];
    }
    cout << endl;
    cout << "List of salsa sold\n";
    for(int x = 0; x < 5; x++){
        if (salsaSold[x] == 1){
            cout << salsaFlavors[x] << " salsa sold: " << salsaSold[x] << " jar" << endl;
        } else {
            cout << salsaFlavors[x] << " salsa sold: " << salsaSold[x] << " jars" << endl;
        }
    }
    cout << endl;
    string mostSold = salsaFlavors[maxValueArray(salsaSold,5)];
    if (salsaSold[minValueArray(salsaSold,5)] == 1){
        cout << mostSold << " salsa sold the most at " << salsaSold[maxValueArray(salsaSold,5)] << " jars" << endl;
    } else {
        cout << mostSold << " salsa sold the most at " << salsaSold[maxValueArray(salsaSold,5)] << " jars" << endl;
    }

    string leastSold = salsaFlavors[minValueArray(salsaSold,5)];
    if (salsaSold[minValueArray(salsaSold,5)] == 1){
        cout << leastSold << " salsa sold the least at " << salsaSold[minValueArray(salsaSold,5)] << " jar" << endl;
    } else {
        cout << leastSold << " salsa sold the least at " << salsaSold[minValueArray(salsaSold,5)] << " jars" << endl;
    }

}

// End of problem 3



// Problem 4

/*
The program will accept 3 arguments: an array, the size of the array, and the number n
The function will display all of the variables larger than the number n
*/

// this checks to see if any number is larger than the number(n)
void largerThanN(int numberArray[], int arraySize, int n){
    for(int x = 0; x < arraySize; x++){
        if (numberArray[x] > n){
            cout << numberArray[x] << " is larger than " << n << endl;
        }
    }
}

void problem4(){
    int numberArray[3];
    int n = 0;
    cout << "Provide 3 numbers for an array\n";

    cout << "What is the first number: ";
    cin >> numberArray[0];

    cout << "What is the second number: ";
    cin >> numberArray[1];

    cout << "What is the third number: ";
    cin >> numberArray[2];

    cout << "What number do you want check if the array is larger than: ";
    cin >> n;
    cout << endl;
    largerThanN(numberArray,3,n);



}

// End of problem 4



// Problem 7

/*
Ask the user for a file name. assume the file contains random numbers, each on a seprate line. place the contents of the file into an array
display the following: smallest number, largest number, total of the numbers, average of the numbers
*/
int maxValueVector(vector<int> numbersVec){
    int largestValue = numbersVec[0];
    for(int x : numbersVec){
        if (largestValue < x){
            largestValue = x;
            
        }
    }
    return largestValue;
}

int minValueVector(vector<int> numbersVec){
    int smallestValue = numbersVec[0];
    for(int x : numbersVec){
        if (smallestValue < x){
            smallestValue = x;
            
        }
    }
    return smallestValue;
}

int totalVector(vector<int> numbersVec){
    int sum = 0;
    for(int x : numbersVec){
        sum = sum + x;
    }
    return sum;
}


void problem7(){
    string fileName;
    ifstream dataFile;

    cout << "What is the name of the file you would like to open: ";
    cin >> fileName;
    dataFile.open(fileName);
    if(dataFile.fail()){
        cout << "could not open file!" << endl;
    }

    int numCount = 0;
    int value;
    vector<int> numberVector;
    while(dataFile >> value){
        numCount++;
        numberVector.push_back(value);
    }
    int largestNumber = maxValueVector(numberVector);
    int smallestnumber = minValueVector(numberVector);
    int sum = totalVector(numberVector);
    float avg = sum / numCount;

    cout << "There are " << numCount << " numbers in the file" << endl;
    cout << "The smallest number in the file is " << smallestnumber << endl;
    cout << "The largest number in the file is " << largestNumber << endl;
    cout << "The sum of all the numbers in the file is " << sum << endl;
    cout << "The average of all the numbers in the file is " << avg << endl;
}

// End of problem 7



// Problem 10

/*
The local DMV wants a program to grade written portions of exams.
The exam has 20 questions. Store the answers in an array
Ask the user for their answers to the questions and compare them to the answers
A user only has to get 15 out of the 20 questions right to pass
Show the total number of correct questions
Show the total number missed questions
Show a list of the question numbers of the missed questions
*/
void problem10(){
    char correctAwnsers[20] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    char userAwnsers[20];
    int answeredCorrectly;
    for(int x = 0; x < 20; x++){
        cout << "What is your answer for problem " << x+1<< ": ";
        cin >> userAwnsers[x];
        
        while(cin.fail() || (((userAwnsers[x] != 'A') && (userAwnsers[x] != 'B')) && ((userAwnsers[x] != 'C') && (userAwnsers[x] != 'D')))){
            cout << "Invalid input!\nPlease provide a new input\n";
            cout << "What is your answer for problem " << x+1<< ": ";
            cin >> userAwnsers[x];
        }
    
    }

    for(int i = 0; i < 20; i++){
        if(correctAwnsers[i] == userAwnsers[i]){
            answeredCorrectly++;
        }
    }
    cout << endl;

    if(answeredCorrectly == 20){
        cout << "You got every questions right!\n";
    }else if(answeredCorrectly == 0){
        cout << "You have no correct questions!\n";
    }else{
        cout << "You got " << answeredCorrectly << "/20 correct!\n";
    }
    if(answeredCorrectly >= 15){
        cout << "You passed!\n";
    }else{
        cout << "You failed!\n";
    }
    
    cout << endl;

    for(int i = 0; i < 20; i++){
        if(correctAwnsers[i] == userAwnsers[i]){
            cout << "Question " << i+1 << " correct" << endl;
        }else{
            cout << "Question " << i+1 << " incorrect" << endl;
        }  
    }
    
}

// End of problem 10



// Problem 19

/*
This program will read responses from a file and load it into an array or vector, and then ask the user for a question.
the program will provide a responce from the array/vector to the users question
*/


//This function finds a file called 8_ball_responses.txt and saves each line in it to a vector
//The function will return a random string from the vector
string magicBallResponses(){
    srand(time(nullptr));
    ifstream responseFile;
    responseFile.open("8_ball_responses.txt");
    string currentLine;
    vector<string> responseVector;
    string currentWord;
    int counter = 0;
    while(responseFile){
        getline(responseFile, currentWord);
        responseVector.push_back(currentWord);
        counter++;
    }
    
    
    int randomInt = rand() % counter;
    return responseVector[randomInt];
}
void problem19(){
    string question;
    cout << "Ask magic 8 ball a question\n";
    cin >> question;
    cout << magicBallResponses();
}

// End of problem 19

int main(){
    problem1();
    problem3();
    problem4();
    problem7();
    problem10();
    problem19();


    return 0;
}