#ifndef QUEUE_H
#define QUEUE_H


#include "List.h"

template<typename T>
class Queue
{
public:
	void pop();
	void push(const T& item);

	T front();
	T back();

	int size();
	bool isEmpty();

private:
	List<T> list;

};


template<typename T>
void Queue<T>::pop() { list.removeFront(); }

template<typename T>
void Queue<T>::push(const T& item) { list.insertBack(item); }

template<typename T>
T Queue<T>::front() {return list.peekFront(); }

template<typename T>
T Queue<T>::back() { return list.peekBack(); }

template<typename T>
int Queue<T>::size() { return list.size(); };

template<typename T>
bool Queue<T>::isEmpty() { return list.isEmpty(); }

#endif // QUEUE_H
