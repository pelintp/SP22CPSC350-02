#include <string>
#include <iostream>
using namespace std;

class Translator{
public:

    Translator(); //default constructor
    ~Translator(); //default destructor
    string translateEnglishWord(string word); 
    string translateEnglishSentence(string sent); 

};
