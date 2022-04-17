#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>




using namespace std;


/*
This function just clears the cin.fail() flag
*/
void clear(){
    cin.clear();
    cin.ignore(255,'\n');
}

/*
This function will prompt the user if they input invalid data, it will then try to get valid data from the user
variables:
    Data - This is a template data type to allow it to work with any type of data, this varable is passed by reference and will overwrite the origianal
    response - This takes a string that the function will print to the terminal every time. This should be instructions for what the user should input
    limit - This limits how many times the function will run
*/
template <typename T>
void responseFail(T &data, string respose, int limit = 20){
    while((limit > 0) && (cin.fail())){
        clear();
        cout << "Invalid response!\n";
        cout << respose;
        cin >> data;
    }
}







int main(){
    
    
    
    return 0;
}



/* //Default cin error

while(cin.fail())

    cin.clear();
    cin.ignore(255,'\n');


*/

