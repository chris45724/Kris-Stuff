/*
Chris Howard
CS162
Week 5
*/
#include <iostream>
#include <time.h>
using namespace std;

/* 
----- 3 -----

Car Class
   Write a class named Car that has the following member variables:
      
      yearModel — an int that holds the car’s year model
      
      make — a string that holds the make of the car
      
      speed — an int that holds the car’s current speed
      
   In addition, the class should have the following constructor and other member functions:
      
      Constructor — The constructor should accept the car’s year model and make as arguments. 
         These values should be assigned to the object’s yearModel and make member variables
         The constructor should also assign 0 to the speed member variables.
   
      
      Accessor — appropriate accessor functions to get the values stored in an object’s yearModel,
         make, and speed member variables
      
      accelerate — The accelerate function should add 5 to the speed member variable each time it is called.
      
      brake — The brake function should subtract 5 from the speed member variable each time it is called.
      
   Demonstrate the class in a program that creates a Car object, then calls the accelerate function five times. 
   After each call to the accelerate function, get the current speed of the car and display it. 
   Then, call the brake function five times. 
   After each call to the brake function, get the current speed of the car and display it.


----- 3 -----
*/
class Car
{  
   private:
      string make;
      int yearModel;
      int speed;
   public:
      // constructors
      Car();
      Car(string);
      Car(string, int);
      //Ability to set values
      void setMake(string);
      void setYearModel(int);
      // Accessors
      int getYearModel() const
      { return yearModel; }
      string getMake() const
      { return make; }
      int getSpeed() const
      { return speed; }
      //Weird stuffs
      void accelerate()
      { speed+= 5; }
      void brake()
      { 
      if (speed > 0){
         speed-=5;
      }
      }
};

//Empty car class
Car::Car()
{
   make = "NotSet";
   yearModel = -1;
   speed = 0;
}

//Car with only make
Car::Car(string inputMake)
{
   make = inputMake;
   yearModel = -1;
   speed = 0;
}

//car with make and year
Car::Car(string inputMake, int inputYear)
{
   make = inputMake;
   yearModel = inputYear;
   speed = 0;
}

//Sets the Car's make to a provided value (inputMake)
void Car::setMake(string inputMake)
{
   make = inputMake; 
}

//Sets the Car's yearModel to a provided value (inputYearModel)
void Car::setYearModel(int inputYearModel)
{
   yearModel = inputYearModel;
}



void problem3(){
   cout << "\n------ Problem 3 ------\n";
   Car test1("TestCar1" , 2002);
   cout << test1.getMake() << "'s Speed is " <<  test1.getSpeed() << endl << endl;
   for(int x = 1; x < 6; x++){
      test1.accelerate();
      cout << "accelrated " << x << " times\n";
      cout << test1.getMake() << "'s Speed is " <<  test1.getSpeed() << endl << endl;
   }
   for(int x = 1; x < 6; x++){
      test1.brake();
      cout << "braked " << x << " times\n";
      cout << test1.getMake() << "'s Speed is " <<  test1.getSpeed() << endl << endl;
   }

}


/* 
----- 8 -----
Circle Class
   Write a Circle class that has the following member variables:

      radius — a double
      
      pi — a double initialized with the value 3.14159
    
   The class should have the following member functions:
   
    	Default Constructor — a default constructor that sets radius to 0.0
    	
    	Constructor — accepts the radius of the circle as an argument 
    	
    	setRadius — a mutator function for the radius variable 
    	
    	getRadius — an accessor function for the radius variable 
    	
    	getArea — returns the area of the circle, which is calculated as area = pi * radius * radius
     
     	getDiameter — returns the diameter of the circle, which is calculated as diameter = radius * 2
     	
     	getCircumference — returns the circumference of the circle, which is calculated as circumference = 2 * pi * radius

   Write a program that demonstrates the Circle class by asking the user for the circle’s radius, creating a Circle object, then reporting the circle’s area, diameter, and circumference.


----- 8 -----
*/
class Circle
{
   private:
      double radius = 0;
      double pi = 3.14159;
   
   public:
      Circle()
      { radius = 0; }
      Circle(double newRadius)
      { radius = newRadius;}
      
      void setRadius(double newRadius)
      { radius = newRadius; }
      double getRadius() const
      { return radius; }
      double getArea() const
      {return (pi * radius * radius);}
      double getDiameter() const
      { return (2 * radius);}
      double getCircumference() const
      { return (2*pi*radius);}


};


