/*
Chris Howard
?????
CS 161
*/



#include <iostream>
#include<time.h>

using namespace std;


int main(){



    /*
    int num = 0;
    cout << "Guess a number: ";
    cin >> num;

    if(num != 42){
        cout << "You loose" << endl;
    }
    else{   
        cout << "Correct guess!" << endl;
    }


    */

   /*
   int num2 = 0;

   cout << "Provide a percentile score for grading:";

   cin >> num2;


   if(num2 >= 90){
       cout << "Score is A\n";
   }
   else if(num2 >= 80){
       cout << "Score is B\n";
   }
   else if(num2 >= 70){
       cout << "Score is C\n";
   }
   else if(num2 >= 60){
       cout << "Score is D\n";
   }
   else{
       cout << "Score is F\n";
   }

    */



   /*
   int num3;
   srand(time(nullptr));

   num3 = (rand()%10)+1;

   cout << num3 << " whatever name"<< endl;
    

   for(int i = 0; i < num3; i++){
      cout << "Hello, ";
   } 

   cout << "- Kurt Cobain" << endl;


    */


   /*
    for(int i = 1; i <= 20; i++){
        cout << i << " - " << i*i << endl;
    }
    */


   /*
   int num4 = 0;
   cout<< "Please input a number: ";

   cin >> num4;


   for(int i = num4; i != 0; i--){
       cout << i << endl;
   }
    */


   int num5 = 0;
   int num6 = 0;

   cout << "gib number for rectangle of stars\n";
   cout << "What's the height: ";

   cin >> num5;

   cout << "Width: ";
   cin >> num6;


   for(int x = num6; x > 0 ; x--){
       for(int i = 0; i < num5; i++){
           cout<< "*";
       }
       cout << endl;
   }





}