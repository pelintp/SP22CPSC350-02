#include "parser.h"
int main()
{
   string str_string;
   cout << "Enter something : ";   //asks users input
   cin>>str_string; //assigns inputted value to the variable str_string
   
   Parser parserparser(str_string);
   parserparser.outputToFile("output.txt");  // displays the output on the txt file.
   return 0;
}
