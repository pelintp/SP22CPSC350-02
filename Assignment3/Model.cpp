#include "Model.h"
#include <iostream>
#include <string>

using namespace std;

Model::Model(){} //default constructor

Model::~Model(){} //default destructor


string Model::translateSingleCharacter(char c){ // code that translates each letter
    if(c == 'B'){
        return "Bub";}
    else if(c == 'b'){
        return "bub";}
        
        
    else if(c == 'C'){
        return "Cash";}
    else if(c == 'c'){
        return "cash";}
        
        
    else if(c == 'D'){
        return "Dud";}
    else if(c == 'd'){
        return "dud";}
        
        
    else if(c == 'F'){
        return "Fuf";}
    else if(c == 'f'){
        return "fuf";}
        
        
    else if(c == 'G'){
        return "Gug";}
    else if(c == 'g'){
        return "gug";}
        
        
    else if(c == 'H'){
        return "Hash";}
    
    else if(c == 'h'){
        return "hash";}
    
    
    else if(c == 'J'){
        return "Jay";}
    else if(c == 'j'){
        return "jay";}
        
        
    else if(c == 'K'){
        return "Kuck";}
    else if(c == 'k'){
        return "kuck";}
    
    
    else if(c == 'L'){
        return "Lul";}
    else if(c == 'l'){
        return "lul";}
    
    
    else if(c == 'M'){
        return "Mum";}
    else if(c == 'm'){
        return "mum";}
        
        
    else if(c == 'N'){
        return "Nun";}
    else if(c == 'n'){
        return "nun";}
    
    
    else if(c == 'P'){
        return "Pub";}
    else if(c == 'p'){
        return "pub";}
    
    
    else if(c == 'Q'){
        return "Quack";}
    else if(c == 'q'){
        return "quack";}
        
        
    else if(c == 'R'){
        return "Rug";}
    else if(c == 'r'){
        return "rug";}
    
    
    else if(c == 'S'){
        return "Sus";}
    else if(c == 's'){
        return "sus";}
    
    
    else if(c == 'T'){
        return "Tut";}
    else if(c == 't'){
        return "tut";}
    
    
    
    else if(c == 'V'){
        return "Vuv";}
    else if(c == 'v'){
        return "vuv";}
    
    
    else if(c == 'W'){
        return "Wack";}
    else if(c == 'w'){
        return "wack";}
    
    
    else if(c == 'X'){
        return "Ex";}
    else if(c == 'x'){
        return "ex";}
    
    
    else if(c == 'Y'){
        return "Yub";}
    else if(c == 'y'){
        return "yub";}
        
        
    else if(c == 'Z'){
        return "Zub";}
    else if(c == 'z'){
        return "zub";}
        
        
    //converts charachters to string
    else{
        string l = "";
        l += c;
        return l;
    }

}


string Model::translateDoubleCharacter(char c){  //code that describes scenario for letter pairs
    //checks if it upper
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        {return "Squat" + tolower(c);} //calls the last method tolower for capitalization --output
    
    //checks if it lower
    //tutnese convert
    else if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) 
        {string l = "";
        l += c; 
        return "squat" + l;} 
    
    else{
        return "squa" + translateSingleCharacter(c); //for the constant
    }
}


//turns into lower
string Model::tolower(char l){
    if(l == 'A'){
        return "a";}
        
        
    if(l == 'B'){
        return "b";}
        
        
    if(l == 'C'){
        return "c";}
        
        
    if(l == 'D'){
        return "d";}
        
        
    if(l == 'E'){
        return "e";}
        
        
    if(l == 'F'){
        return "f";}
        
        
    if(l == 'G'){
        return "g";}
        
        
    if(l == 'H'){
        return "h";}
        
        
    if(l == 'I'){
        return "i";}
        
        
    if(l == 'J'){
        return "j";}
        
        
    if(l == 'K'){
        return "k";}
        
        
    if(l == 'L'){
        return "l";}
        
        
    if(l == 'M'){
        return "m";}
        
        
    if(l == 'N'){
        return "n";}
        
        
    if(l == 'O'){
        return "o";}
        
        
    if(l == 'P'){
        return "p";}
        
        
    if(l == 'Q'){
        return "q";}
        
        
    if(l == 'R'){
        return "r";}
        
        
    if(l == 'S'){
        return "s";}
        
        
    if(l == 'T'){
        return "t";}
        
        
    if(l == 'U'){
        return "u";}
        
        
    if(l == 'V'){
        return "v";}
        
        
    if(l == 'W'){
        return "w";}
        
        
    if(l == 'X'){
        return "x";}
        
        
    if(l == 'Y'){
        return "y";}
        
        
    if(l == 'Z'){
        return "z";}

return 0;

}