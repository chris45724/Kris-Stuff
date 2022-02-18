#include <iostream>

using namespace std;



void tester(int &v);


int main(){
    int x = -5;

    int y;

    cout << -x << endl;


    int test;


    tester(test);
    y = test;
    cout << y << " What??";

    
    
    
    return 0;
}


void tester(int &v){


    
    cout <<" Please pass a number: ";
    cin >> v;

    v;



}