#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>
#include <cctype>
#include <array>
#include <fstream>
#include <string>


using namespace std;

// dynamicly change size of array

//template <typename T>



int main(){
    string currentWord = "\"Apple\"";
    int length = currentWord.length();
    int wordLength = currentWord.length();
    string temp = "";
        for(int x = 0; x < wordLength; x++){
        char letter = tolower(currentWord[x]);
        if (!(isalnum(letter))){
            continue;
        }
        temp+= letter;
        currentWord2[x] = letter;

        //cout << letter << endl;
    }
    cout << temp << endl;
}