#include "DelimiterFinder.h"

//Default constructor
DelimiterFinder::DelimiterFinder() 
{
	new_ask();
}

// Overloaded constructor
DelimiterFinder::DelimiterFinder(string p) 
{
	filename = p;
	delimiter1 = 0; //(
	delimiter2 = 0; //{
	delimiter3 = 0; //[
}

// Default destructor
DelimiterFinder::~DelimiterFinder() 
{

}

void DelimiterFinder::check_file() 
//finds delimeters from the file then inserts them into the stack
{
	string line;
	code.open(filename);
	count_line = 0;
	while (code.good()) {
		count_line++;
		getline(code, line);
		for (int i = 0; i < line.length(); ++i) {
			switch (line[i]) {
			case '{':
				stack.push('{');
				delimiter2 = count_line;
				break;
			case'(':
				stack.push('(');
				delimiter1 = count_line;
				break;
			case'[':
				stack.push('[');
				delimiter3 = count_line;
				break;
			case'}':
				if (stack.empty_stack()) {
					throwException(count_line, '{');
					return;
				}
				else if (stack.peek() == '(') {
					stack.pop();
					throwException(delimiter1, ')');
					return;
				}
				else if (stack.peek() == '[') {
					stack.pop();
					throwException(delimiter3, ']');
					return;
				}
				else {
					stack.pop();
				}
				break;
			case')':
				if (stack.empty_stack()) {
					throwException(count_line, '(');
					return;
				}
				else if (stack.peek() == '{') {
					stack.pop();
					throwException(delimiter2, '}');
					return;
				}
				else if (stack.peek() == '[') {
					stack.pop();
					throwException(delimiter3, ']');
					return;
				}
				else {
					stack.pop();
				}
				break;
			case']':
				if (stack.empty_stack()) {
					throwException(count_line, '[');
					return;
				}
				else if (stack.peek() == '(') {
					stack.pop();
					throwException(delimiter1, ')');
					return;
				}
				else if (stack.peek() == '{') {
					stack.pop();
					throwException(delimiter2, '}');
					return;
				}
				else {
					stack.pop();
				}
				break;
			}

		}
	}
	code.close();
	if (stack.empty_stack()) {
		new_ask();
	}
	else {
		switch (stack.pop()) {
		case'(':
			throwException(delimiter1, ')');
			break;
		case'[':
			throwException(delimiter3, ']');
			break;
		case'{':
			throwException(delimiter2, '}');
			break;
		}
	}
}

void DelimiterFinder::throwException(int l, char e) 
//shows what and where  the error is
{
	cout << "Line: " << l << " Expected: " << e << endl;
}

void DelimiterFinder::new_ask() 
// no error were find
{
	choose = true;
	cout << "No Errors were find in this file!\n";
    while (choose) {
		cout << "Do you want to check another file? Enter '1' for yes.  Enter '2' for no.  ";
		cin >> continue_program;
		if (cin.fail()) {
			cout << "Enter either 1 or 2.";
			cin.clear();
			cin.ignore();
		}
		else if (continue_program < 1 || continue_program > 2) {
			cout << "Enter either 1 or 2.";
		}
		else if(continue_program == 1) {
			choose = false;
			runScript();
		}
		else if (continue_program == 2) {
			choose = false;
		}
	}
}

void DelimiterFinder::runScript() 
//asks file name and reruns.
{
	cout << "Enter your filename: ";
	cin >> filename;
	do {
		code.open(filename);
		if (code.good() == true) {
			continue;
		}
		else {
			cout << "Invalid filename";
			cin >> filename;
		}
	} while (code.good() != true);
	check_file();
}