#include <iostream>
#include <array>
#include <fstream>
#include <string>

using namespace std;

/* struct Word - used to maintain a frequency table of words from a text file
// value - string - the word that we are storing
// num - unsigned int - the number of occurrences of the value to this point
*/
struct Word {
    string value;
    unsigned int num;
};



/*
Function - searchArr - searches a struct words.value for a match
Param1 - words - Word* - a pointer to an array of Word structs
Param2 - size - int - the number of elements in words
Param3 - val - string - the word that we are searching for
Return - int - the index position of the string you are searching for
Return -1 if not found
*/
int searchArr(Word *words, int size, string val) {
    //YOUR CODE HERE
    //loop through words and return the position of val if found
    for(int x = 0; x < size; x++ ){
        if (words[x].value == val){
            return(x);
        }
    }


    //don't return 0
    return -1;
}




/*
Function - countWords - counts the number of words in a text file
Param1 - inFile - ifStream - an input file handler, passed by reference
Return - int - the number of words in the text file
Cin is used to iterate over the file one word at a time
The file handler is reset to the first position in the file
*/
int countWords(ifstream &inFile) {
    int fileLen = 0;
    string currentWord;
    while(inFile >> currentWord) {
        fileLen++;
    }

    //reset the read position in the file
    inFile.clear();
    inFile.seekg(0, ios::beg) ;

    return fileLen;
}



/*
Function - initText - copies the words from a text file into an array of strings
Param1 - inFile - ifStream - an input file handler, passed by reference
Param2 - size - int - the size of the array to be created dynamically
Return - string* - pointer to the array of strings that was allocated dynamically in the function - must be freed
*/
string* initText(ifstream &inFile, int size) {
    //create a string pointer that points to dynamically allocated memory
    //YOUR CODE HERE
    string *arrayOfWords = nullptr;
    arrayOfWords = new string[size];
	
    //create a string to store the current word in the file
    //YOUR CODE HERE
    string currentWord = "";
    

    //YOUR CODE HERE
    //Loop through the file and copy each word in the file into the dynamically allocated array of strings
    //If you want to process the words at all, this is a good place to consider it - examples - Cat Cat, cat cat, cat" and cat.
	//I lower-cased the first letter. Example Cat is now cat.
	//More processing = better results but makes it more complicated
    int position = 0;
    while(inFile >> currentWord) {
        int wordLength = currentWord.length();
        string temp = "";
        for(int x = 0; x < wordLength; x++){
            char letter = tolower(currentWord[x]);

            if (!(isalnum(letter))){
            continue;
            }
            temp+= letter;
            //cout << letter << endl;
        }
        currentWord = temp;




        arrayOfWords[position] = currentWord;
        position++;
    }
	
	
	
    //return something
	//don't return 0
	return arrayOfWords;
    
}//function




/*
Function - analyzeWords - creates an array of Word structs and stores a frequency table of the values contained in a array of strings
Param1 - words - string*  - a pointer to an array of strings to be analyzed
Param2 - size - int - the size of the words array
Param3 - resultsSize - &int - the number of each unique Word in words - passed by reference
Return - Word* - pointer to the array of Word structs that was allocated in the function
An array of the minimum size is returned
*/
Word* analyzeWords(string *words, int size, int &resultsSize) {
    //YOUR CODE HERE
    //create a Word pointer to a dynamically allocated array of Words of size, size
	// this is called a concordance
    Word* wordArray = nullptr;
    wordArray = new Word[size];
    for(int x = 0; x < size; x++){
        wordArray[x].value = "";
        wordArray[x].num = 0;
    }    

    //YOUR CODE HERE
    //Build the concordance here
	//iterate over words
	//if you find a new word, then add it to the concordance
	//if the word is already in the concordance then increment the count
	//use the searchArr function to search
    int position = 0;
    for(int x = 0; x < size; x++){
        int target = searchArr(wordArray,size,words[x]);
        if(target == -1){
            //cout << words[x] << endl;
            wordArray[position].value = words[x];
            wordArray[position].num = 1;
            position++;
            resultsSize++;
        }
        else{
            wordArray[target].num++;
        }

    }
	
	
    //YOUR CODE HERE
    //return pointer to Word array
	//don't return 0
	
    return wordArray;
	
}//function



/*
Function - printResults - prints out a frequency table represented by results
Param1 - words - Word* - a pointer to an array of Word structs
Param2 - size - int - the size of the array
Return - void
Format is "word - count\n"
*/

void printResults(Word *results, int size) {
    //YOUR CODE HERE
	//Iterate over results and print out the words and the number of occurrences

    for(int x = 0; x < size; x++){
        cout << results[x].value << " occur " << results[x].num << " times\n";
    }
	
	
}


int main() {

    ifstream inFile;// input file handler
    string fileName = "hobbit.txt"; // the name of the text file - you need the file in this directory
    string *text = nullptr;// pointer to an array of strings containing the words in the text file
    Word *results = nullptr;// pointer to an array of Words that will represent the concordance
    int resultsSize = 0; // gets passed around by reference. Used to store the number of unique words in the text file


    //open file
    inFile.open(fileName);

    //test file open
    if(inFile) {
        cout << "File opened" << endl;
    } else {
        cout << "File error" << endl;
    }//if

    //we will use this to manage our array
    int MAX_NUM = countWords(inFile);
    //cout << countWords(inFile);



    //declare an array of Words of size MAX_NUM and assign it to the pointer from earlier
    text = initText(inFile, MAX_NUM);
    //cout << initText(inFile, MAX_NUM);


    //call countWords
    results = analyzeWords(text, MAX_NUM, resultsSize);
    //analyzeWords(text, MAX_NUM, resultsSize);

    //edit for testing
    printResults(results, resultsSize);

    return 0;
}

