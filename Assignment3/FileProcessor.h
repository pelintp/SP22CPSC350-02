#include <iostream>
#include <fstream>


using namespace std;
class FileProcessor{

public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //default destructor
    void processFile(string inputName, string outputName); //reads from file translates outputs a new file
};