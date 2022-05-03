#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T> class IList
{
public:
	virtual void clear() = 0;

	virtual int size() = 0;
	virtual bool isEmpty() = 0;

	virtual bool removeFront() = 0;
	virtual bool removeBack()  = 0;

	virtual void insertFront(const T& item) = 0;
	virtual void insertBack(const T& item) = 0;

	virtual T peekFront() = 0;
	virtual T peekBack() = 0;
};

template <typename T>
class ListNode
{
public:
	ListNode<T>(const T& data, ListNode<T>* next = nullptr, ListNode<T>* prev = nullptr);

	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
};

template <typename T>
ListNode<T>::ListNode(const T& data, ListNode<T>* next, ListNode<T>* prev) :
	data(data), next(next), prev(prev) {}


template<typename T>
class List : public IList<T>
{
public:
	List<T>();
	virtual ~List<T>();

	void clear();

	int size();
	bool isEmpty();

	bool removeFront();
	bool removeBack();

	void insertFront(const T& item);
	void insertBack(const T& item);

	bool find(T data);
	// T get(T data);
	bool remove(T data);

	T peekFront();
	T peekBack();

private:
	ListNode<T>* front;
	ListNode<T>* back;
	int isize;

};

template <typename T>
List<T>::List() {
	front = back = nullptr;
	isize = 0;
}

template <typename T>
List<T>::~List() {
	clear();
}
template <typename T>
void List<T>::clear()
{
	//create new node
	ListNode<T>* current = front;

	//delete
	while (current != nullptr)
	{
		ListNode<T>* temp = current;

		current = current->next;

		delete temp;
	}

	front = back = nullptr;
	isize = 0;
}


template <typename T>
bool List<T>::isEmpty() { //constatnt
	return isize == 0;
}

template <typename T>
int List<T>::size() { //constant
	return isize;
}

template <typename T>
bool List<T>::removeBack() { //remove from front of queue
	//check if empty
	if (isEmpty()) {
		//if the back is empty then return
		return false;
	}
	//if single element
	else if (isize == 1)
	{
		clear();

		return true;
	}
	else
	{
		ListNode<T>* temp = back;

		back = back->prev;

		//back to next = temp;
		back->next = nullptr;

		delete temp;
		return true;
	}

	//decrement the size
	--isize;
}

template <typename T>
bool List<T>::removeFront() {
	//remove from front of queue
	//check if empty
	if (isEmpty()) {
		//if the front is empty then return
		return false;
	}
	//if single element
	else if (isize == 1)
	{
		clear();

		return true;
	}
	else
	{
		ListNode<T>* temp = front;

		front = front->next;

		front->prev = nullptr;

		delete temp;
		return true;
	}
	//decrement the size
	--isize;
}

template <typename T>
void List<T>::insertFront(const T& item) {
	//insert at the back of queue
	//create new node
	ListNode<T>* newNode = new ListNode<T>(item, front);

	// assign newNode to the front pointer
	front = newNode;

	if (isize == 0)
		back = newNode;

	++isize;
}

template <typename T>
void List<T>::insertBack(const T& item) { //insert at the back of queue
	//create new node
	ListNode<T>* newNode = new ListNode<T>(item, nullptr, back);

	// assign new node to the back pointer
	if (isize == 0)
	{
		front = back = newNode;
	}
	else
	{
		back->next = newNode;
	}

	back = newNode;

	//increment the size
	++isize;
}

template <typename T>
T List<T>::peekFront() {
	return front->data;
}

template <typename T>
T List<T>::peekBack() {
	return back->data;
}

template <typename T> bool List<T>::find(T data) {
	T find;

	ListNode<T> *current = front;
	while(current != NULL){

		if(current->data == data) {
			return true;
		}
		else {
			current = current->next;
		}
	}

	return false;
}




template <typename T> bool List<T>::remove(T data) {
	T find;

	ListNode<T> *current = front;
	while(current->data != data){
		if (current == NULL) {
			cout << "Could not find item to delete." << endl;
			return false;
		}
		current = current->next;

	}
	if (current == back) {
		removeBack();
	}
	else if (current == front){
		removeFront();
	}
	else{
		// need to rearrange nodes
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current->next = NULL;
		current->prev = NULL;
		delete current;
		return true;
	}
	// if current not equal  NULL
	// 	return find
	return false;
}

#endif // !LIST_H
