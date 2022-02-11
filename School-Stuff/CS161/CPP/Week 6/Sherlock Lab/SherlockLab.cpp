/*
Chris Howard
CS161
SherlockLab
*/

#include <iostream>
#include <iomanip>
#include <fstream>



using namespace std;



int main(){
    
    ifstream sherlock;
    sherlock.open("sherlock-1.txt");
    ofstream outputFile;
    outputFile.open("textAnalysis.txt");

    if(sherlock.fail()){
        cout << "\nThe input file Failed\n";

        cout << "Please check the input file's name\n\n";

        return 1;
    }


    int quantThe = 0;
    int quantWords = 0;

    string word,longestWord;

    cout << endl;
    while(sherlock >> word){
        quantWords++;
        if(word == "the"){
            quantThe++;
        }        
    
    
    }

    sherlock.close();

    cout << endl;

    cout << "The total number of words is: "<< quantWords<< "\nThe number of occurrences of \"the\" is: " << quantThe << endl << endl;
    outputFile << "The total number of words is: "<< quantWords<< "\nThe number of occurrences of \"the\" is: " << quantThe << endl;

    if(outputFile.fail()){
        cout << "The output file failed!";
    }

    outputFile.close();

    //cout << aa << bb << cc << endl;
    
    return 0;
}