/*
We will be attempting to find prime numbers!

lets go
*/




#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
//#include "bigint-library-master/bigint.h"

using namespace std;


//void WholeQuotents(int);

bool primeNumber(int number){
    bool IsPrime = true;
    for (int i = number; i > 0; i--){
        //cout << i << endl;
        //cout << (number % i) << endl;
        if ( ((number % i) == 0) && ((i < number) && (i > 1)) ){
            IsPrime = false;
            break;
        }
    }
    return IsPrime;
}



int main(){
    
    unsigned long long int cycles = 0;
    unsigned long long int startNumber = 0;
    //time_t currentTime = time(0);
    char log = 'n';
    char timing = 'y';
    //opens file to write to
    ofstream outputFile;
    outputFile.open("PrimeNumbers.txt");
    
    // gets user input for operation
    cout << "What number would you like to start at: ";
    cin >> startNumber;
    cout << endl;
    cout << "How many cycles would you like to run: ";
    cin >> cycles;
    cout << endl;
    cout << "Would you like to write to console\nWriting to console is slow\n[y]es [n]o: ";
    cin >> log;
    cout << endl;
    if (log != 'y'){
        cout << "Would you like to save timing info in file?\n[y]es [n]o: ";
        cin >> timing;
    }
    

    if(cin.fail() || ( (log != 'y') && (log != 'n') ) ){
        cout << "\n----invalid input----\n";
        return 1;
    }
    cout << endl;
    cout << endl;

    outputFile << "All prime numbers between " << startNumber << " and " << startNumber + cycles << endl << "C++ version\n";
    
    int startTime = time(NULL); // saving current time for calculating time taken
    
    
    if(log == 'y'){ //outputs prime numbers to console and file
        cout << "---Running---";
        for (int i = (startNumber); i <= (cycles + startNumber); i++){
            
            if(primeNumber(i)){
                cout << "  " << i << "  Is a prime number | Calculated in " << (time(NULL) - startTime) << " seconds\n";
                outputFile << i << "    | Calculated in " << (time(NULL) - startTime) << " seconds" << endl;
            }   
        }
    }
    else if( (log == 'n') && (timing == 'n') ){
        cout << "---Running---";
        for (int i = (startNumber); i <= (cycles + startNumber); i++){
            if(primeNumber(i)){
                outputFile << i << endl;
            } 
        }
    }
    else{   // just outputs to file | Written as an if/else to allow code to run faster
        cout << "---Running---";
        for (int i = (startNumber); i <= (cycles + startNumber); i++){
            if(primeNumber(i)){
                outputFile << i << "    | Calculated in " << (time(NULL) - startTime) << " seconds" << endl;
            } 
            
        }
    }

    
    cout << "---Finished!---\n";
    outputFile << "Finnished successfully after " << (time(NULL) - startTime)<< " seconds" << endl;
    outputFile.close();
    cout << "Press any key then enter to close: ";
    string close="";
    cin >> close;

    
    return 0;
}


