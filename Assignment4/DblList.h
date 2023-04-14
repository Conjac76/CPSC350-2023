#ifndef DblList_H
#define DblList_H

#include "ListNode.h"
#include <iostream>

template <class Type>
class DblList {
public:
    DblList();
    ~DblList();

    void insertFront(Type d);
    Type removeFront();
    Type removeBack();
    Type deletePos(int pos);
    Type getFront();
    int find(Type value);
    bool isEmpty();

    void printList();
    unsigned int getSize();
    ListNode<Type>* remove(Type key);
    ListNode<Type> *front;
    ListNode<Type> *back;
    unsigned int size;
};

template <class Type>
DblList<Type>::DblList() {
    back = nullptr;
    front = nullptr;
    size = 0;
}

template <class Type>
DblList<Type>::~DblList() {
    ListNode<Type> *current = front;
    while (current != nullptr) {
        ListNode<Type> *temp = current->next;
        delete current;
        current = temp;
    }
}

template <class Type>
unsigned int DblList<Type>::getSize() {
    return size;
}

template <class Type>
void DblList<Type>::printList() {
    ListNode<Type> *current = front;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

template <class Type>
void DblList<Type>::insertFront(Type d) {
    ListNode<Type> *node = new ListNode<Type>(d);
    if (size == 0) {
        back = node;
    }
    else {
        front->prev = node;
        node->next = front;
    }
    front = node;
    ++size;
}

template <class Type>
Type DblList<Type>::removeFront() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    ListNode<Type> *temp = front;
    if (front->next == nullptr) {
        back = nullptr;
    }
    else {
        front->next->prev = nullptr;
    }
    front = front->next;
    temp->next = nullptr;
    Type data = temp->data;
    delete temp;
    --size;
    return data;
}

template <class Type>
Type DblList<Type>::removeBack() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    ListNode<Type> *temp = back;
    if (back->prev == nullptr) {
        front = nullptr;
    }
    else {
        back->prev->next = nullptr;
    }
    back = back->prev;
    temp->prev = nullptr;
    Type data = temp->data;
    delete temp;
    --size;
    return data;
}

template <class Type>
int DblList<Type>::find(Type value) {
    int index = -1;
    ListNode<Type> *current = front;
    while (current != nullptr) {
        ++index;
        if (current->data == value) {
            break;
        }
        else {
            current = current->next;
        }
    }
    if (current == nullptr) {
        index = -1;
    }
    return index;
}

template <class Type>
Type DblList<Type>::deletePos(int pos)
{
	--size;
	int index =0;
	ListNode<Type> *curr = front;
	ListNode<Type> *prev = front;
	while (index!=pos) 
	{
		prev = curr;
		curr = curr->next;
		++index;
	}

	prev->next = curr->next;
	curr->next = NULL;
	Type d = curr-> data;
	delete curr;
	return d;

}

template <class Type>
ListNode<Type>* DblList<Type>::remove(Type key)
{
	ListNode<Type>* current = front;
	while(current->data!=key)
	{
		current = current->next;
		if (current == NULL)
			return NULL;
	}

	if (current == front)
	{
		front = current->next;
	}

	else
	{
		current->prev->next = current->next;
	}

	if(current == back)
	{
		back = current->prev;
	}

	else
	{
		current->next->prev = current->prev;
	}
	current->next = NULL;
	current ->prev = NULL;
	--size;
	return current;
}

template<class Type>
bool DblList<Type>::isEmpty() {
	return this->getSize() == 0;
}

template <class Type>
Type DblList<Type>::getFront() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    return front->data;
}

#endif