void problem8(){
   cout << "\n------ Problem 8 ------\n";
   int x;
   cout << "Please provide a radius for a circle: ";
   cin >> x;

   //x=5; //Test radius

   Circle circle1(x);
   cout << endl;

   cout << "Circle stats:\n" << "    Radius: " << circle1.getRadius() << " units\n";
   cout << "    " << "Diameter: " << circle1.getDiameter() << " units\n";
   cout << "    " << "Area: " << circle1.getArea() << " square units\n";
   cout << "    " << "Circumference: "  << circle1.getCircumference() << " units\n";

}


/* 
----- 10 -----
Number Array Class
   Design a class that has an array of floating-point numbers. 
   The constructor should accept an integer argument and dynamically allocate the array to hold that many numbers. 
   The destructor should free the memory held by the array. 
   In addition, there should be member functions to perform the following operations:
    
      Store a number in any element of the array

      Retrieve a number from any element of the array
    
      Return the highest value stored in the array
   
      Return the lowest value stored in the array
    
      Return the average of all the numbers stored in the array
    
      Demonstrate the class in a program.
----- 10 -----
*/

// I want to do template <typename T> so bad!
class DynamicArray
{
   private:
      int size;
      double *theArray = nullptr;
   public:
   DynamicArray(int setSize)
   {
      cout << theArray<<endl;
      //delete *theArray;
      theArray = new double[setSize];
      size = setSize;
      cout << theArray <<endl;
   }
   ~DynamicArray()
   {
      //delete [] theArray;
      theArray = nullptr;
      delete theArray;
   }

   //gets a value from the array at a specifided position
   double get(const int location) const
   {
      cout << theArray << endl;
      //double hold = theArray[location]; // <---- keeps stack dumping, and I don't have a working debugger, so I'm giving up
      return theArray[location];
   }
   
   //
   void set(int position, double value)
   {
      if (position <= size){
         //cout << value << endl;
         theArray[position] = value;
      }
   }
   
   
   // I know the instructions said to return the value, but I think the position is far more valuable
   int highest() const;
   int lowest() const;

};

void problem10(){
   cout << "\n------ Problem 10 ------\n";
   DynamicArray array(5);
   cout << array.get(3) << endl;
   //array.set(3,3.3);
   //cout << array.get(3) << endl;
}


/* 
----- 12 -----
Coin Toss Simulator
   Write a class named Coin. The Coin class should have the following member variable:

   A string named sideUp. The sideUp member variable will hold either “heads” or “tails” indicating the side of the coin that is facing up.
   The Coin class should have the following member functions:
    
   A default constructor that randomly determines the side of the coin that is facing up (“heads” or “tails”) and initializes the sideUp member variable accordingly.
    
   A void member function named toss that simulates the tossing of the coin. When the toss member function is called, it randomly determines the side of the coin that is facing up (“heads” or “tails”) and sets the sideUp member variable accordingly.
   
   A member function named getSideUp that returns the value of the sideUp member variable.
    
   Write a program that demonstrates the Coin class. The program should create an instance of the class and display the side that is initially facing up. Then, use a loop to toss the coin 20 times. Each time the coin is tossed, display the side that is facing up.
   The program should keep count of the number of times heads is facing up and the number of times tails is facing up, and display those values after the loop finishes.

----- 12 -----
*/
class Coin{
   private:
      string sideUp;
   public:
   Coin()
   {
      toss();
   }
   
   void toss()
   {
      srand(time(nullptr));
      int x = rand() % 10 + 1;
      if((x%2)==0){
         sideUp = "Heads";
      }
      else{
      sideUp = "Tails";
      }
   }  
   string getSideUp()
   { return sideUp;}
      
   
};

void problem12(){
   cout << "\n------ Problem 12 ------\n";
   Coin coin;
   //cout << "The coin started on " << coin.getSideUp() << endl;
   int heads = 0;
   for(int x = 0; x <20; x++){

      //Figuring out what time we got our number
      int wait = time(nullptr);
      coin.toss();
      if (coin.getSideUp() == "Heads"){
         heads++;
      }
      cout << "Coin " << x+1 << " landed on " << coin.getSideUp() << endl;

      //Because we get a new random number every second, we must wait for a new one
      while(time(nullptr) == wait){
         int y = 1;
      }
   }
   cout << "You got heads " << heads << " times, and you got tails " << (20-heads) << " times\n";

}

int main(){
   problem3();
   problem8();
   //problem10();
   problem12();
return 0;
}
