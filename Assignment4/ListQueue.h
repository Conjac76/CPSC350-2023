#ifndef ListQueue_H
#define ListQueue_H

#include <iostream>
#include "DblList.h"

template <class Type>
class ListQueue {
public:
	ListQueue();	
	~ListQueue();
	void enqueue(Type data);
	Type dequeue();
	Type peek();

	bool isFull();
	bool isEmpty();
	int getSize();

private:
	DblList<Type>* list;
};

template<class Type>
ListQueue<Type>::ListQueue() {
	list = new DblList<Type>();
}

template<class Type>
ListQueue<Type>::~ListQueue() {
	delete list;
}

template<class Type>
void ListQueue<Type>::enqueue(Type data) {
	list->insertFront(data);
}

template<class Type>
Type ListQueue<Type>::dequeue() {
	if (!this->isEmpty()) {
		return list->removeBack();
    }
    else {
        std::__throw_runtime_error("ERROR: EMPTY");
    }
}

template <class Type>
Type ListQueue<Type>::peek() {
	if (!this->isEmpty()) {
		return list->back->data;
    } else {
        //Error List empty
    }
}

template <class Type>
bool ListQueue<Type>::isEmpty() {
	return list->isEmpty();
}

template<class Type>
bool ListQueue<Type>::isFull() {
    return false;
}

template<class Type>
int ListQueue<Type>::getSize() {
    return list->getSize();
}


#endif