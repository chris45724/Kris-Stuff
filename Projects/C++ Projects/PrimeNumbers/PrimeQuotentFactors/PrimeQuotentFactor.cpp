#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <vector>


using namespace std;

vector<unsigned long long int> primeNumberGenerator(unsigned long long int finalNumber=10000, unsigned long long int startNumber = 1);

bool isPrimeNumber(int number);

vector<unsigned long long int> factorFinder(unsigned long long int numbers);

void primeFileGenerator(vector<unsigned long long int> primeNumbers);

vector<unsigned long long int> primeFileReader();


vector<unsigned long long int> bruteForcer(vector<unsigned long long int> primeNumbers);
/*
Write prime numbers to file to refernce later
ask user if they want to generate a diffrent list
*/




int main(){
    srand(time(nullptr));
    vector<unsigned long long int> primeNumbers = primeFileReader();
    char regenrate = 'n';
    cout << "Would you like to generate new list of prime numbers?\n[y]es [n]o: ";
    cin >> regenrate;
    while(cin.fail() || ((regenrate != 'y') && (regenrate != 'n'))){
        cout << "\n\nInvalid input!\n\n";
        cout << "Would you like to generate new list of prime numbers?\n[y]es [n]o: ";
        cin >> regenrate;
    }
    
    
    if (regenrate == 'y'){
        unsigned long long int startOfPrimes = 0;
        unsigned long long int endOfPrimes = 0;

        cout << "What number would you like to start calculating primes at: ";
        cin >> startOfPrimes;
        while(cin.fail()){
            cout << "\n\nInvalid input!\n\n";
            cout << "What number would you like to start at: ";
        }

        cout << "What number would you like to stop calculating primes at: ";
        cin >> endOfPrimes;
        while(cin.fail()){
            cout << "\n\nInvalid input!\n\n";
            cout << "What number would you like to end at: ";
        }
        cout << "Started generating new file\n";
        primeFileGenerator(primeNumberGenerator(endOfPrimes,startOfPrimes));
        cout << "Ended generating new file\n";


    }
    primeNumbers = primeFileReader();

    int loops = 10;
    cout << "How many times would you like to loop: ";
    cin >> loops;
    while(cin.fail()){
        cout << "\n\nInvalid input!\n\n";
        cout << "How many times would you like to loop: ";
        cin >> loops;
    }


    int quantOfPrimes = primeNumbers.size();
    for(int x = 0; x < loops; x++){
        cout << "\n\n----- Starting  loop " << x+1 << " -----\n";
        unsigned long long int prime1 = primeNumbers[rand() % quantOfPrimes];
        unsigned long long int prime2 = primeNumbers[rand() % quantOfPrimes];
        unsigned long long int quotent = prime1 * prime2;
        cout << "The first prime number is "<<prime1<<endl;
        cout << "The second prime number is "<<prime2<<endl;
        cout << "The quotent of the prime numbers is "<<quotent<<endl;
        int starttime = time(nullptr);
        cout << "Starting bruteforce\n";
        vector<unsigned long long int>factors = factorFinder(quotent);
        cout << "The factors are " <<factors[0] << " and " << factors[1] << endl;
        if ((time(nullptr) - starttime) != 0)
            cout << "Calculated in " << time(nullptr) - starttime << " seconds" << endl;

    }
    
    

    
    //cout << factors.size() << endl;
}




void primeFileGenerator(vector<unsigned long long int> primeNumbers){
    ofstream outFile("primeNumbers.txt");
    for(int x : primeNumbers){
        outFile<< x << endl;
    }
}

vector<unsigned long long int> primeFileReader(){
    ifstream primeNumberFile("primeNumbers.txt");
    if (primeNumberFile.fail()){
        //cout << "No prime numbers found!\nGenerating default list\n";
        primeFileGenerator(primeNumberGenerator());
        //cout << "List generated!\n";
    }
    vector<unsigned long long int> primeNumbers;
    int placeHolder = 0;
    while(primeNumberFile >> placeHolder){
        primeNumbers.push_back(placeHolder);
    }
    primeNumberFile.close();
    return primeNumbers;
}



bool isPrimeNumber(int number){
    bool IsPrime = true;
    for (int i = number; i > 0; i--){
        if ( ((number % i) == 0) && ((i < number) && (i > 1)) ){
            IsPrime = false;
            break;
        }
    }
    return IsPrime;

}

vector<unsigned long long int> factorFinder(unsigned long long int number){
    vector<unsigned long long int> values;
    for(unsigned long long int x = 2; x < number; x++){
        //cout << "Loop " << x << endl;
        if((number % x) == 0){
            //cout << x << " appended to vector\n";
            values.push_back(x);
        }
    }
    return values;
}


vector<unsigned long long int> primeNumberGenerator(unsigned long long int finalNumber, unsigned long long int startNumber){
    vector<unsigned long long int> primeNumbers;
    for(int x = startNumber; x < (startNumber+finalNumber); x++){
        if (isPrimeNumber(x)){
            primeNumbers.push_back(x);
        }
    }
    return primeNumbers;
}
