#include <iostream>


//includes the standard C++ library 
using namespace std;

class Model{

public:
    Model(); //default constructor
    ~Model(); //default destructor
    string translateSingleCharacter(char c); //translates one char to string
    string translateDoubleCharacter(char c); //translates pairs to string
    string tolower(char l); //changes lowercase
   
};