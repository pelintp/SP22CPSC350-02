#include <iostream>
#include <fstream>
#include <string>
#include "AStack.h"
using namespace std;

class DelimiterFinder
{
private:
	ifstream code;
	AStack<char> stack;
	int count_line, 
    delimiter1, //(
    delimiter2, //{
    delimiter3, //[
    continue_program;
	string filename;
	bool choose;
public:
	DelimiterFinder();
	DelimiterFinder(string);
	~DelimiterFinder();
	void runScript();
 	void new_ask();
	void check_file();
	void throwException(int, char);

};