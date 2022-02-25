#include "FileProcessor.h"
#include "Translator.h" // Since I create an object of the Translator class, I have to include the Translator header file here
#include <fstream> 
#include <iostream>



FileProcessor::FileProcessor(){} //default constructor 
FileProcessor::~FileProcessor(){} //default destructor

void FileProcessor::processFile(string inputName, string outputName){
// use fstream objects to read and write to files
    
    Translator converter;
    string words; //input words
    string tutnese; //tutnese words
    ofstream resultText(outputName);//tutnese translation
    ifstream inFile(inputName);//english sentences
    
    
    
   
    
    if(inFile.is_open()){ //The input text file has to be in the same file as the program
        
        while(getline(inFile, words)){ //reading the input file
            
            tutnese = converter.translateEnglishSentence(words);
            resultText << tutnese << "\n"; //newline
        }
        inFile.close();//closing input file
    }
    resultText.close(); //closing output file
}