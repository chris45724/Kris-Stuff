/*
Chris Howard
CS162
Week 4
*/
#include <iostream>
#include <array>
#include <fstream>
#include <string>

using namespace std;

/* 
----- 1 -----
Movie Data
Write a program that uses a structure named MovieData to store the following information about a movie:
Title:
Director:
Year Released:
Running Time (in minutes):
The program should create two MovieData variables, 
store values in their members, and pass each one, 
in turn, to a function that displays the information about the movie in a clearly formatted manner.
----- 1 -----
*/
struct MovieData{
   string title;
   string director;
   int release;
   int runtime;
};

void moviePrinter(MovieData movie){
   cout << "Info about " << movie.title << endl;
   cout << "Director: " << movie.director << endl;
   cout << "Released in: " << movie.release << endl;
   cout << "Movie runtime: " << movie.runtime  << " minutes"<< endl;
}


void problem1(){
   cout << "------ Problem 1 ------\n";
   MovieData movie1,movie2;

   // I'm just making up movies...
   movie1.title = "Good movie";
   movie1.director = "Cool director";
   movie1.release = 2002;
   movie1.runtime = 125;

   movie2.title = "Bad movie";
   movie2.director = "Lame director";
   movie2.release = 2003;
   movie2.runtime = 100;

   moviePrinter(movie1);
   moviePrinter(movie2);



}


/* 
----- 2 -----
Movie Profit
Modify the program written for Programming Challenge 1 (Movie Data) to include two additional members that hold the movie’s production costs and first-year revenues. 
Modify the function that displays the movie data to display the 
title, 
director, 
release year, 
running time, 
and first year’s profit or loss.

----- 2 -----
*/

struct MovieData2{
   string title;
   string director;
   int release;
   int runtime;
   int cost;
   int firstRev;
};

void moviePrinter2(MovieData2 movie){
   cout << "Info about " << movie.title << endl;
   cout << "Director: " << movie.director << endl;
   cout << "Released in: " << movie.release << endl;
   cout << "Movie runtime: " << movie.runtime  << " minutes"<< endl;
   cout << "Movie production cost: " << movie.cost  << " thousand dollars"<< endl;
   cout << "Movie first year revenue: " << movie.firstRev  << " thousand dollars"<< endl;

}


void problem2(){
   cout << "\n------ Problem 2 ------\n";

   MovieData2 movie1,movie2;

   // I'm just making up movies...
   movie1.title = "Good movie";
   movie1.director = "Cool director";
   movie1.release = 2002;
   movie1.runtime = 125;
   movie1.cost = 340;
   movie1.firstRev = 590;

   movie2.title = "Bad movie";
   movie2.director = "Lame director";
   movie2.release = 2003;
   movie2.runtime = 100;
   movie2.cost = 485;
   movie2.firstRev = 324;


   moviePrinter2(movie1);
   moviePrinter2(movie2);

}


/* 
----- 6 -----
Soccer Scores
Write a program that stores the following data about a soccer player in a structure:
Player’s Name
Player’s Number
Points Scored by Player
The program should keep an array of 12 of these structures. 
Each element is for a different player on a team. 
When the program runs, 
it should ask the user to enter the data for each player. 
It should then show a table that lists each player’s:
number, 
name, 
and points scored. 
The program should also calculate and display the total points earned by the team. 
The number and name of the player who has earned the most points should also be displayed.
Input Validation: Do not accept negative values for players’ numbers or points scored

Only need 3 players of data
----- 6 -----
*/

struct playerData{
   string name = "n\\a";
   int number = 0;
   int points = 0;
};

void playerDataGetter (playerData &player, int position){
   cout << "What was the name of player " << position << ": ";
   cin >> player.name;
   cout << "What was the player number of " << player.name << ": ";
   cin >> player.number;
   while (player.number < 0){
      cout << "player number cannot be a negative number!\nWhat was the number of player " << position << ":";
      cin >> player.number;
   }
   cout << "How many points did " << player.name << " score: ";
   cin >> player.points;
   while (player.points < 0){
      cout << "score cannot be a negative number!\nWhat was the score of " << player.name << ":";
      cin >> player.points;
   }
}

void problem6(){
   cout << "\n------ Problem 6 ------\n";
   playerData players[12];
   for(int x = 0; x < 3; x++){
      playerDataGetter(players[x],(x+1));
   }
   cout << endl;
   int largestScore = 0;
   for(int x = 0; x < 3; x++){
      if(players[x].points > players[largestScore].points){
         largestScore = x;
      }
   }
   cout << players[largestScore].name << " scored the most points!\nThey scored " << players[largestScore].points << "\nTheir player numer was " << players[largestScore].number << endl;


}


/* 
----- 11 -----
Monthly Budget
A student has established the following monthly budget:
Housing		$500.00
Utilities 	$150.00
Household Expenses	$65.00
Transportation	$50.00
Food	$250.00
Medical		$30.00
Insurance	$100.00
Entertainment	$150.00
Clothing	$75.00
Miscellaneous	$50.00

Write a program that has a MonthlyBudget structure designed to hold each of these expense categories. 
The program should pass the structure to a function that asks the user to enter the amounts spent in each budget category during a month. 
The program should then pass the structure to a function that displays a report indicating the amount over or under in each category, 
as well as the amount over or under for the entire monthly budget.

Only 5 items on budget
----- 11 -----
*/

struct MonthlyBudget{
   float Housing = 500;
   float Utilities = 150;
   //float Household = 65;
   float Transportation = 50;
   float Food = 250;
   //float Medical = 30;
   //float Insurance = 100;
   float Entertainment = 150;
   //float Clothing = 75;
   //float Miscellaneous = 50;

};

void budgetGetter(MonthlyBudget &budget){
   cout << "How much was spent on housing this month: ";
   cin >> budget.Housing;
   cout << "How much was spent on housing this Utilities: ";
   cin >> budget.Utilities;
   cout << "How much was spent on Transportation this month: ";
   cin >> budget.Transportation;
   cout << "How much was spent on housing this Food: ";
   cin >> budget.Food;
   cout << "How much was spent on housing this Entertainment: ";
   cin >> budget.Entertainment;

}

void budgetReport(const MonthlyBudget thisMonth){
   MonthlyBudget base;

   cout << "You spent " << thisMonth.Housing << "$ on housing out of " << base.Housing << endl;
   cout << "You have " << base.Housing-thisMonth.Housing << "$ leftover" << endl << endl;

   cout << "You spent " << thisMonth.Utilities << "$ on utilities out of " << base.Utilities << endl;
   cout << "You have " << base.Utilities-thisMonth.Utilities << "$ leftover" << endl << endl;

   cout << "You spent " << thisMonth.Transportation << "$ on transportation out of " << base.Transportation << endl;
   cout << "You have " << base.Transportation-thisMonth.Transportation << "$ leftover" << endl << endl;

   cout << "You spent " << thisMonth.Food << "$ on food out of " << base.Food << endl;
   cout << "You have " << base.Food-thisMonth.Food << "$ leftover" << endl << endl;

   cout << "You spent " << thisMonth.Entertainment << "$ on entertainment out of " << base.Entertainment << endl;
   cout << "You have " << base.Entertainment-thisMonth.Entertainment << "$ leftover" << endl << endl;

}

void problem11(){
   cout << "\n------ Problem 11 ------\n";
   MonthlyBudget thisMonth;
   budgetGetter(thisMonth);
   budgetReport(thisMonth);
   


}

int main(){
   problem1();
   problem2();
   problem6();
   problem11();
return 0;
}
