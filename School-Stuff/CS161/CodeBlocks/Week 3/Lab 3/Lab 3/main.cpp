#include <iostream>
#include <iomanip>


/*
    mad lab
    Chris Howard
    Lab 3

*/
/*


The program will display the string which will tell the following story.
There was once a person named NAME who lived in CITY. At the age of AGE, NAME went to college at
COLLEGE. NAME graduated and went to work as a PROFESSION. NAME adopted a(n) ANIMAL named
PETNAME. They both lived happily ever after...
This will be a mad libs style story; replacing the words in all caps with the variables assigned

a) Name
b) Age
c) Name of a city
d) Name of a college
e) Name of a profession
f) Type of animal
g) Pet's name

*/

using namespace std;

int main()
{


   // we make the variables
   string name, city, collage, profession, age, animal, petName;
   string out;

   cout << "Please input a name: ";
   getline(cin, name);


   cout << "Please input a number: ";
   getline(cin, age);


   cout << "Please input a city: ";
   getline(cin, city);

   cout << "Please input a collage: ";
   getline(cin, collage);


   cout << "Please input a profession: ";
   getline(cin, profession);

   cout << "Please input an animal: ";
   getline(cin, animal);


   cout << "Please input a name: ";
   getline(cin, petName);


   //this is to look nicer
   cout << "\n\n\n\n";

   // we will concatenate all of the variables into a string for the story

   out = "There was once a person named "+name+" who lived in "+city+". At the age of "+age+", "+name+" went to college at ";

   out += collage +".\n"+name+" graduated and went to work as a "+profession+".\n"+name+" adopted a(n) "+animal+" named ";

   out += petName +".\nThey both lived happily ever after...";

   cout << out;




}
