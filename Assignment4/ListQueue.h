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
	Type getFront();
	ListQueue(const ListQueue<Type>& other);


	Type& getAt(int i);
	bool isFull();
	bool isEmpty();
	int getSize();
	ListQueue<Type>& operator=(const ListQueue<Type>& other) {
		if (this != &other) {
			delete list;
			list = new DblList<Type>(*other.list);
		}
		return *this;
	}



private:
	DblList<Type>* list;
};

template<class Type>
Type& ListQueue<Type>::getAt(int index) {
	return list->getAt(index);
}

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
        std::__throw_runtime_error("error empty");
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

template<class Type>
Type ListQueue<Type>::getFront() {
	if (!this->isEmpty()) {
		return list->front->data;
	} else {
		std::__throw_runtime_error("error: empty");
	}
}

template<class Type>
ListQueue<Type>::ListQueue(const ListQueue<Type>& other) {
    list = new DblList<Type>(*other.list);
}



#endif