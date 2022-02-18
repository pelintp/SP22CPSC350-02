#include <fstream>
#include "parser.h"

using namespace std;
Parser::Parser(string str_string)
{
   input_string = str_string;
}

void Parser::all_functions(ofstream& fout)
{
   // initializing 26 variables &  non alphs and pairs
   int a = 0;
   int b = 0;
   int c = 0;
   int d = 0;
   int e = 0;
   int f = 0;
   int g = 0;
   int h = 0;
   int I = 0;
   int j = 0;
   int k = 0;
   int l = 0;
   int m = 0;
   int N = 0;
   int o = 0;
   int p = 0;
   int q = 0;
   int r = 0;
   int s = 0;
   int t = 0;
   int u = 0;
   int v = 0;
   int w = 0;
   int x = 0;
   int y = 0;
   int z = 0;
   int Non_Alphabet = 0;
   int p_pairs=0;
   
   
  
 //increases the letter count when  it finds searched letter. If it isn'tin  the alphabet it  adds it to non-alphs
   
   for 
   (int i = 0; i < input_string.length(); ++i)
       {
       //  IF  ELSE TO DETERMINE  IF  IT IS ALPHS  OR  NON-ALPHS (True-False=True counts
       if (input_string[i] == 'A' || input_string[i] == 'a')
           a++;
       else if (input_string[i] == 'B' || input_string[i] == 'b')
           b++;
       else if (input_string[i] == 'C' || input_string[i] == 'c')
           c++;
       else if (input_string[i] == 'D' || input_string[i] == 'd')
           d++;
       else if (input_string[i] == 'E' || input_string[i] == 'e')
           e++;
       else if (input_string[i] == 'F' || input_string[i] == 'f')
           f++;
       else if (input_string[i] == 'G' || input_string[i] == 'g')
           g++;
       else if (input_string[i] == 'H' || input_string[i] == 'h')
           h++;
       else if (input_string[i] == 'I' || input_string[i] == 'i')
           I++;
       else if (input_string[i] == 'J' || input_string[i] == 'j')
           j++;
       else if (input_string[i] == 'K' || input_string[i] == 'k')
           k++;
       else if (input_string[i] == 'L' || input_string[i] == 'l')
           l++;
       else if (input_string[i] == 'M' || input_string[i] == 'n')
           m++;
       else if (input_string[i] == 'N' || input_string[i] == 'n')
           N++;
       else if (input_string[i] == 'O' || input_string[i] == 'o')
           o++;
       else if (input_string[i] == 'P' || input_string[i] == 'p')
           p++;
       else if (input_string[i] == 'Q' || input_string[i] == 'q')
           q++;
       else if (input_string[i] == 'R' || input_string[i] == 'r')
           r++;
       else if (input_string[i] == 'S' || input_string[i] == 's')
           s++;
       else if (input_string[i] == 'T' || input_string[i] == 't')
           t++;
       else if (input_string[i] == 'U' || input_string[i] == 'u')
           u++;
       else if (input_string[i] == 'V' || input_string[i] == 'v')
           v++;
       else if (input_string[i] == 'W' || input_string[i] == 'w')
           w++;
       else if (input_string[i] == 'X' || input_string[i] == 'x')
           x++;
       else if (input_string[i] == 'Y' || input_string[i] == 'y')
           y++;
       else if (input_string[i] == 'Z' || input_string[i] == 'z')
           z++;
       else
           Non_Alphabet++; 
   }
   
      int Alphabet = a+b+c+d+e+f+g+h+I+j+k+l+m+N+o+p+q+r+s+t+u+v+w+x+y+z; //calculates how many alphs letter are in. later use it in Alphabet output.
      
      //PAIRS
      for(int i=0; i<input_string.size()-1; i++) 
          {
        if(input_string[i]==input_string[i+1])
            {
            p_pairs++;
        }
      }
      
   // writes the output to the file
   fout << "a:" << a << endl;
   fout << "b:" << b << endl;
   fout << "c:" << c << endl;
   fout << "d:" << d << endl;
   fout << "e:" << e << endl;
   fout << "f:" << f << endl;
   fout << "g:" << g << endl;
   fout << "h:" << h << endl;
   fout << "i:" << I << endl;
   fout << "j:" << j << endl;
   fout << "k:" << k << endl;
   fout << "l:" << l << endl;
   fout << "m:" << m << endl;
   fout << "n:" << N << endl;
   fout << "o:" << o << endl;
   fout << "p:" << p << endl;
   fout << "q:" << q << endl;
   fout << "r:" << r << endl;
   fout << "s:" << s << endl;
   fout << "t:" << t << endl;
   fout << "u:" << u << endl;
   fout << "v:" << v << endl;
   fout << "w:" << w << endl;
   fout << "x:" << x << endl;
   fout << "y:" << y << endl;
   fout << "z:" << z << endl;
   
   
   //OUTPUS FOR ALPH & NON-ALPHS &  AVERAGE
   fout << "alphabets:" << Alphabet << endl; //calculated alphs
   fout << "non-alphabets:" << Non_Alphabet << endl; //else statement goes over and calculated with for loop -- this is the displayed output
   fout << "average:" << Alphabet/26.0 << endl; //gets alphabet and divedes by 26 to find the average-- this is the displayed output
   fout << "pairs:" << p_pairs <<endl; //-- this is the displayed output for pairs
}


//OUTPUT FILE
void Parser::outputToFile(string file)
{
   // Creating & opening  outputt.txt
   ofstream outFile;
   outFile.open(file);

   all_functions(outFile);  //display all_functions parts.
   //pairs(outFile); //displays pairs. 
   outFile.close(); 
}