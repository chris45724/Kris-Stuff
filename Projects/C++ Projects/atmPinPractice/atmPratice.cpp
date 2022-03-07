//This is from the cs161 textbook!!!
#include <iostream>
#include <vector>



using namespace std;


bool arraySizeChecker(const int pin[]){
    
    vector<int> pinVector(0,pin);
    int arrayCount = 0;

    /*for(int x : pin){
        arrayCount++;
    }*/
    cout << pin;
    if (arrayCount == 7){
        return true;
    }
    else{
        return false;
    }
}


bool pinChecker(const int pinInput[],const int pinDatabase[]){
    if ((arraySizeChecker(pinInput) == false) || (arraySizeChecker(pinDatabase) == false)){
        return false;
    }
    for(int x = 0; x < 7; x++){
        std::cout << "pin input is: " << pinInput[x] << std::endl;
        std::cout << "pin database is: " << pinDatabase[x] << std::endl;
        if (pinInput[x] != pinDatabase[x]){
            return false;
        }
    }
    return true;
}





int main(){
    int x[6] = {1,2,3,4,5,6};
    int y[7] = {1,2,3,4,5,6,7};

    std::cout << pinChecker(x,y) << std::endl;
    
    return 0;
}