#ifndef LISTNODE_H
#define LISTNODE_H
#include <stddef.h>
using namespace std;

template <class Type>
class ListNode {
    public:
        ListNode(Type d);
        ~ListNode();

        Type data;
        ListNode *next;
        ListNode *prev;
        ListNode(const ListNode& other);
        ListNode& operator=(const ListNode& other);

    private:
        ListNode();
};

template <class Type>
ListNode<Type>::ListNode(Type d)
{
	data = d;
	prev = NULL;
	next = NULL; //nullptr
}

template <class Type>
ListNode<Type>::~ListNode()
{
	
}

template <class Type>
ListNode<Type>::ListNode(const ListNode& other) {
    // copy data
    data = other.data;

    // create new node with same data
    next = new ListNode(other.next->data);
    prev = new ListNode(other.prev->data);

    // copy links
    next = other.next;
    prev = other.prev;
}

template <class Type>
ListNode<Type>& ListNode<Type>::operator=(const ListNode& other) {
    // check for self-assignment
    if (this != &other) {
        // copy data
        data = other.data;

        // create new node with same data
        next = new ListNode(other.next->data);
        prev = new ListNode(other.prev->data);

        // copy links
        next = other.next;
        prev = other.prev;
    }
    return *this;
}

#endif