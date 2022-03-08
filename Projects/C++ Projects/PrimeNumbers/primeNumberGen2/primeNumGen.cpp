#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

/*
https://en.wikipedia.org/wiki/Sieve_of_Atkin <-- This is the method I used to generate prime numbers!


https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/



bool primeNumber(unsigned long long int number){
    bool IsPrime = true;
    for (unsigned long long int i = number; i > 0; i--){
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
    ofstream outputFile;
    outputFile.open("primeNumbers.txt");
    
    cout << "What number would you like to start at: ";
    cin >> startNumber;
    cout << endl;
    cout << "What number would you like to stop at: ";
    cin >> cycles;
    cout << endl;
    

    if(cin.fail()){
        cout << "\n----invalid input----\n";
        return 1;
    }
    cout << endl;
    cout << endl;

    
    cout << "---Running---\n";
    for (unsigned long long int i = (startNumber); i <= (cycles); i++){
        if(primeNumber(i)){
            outputFile << i << endl;
        } 
            
    }
    if (startNumber > cycles){
        cout << "Error\nThe first number is larger than the last number\n";
        return 1;
    }
    

    
    cout << "---Finished---\n";
    outputFile.close();

    
    return 0;
}
