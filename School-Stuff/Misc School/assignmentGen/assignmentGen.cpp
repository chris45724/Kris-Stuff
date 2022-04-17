//make assignment plz
#include <iostream>
#include <fstream>

using namespace std;

void clear(){
    cin.clear();
    cin.ignore(255,'\n');
}

template <typename T>
void resposeFail(T &data, string respose, int limit = 20){
    while((limit > 0) && (cin.fail())){
        clear();
        cout << "Invalid response!\n";
        cout << respose;
        cin >> data;
    }
}

int question(string);

void outputHwGenerator();

void inputHwGenerator();

int main(){
    //cout << "Have you already generated files?\n[y]es   [n]o: ";
    int response = question("Have you already generated input files?");
    if (response == 1){
        outputHwGenerator();
    }
    else if (response == 0){
        inputHwGenerator();
    }
    else{
        cout << "Invalid response\nNow exiting\n";
        return 1;
    }
    return 0;
}




int question(string prompt){
    char response = 'v';
    cout << prompt << "\n[y]es   [n]o: ";
    cin >> response;
    if (response == 'y'){
        return 1;
    }
    else if (response == 'n'){
        return 0;
    }
    else{
        return -1;
    }
}

void outputHwGenerator(){
    cout << "placeholder\n";
}

void inputHwGenerator(){
    int week = 0;
    int problems = 0;
    cout << "Generating homework input files\n";
    cout << "What week is the assignment: ";
    cin >> week;
    resposeFail(week,"What week is the assignment: ");
    cout << "How many homework problems?\nInput 0 to exit: ";
    cin >> problems;
    resposeFail(problems,"How many homework problems: ");
    if(problems != 0){
        string filename = "Week " + to_string(week) + ".cpp";
        ofstream file(filename);
        int problemNames[problems];
        for(int x = 0; x < problems; x++){
            cout << "What number is problem " << (x+1) << ": ";
            cin >> problemNames[x];
            resposeFail(problemNames[x],"Number: " ,3);
            /*
            while(cin.fail()){
                clear();
                cout << "Invalid response!\n";
                cout << "What number is problem " << (x+1) << ": ";
                cin >> problemNames[x];
            }*/
        }
        file << "/*\nChris Howard\nCS162\nWeek " << week <<"\n*/\n";
        file << "#include <iostream>\n";
        file << "using namespace std;"
        file << "\n";

        cout << "Making functions\n";
        for(int x = 0; x < problems; x++){
            file << "\n/* "<< "\n----- "<< problemNames[x] << " -----" <<"\n\n" << "----- "<< problemNames[x] << " -----\n*/\n";
            file << "void problem" << problemNames[x] << "(){\n";
            file << "   cout << \"------ Problem "<< problemNames[x] <<" ------\\n\";" << endl;
            file << "\n}";
            cout<< "Problem " << x + 1 << " was created" << endl;
            cout<< "Problem " << x + 1 << " was labled problem" << problemNames[x] << "()"<< endl;
            file << "\n\n";

        }
        cout << "\n\n";
        cout << "Making main\n";
        file << "int main(){\n";
        for(int x = 0; x < problems; x++){
            file << "   //problem" << problemNames[x] << "();\n";
        }
        file << "return 0\n}\n";
        file.close();

    }
    


}