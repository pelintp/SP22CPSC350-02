#include <iostream>
#include <fstream>
#include <string>
#include "DelimiterFinder.h"
using namespace std;

int main(int argc, char** argv ) {
    //takes command line
	string filename;
	ifstream inFile;
	if (argv[1] != NULL) {
		filename = argv[1];
	}
	else
	{
        // if not enter file name
		cout << "Enter your file name: "; 
		cin >> filename;
	}
	do {
		inFile.open(filename);
		if (inFile.good() == true) {
			continue;
		}
		else {
			cout << "Invalid filename reenter: ";
			cin >> filename;
		}
	} while (inFile.good() != true);

	DelimiterFinder *Checker = new DelimiterFinder(filename); 
	Checker->check_file();

	delete Checker;
	system("pause");
	return 0; 
    //end program
}
