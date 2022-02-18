#include <fstream>
#include "parser.h"

using namespace std;
Parser::Parser(string str)
{
   input_string = str;
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
       if (input_string[i] == 'a' || input_string[i] == 'A')
           a++;
       else if (input_string[i] == 'b' || input_string[i] == 'B')
           b++;
       else if (input_string[i] == 'c' || input_string[i] == 'C')
           c++;
       else if (input_string[i] == 'd' || input_string[i] == 'D')
           d++;
       else if (input_string[i] == 'e' || input_string[i] == 'E')
           e++;
       else if (input_string[i] == 'f' || input_string[i] == 'F')
           f++;
       else if (input_string[i] == 'g' || input_string[i] == 'G')
           g++;
       else if (input_string[i] == 'h' || input_string[i] == 'H')
           h++;
       else if (input_string[i] == 'i' || input_string[i] == 'I')
           I++;
       else if (input_string[i] == 'j' || input_string[i] == 'J')
           j++;
       else if (input_string[i] == 'k' || input_string[i] == 'K')
           k++;
       else if (input_string[i] == 'l' || input_string[i] == 'L')
           l++;
       else if (input_string[i] == 'm' || input_string[i] == 'M')
           m++;
       else if (input_string[i] == 'n' || input_string[i] == 'N')
           N++;
       else if (input_string[i] == 'o' || input_string[i] == 'O')
           o++;
       else if (input_string[i] == 'p' || input_string[i] == 'P')
           p++;
       else if (input_string[i] == 'q' || input_string[i] == 'Q')
           q++;
       else if (input_string[i] == 'r' || input_string[i] == 'R')
           r++;
       else if (input_string[i] == 's' || input_string[i] == 'S')
           s++;
       else if (input_string[i] == 't' || input_string[i] == 'T')
           t++;
       else if (input_string[i] == 'u' || input_string[i] == 'U')
           u++;
       else if (input_string[i] == 'v' || input_string[i] == 'V')
           v++;
       else if (input_string[i] == 'w' || input_string[i] == 'W')
           w++;
       else if (input_string[i] == 'x' || input_string[i] == 'X')
           x++;
       else if (input_string[i] == 'y' || input_string[i] == 'Y')
           y++;
       else if (input_string[i] == 'z' || input_string[i] == 'Z')
           z++;
       else
           Non_Alphabet++; 
   }
   
   
      int Alphabet = a+b+c+d+e+f+g+h+I+j+k+l+m+N+o+p+q+r+s+t+u+v+w+x+y+z;
      
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
   fout << "alphabets:" << Alphabet << endl;
   fout << "non-alphabets:" << Non_Alphabet << endl;
   fout << "average:" << Alphabet/26.0 << endl;
   fout << "pairs:" << p_pairs <<endl;
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