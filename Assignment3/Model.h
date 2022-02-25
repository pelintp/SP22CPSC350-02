#include <iostream>

using namespace std;

class Model{

public:
    Model(); //default constructor
    ~Model(); //default destructor
    string translateSingleCharacter(char c); //translates one char to string
    string tolower(char l); //changes lowercase
    string translateDoubleCharacter(char c); //translates pairs to string

   
};
