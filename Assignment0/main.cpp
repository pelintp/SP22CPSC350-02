#include "mydemo.h"

int main(int argc, char **argv){
    printHelloWorld sc; // on the stack
    printHelloWorld *sc2 = new printHelloWorld(); // on the heap

std::cout << "Hello World!" << std::endl;

delete sc2;
return 0;
}
