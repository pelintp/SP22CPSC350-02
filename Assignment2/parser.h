#define PARSER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 

class Parser 
{
private:
   string input_string;
public:
   // CONSTRUCTOR
   Parser(string str);

   void all_functions(ofstream& fout);    // shows the all_functions
   void pairs(ofstream& fout);
   void outputToFile(string file);   // shows the output.txt
};
