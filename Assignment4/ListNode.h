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

#endif