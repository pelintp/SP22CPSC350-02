#include <iostream>
using namespace std;

//Template class allow you to stack take any data
template <class T> 
class AStack
{
private:
	int top_data, mSize;
	T *myArray, *tempArray;
public:
	AStack();
	AStack(int);
	~AStack();

	void push(T);
	T pop();
	T peek();
	void resizeStack();

	bool full_stack();
	bool empty_stack();
	int size_stack();
};

template <class T>
//Default constructor
AStack<T>::AStack()
{
	myArray = new char[256];
	tempArray = new char[256];
	mSize = 50;
	top_data = -1;
}

template <class T>
//Overloaded constructor
AStack<T>::AStack(int maxSize)
{
	myArray = new char[maxSize];
	tempArray = new char[maxSize];
	mSize = maxSize;
	top_data = -1;
}

template <class T>
// Destructor delete dynamic arrays
AStack<T>::~AStack() 
{
	delete myArray;
	delete tempArray;
}

template <class T>
//Pusing data to top of the stack
void AStack<T>::push(T data) 
{
	if (full_stack()) {
		cout << "Stack is full";
		resizeStack();
		cout << "Doubled stack";
		myArray[++top_data] = data;
	}
	else {
		top_data++;
		myArray[top_data] = data;
	}

}

template <class T>
// Pop function removes the top item from the stack
T AStack<T>::pop() 
{
	if (empty_stack()) {
		return '\0';
	}
	return myArray[top_data--];
}

template <class T>
// Peek function return (not deletes) the top item from the stack
T AStack<T>::peek() 
{
	if (empty_stack()) {
		return '\0';
	}
	return myArray[top_data];
}

template <class T>
 //checks if the stack is empty
bool AStack<T>::empty_stack() 
{
	return (top_data == -1);
}

template <class T>
//checks if the stack is full
bool AStack<T>::full_stack() 
{
	return (top_data == mSize - 1);
}

template <class T>
//shows how many data are in the stack
int AStack<T>::size_stack() 
{
	return (top_data + 1);
}

template <class T>
//doubles the stack size
void AStack<T>::resizeStack() 
{
	int oldSize = mSize;
	delete tempArray;
	tempArray = new char[oldSize];
	mSize = mSize*2;
	for (int i = 0; i < oldSize; ++i) {
		tempArray[i] = myArray[i];
	}
	delete myArray;
	myArray = new char[mSize];
	for (int i = 0; i < oldSize; ++i) {
		myArray[i] = tempArray[i];
	}
}