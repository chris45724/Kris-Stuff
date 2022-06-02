#include <iostream>


using namespace std;


class Test{
public:
    string Name;
    int Value;


};


int main(){
    
    Test test1;
    test1.Name = "Test 1";
    test1.Value = 12;
    

    cout << "Name: " << test1.Name << endl << "Value: " << test1.Value << endl;
    return 0;
}