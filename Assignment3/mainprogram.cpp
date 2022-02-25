#include <iostream>
#include "FileProcessor.h"

using namespace std;

int main(){
    
    FileProcessor p;
    string inputName, outputName;
    //alows you to enter the text file name that is your main file
    cout <<"Enter the name of the input file that you want to translate"<< endl;
    getline(cin, inputName);
    //creates a new output file with whatever the name you want it to be. 
    cout<<"enter the output file name that you want to create." << endl;
    getline(cin,outputName);
    
    p.processFile(inputName, outputName);
    return 0;

}