#include "parser.h"
int main()
{
   string str;
   cout << "Enter something : ";   //asks users input
   
   getline(cin, str); //
   
   Parser parserparser(str);
   parserparser.outputToFile("output.txt");  // displays the output on the txt file.
   return 0;
}