/*
Chris Howard
CS162
Week 3
*/
#include <iostream>
#include <cstring>

using namespace std;
/* 
----- 2 -----
Backward String:
Write a function that accepts a pointer to a C-string as an argument and displays its contents backward. 
For instance, if the string argument is "Gravity" the function should display "ytivarG". 
Demonstrate the function in a program that asks the user to input a string then passes it to the function.
----- 2 -----
*/
void backwardString(char *cstring){
   int length = 0;
   while(cstring[length] != '\0'){
      //cout << length <<cstring[length] << endl;
      length++;
   }
   length--;
   cout << length;
   cout << "String \"" << cstring << "\" backwards is \"";
   for(int x = 0; x <= length; x++){
      cout << cstring[length-x];
   }
   cout << "\"\n";
}


void problem2(){
   cout << "\n------ Problem 2 ------\n";
   int length = 40;
   char teststring[40];
   cout << "Please provide a string with a length of shorter than " << (length-1) << ": ";
   cin >> teststring;
   //cout << "len" << strlen(temp) << endl;

   //char teststring[strlen(temp)] = temp;
   backwardString(teststring);

}


/* 
----- 5 -----
Sentence Capitalizer:
Write a function that accepts a pointer to a C-string as an argument and capitalizes the first character of each sentence in the string. 
For instance, if the string argument is "hello. my name is Joe. what is your name?" 
the function should manipulate the string so that it contains "Hello. My name is Joe. What is your name?" 
Demonstrate the function in a program that asks the user to input a string then passes it to the function. 
The modified string should be displayed on the screen. 
Optional Exercise: Write an overloaded version of this function that accepts a string class object as its argument. 
----- 5 -----
*/
/*
This function will take a String, or a CString, passed by to it, and modify the string so that after every sentence, it will be capatlized
This function modifies the string/Cstring passed to it
*/
void sentenceCapitalizer(char *cstring){
   bool newSentence = true;
   int length = 0;
   int place = 0;
   while(cstring[length] != '\0'){
      //cout << length <<cstring[length] << endl;
      length++;
   }
   length--;
   while(place < length){

         if(isalpha(cstring[place]) && (newSentence)){
            cstring[place] = toupper(cstring[place]);
            newSentence = false;
         }
         //((ispunct(cstring[place])) I origionally tired this, but it would punctuate after ',' and '+'
         if( (((cstring[place]) == ('.')) || ((cstring[place]) == (';'))) || (((cstring[place]) == ('!')) || ((cstring[place]) == ('?'))) ){
            newSentence = true;
         }
      //cout << place << " : " << cstring[place] << endl;
      place++;
   }
   cout << cstring << endl;
}

// -------- Overloaded version --------

void sentenceCapitalizer(string &sentence){
   bool newSentence = true;
   int length = sentence.size();
   int place = 0;
   
   length--;
   while(place < length){

         if(isalpha(sentence[place]) && (newSentence)){
            sentence[place] = toupper(sentence[place]);
            newSentence = false;
         }
         //((ispunct(cstring[place])) I origionally tired this, but it would punctuate after ',' and '+'
         if( (((sentence[place]) == ('.')) || ((sentence[place]) == (';'))) || (((sentence[place]) == ('!')) || ((sentence[place]) == ('?'))) ){
            newSentence = true;
         }
      //cout << place << " : " << cstring[place] << endl;
      place++;
   }
   cout << sentence << endl;
}









void problem5(){
   cout << "\n------ Problem 5 ------\n";
   string tempString = "";
   int length = 0;
   cout << "Please provide a sentence to capitalize: ";
   getline(cin,tempString);
   length = tempString.size();
   char CString[length];
   for(int x = 0; x < length; x++){
      CString[x] = tempString[x];
   }
   //cout << CString;
   //char CString[] = "applesauce. i like it!";
   sentenceCapitalizer(CString);
   //string test2 = "test. test2. test3. test, but comma!";
   //sentenceCapitalizer(test2);

}


/* 
----- 10 -----
replaceSubstring Function:
Write a function named replaceSubstring. 
The function should accept three C-string or string object arguments. 
Let’s call them string1, string2, and string3. 
It should search string1 for all occurrences of string2. 
When it finds an occurrence of string2, it should replace it with string3. 
For example, suppose the three arguments have the following values:

string1:	“the dog jumped over the fence”
string2: 	“the”
string3:	“that”

With these three arguments, the function would return a string object with the value “that dog jumped over that fence.” 
Demonstrate the function in a complete program.
----- 10 -----
*/
string replaceSubstring(string mainString, string target, string subsitute){
   bool endSentence = false;
   bool newWord = false;
   string temp = "";
   string newString = "";
   int place = 0;
   int length = mainString.size();
   while(!endSentence){
      temp = "";
      newWord = false;
      while(!newWord && (place < length)){
         if(isprint(mainString[place]) && (!isspace(mainString[place]))){
            temp = temp + mainString[place];
         }
         if(isspace(mainString[place])){
            newWord = true;
         }
         place++;
         if(temp == target){
            temp = subsitute;
         }
      }
      //cout << temp << endl;
      //cout << temp << " ";
      newString += temp;
      if (place >= length){
         endSentence = true;
         break;
      }
      newString += " ";
   }
   //cout << newString <<endl;
   //cout << newString << "Junk-to-test-space";
   return newString;
}
void problem10(){
   cout << "\n------ Problem 10 ------\n";
   string mainString = "the dog jumped over the fence";
   string target = "the";
   string replacement = "that";
   cout << "Original string is: \"" << mainString << "\"\nTarget word is: \"" << target << "\"\nSubstitute string is: \"" << replacement << "\"\n";
   cout << "New string is: \"" << replaceSubstring(mainString,target,replacement) << "\"\n";

}


/* 
----- 16 -----
Pig Latin:
Write a program that reads a sentence as input and converts each word to “Pig Latin.” 
In one version, to convert a word to Pig Latin, you remove the first letter and place that letter at the end of the word. 
Then you append the string “ay” to the word. Here is an example:

English: I SLEPT MOST OF THE NIGHT
Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY 
----- 16 -----
*/
void pigLatin(string sentence){
   int place = 0;
   int length = sentence.size();
   bool endSentence = false;
   string temp = "";
   int wordBegining = place;
   int wordEnd = place;
   bool endWord = false;
   bool newWord = true;
   while(!endSentence){
      temp = "";
      while(!endWord &&((place < length))){
         if(isalnum(sentence[place]) && (newWord)){
            wordBegining = place;
         }
         else if(isalnum(sentence[place])){
            continue;
         }
         else{
            wordEnd = place;
            endWord = true;
         }
         if(place >= length){
            break;
            endSentence = true;
         }
         place++;
      }
      cout << sentence[wordEnd];
      temp = temp + sentence[wordEnd];
      for(int x = (wordBegining + 1); x < (wordEnd); x++){
         temp = temp + sentence[x];
         cout << sentence[x];
      }
      temp = temp + sentence[wordBegining];
      cout << sentence[wordBegining];
      temp = temp + "ay";
      cout << temp << endl;
      if (place >= length){
         endSentence = true;
         break;
      }
   }
   
   //place++;
}
void problem16(){
   cout << "\n------ Problem 16 ------\n";
   string normalSentence = "abcd efgh";
   //cout << "Please provide a sentence: ";
   //cin >> normalSentence;
   pigLatin(normalSentence);

   


}

int main(){
   //problem2();
   //problem5();
   //problem10();
   problem16();
return 0;
}
