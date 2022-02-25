#include "Translator.h"
#include "Model.h"

using namespace std;



Translator::Translator(){}
Translator::~Translator(){} 

//english to tutnese
string Translator::translateEnglishWord(string word){
    Model model;
    string result = "";
    char temp = 'a';
    for(int i = 0; i < word.length(); ++i){
        
        temp = word[i];        

        
        if(tolower(temp) == tolower(word[i+1]) && (temp >= 'a' && temp <= 'z')){
            result += model.translateDoubleCharacter(temp);
            i++;
        }
        else{
            result += model.translateSingleCharacter(temp);
        }
    }

    return result;

} 

//ENGLISH TO TUTNESE
string Translator::translateEnglishSentence(string sent){
    string result = ""; //string in fully tutnese

    char l = 'a'; 
    
    
    string word = ""; //hold the word that will be translated
    for(int i = 0; i < sent.length(); ++i){

        //checks the space
        if(sent[i] == ' '){
            result += translateEnglishWord(word);
            word = ""; 
            result += " "; 
           
        }
        //else add the char to the temp string 
        else{
            l = sent[i];
            word += l;
                        
        }
       
       
        
    }
    //After the for-loop ends this will translate whatever is left inside the temp string
    result += translateEnglishWord(word);
    return result;
}