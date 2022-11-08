/**********************
COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
Singly linked List
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next = null
******************/

#ifndef INTSLLIST_H
#define INTSLLIST_H
#include "IntSLLNode.h"

template <class T>
class IntSLList{
public:
	//Default constructor: creates an empty list
	IntSLList();

	//Destructor: deallocate memory
	~IntSLList();

	//addToHead(T val): creates a new node with val as info,
	//and this new node is the new head
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info,
	//and this new node is the new tail
	void addToTail(T val);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//If the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printList(): prints all nodes in the list
	void printList();
private:
	IntSLLNode<T> *head; //A pointer to the first node
	IntSLLNode<T> *tail; //A pointer to the last node
};



/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntSLList<T>::IntSLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntSLList<T>::~IntSLList()
{
	//Declare a pointer prtNode
	IntSLLNode<T> *prtNode;
	//prtNode points head
	prtNode = head;

	//While there is a node in the list, remove it
	while(prtNode != 0)
	{
		//prtNode points head->next
		prtNode = head->getNext();

		//delete head
		delete head;

		//the new head is prtNode
		head = prtNode;
	}
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void IntSLList<T>::printList()
{
	IntSLLNode<T>* prtNode;
	prtNode = head;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo() << " ";
		prtNode = prtNode->getNext();
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool IntSLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}

	return res;
}

/***********************
	Implement other methods
***********************/

template <class T>
void IntSLList<T>::addToHead(T val)
{
	    head = new IntSLLNode<T>(val,head);
if (tail == nullptr)
tail = head;
}

template <class T>
void IntSLList<T>::addToTail(T val)
{
	if(head == nullptr)
    head = tail = new IntSLLNode<T>(val, nullptr);

    else{

  tail->next = new IntSLLNode<T>(val, nullptr);
  tail = tail->next;


    }
}

template <class T>
void IntSLList<T>::deleteFromHead()
{
	if(head){

IntSLLNode <T>*nodeptr = head;
head = head->next;
delete nodeptr;

while(nodeptr->next != nullptr){

cout << nodeptr->info << " ";
nodeptr = nodeptr->next;

}

}

}

template <class T>
void IntSLList<T>::deleteFromTail()
{
	if (head == tail) {

delete head;
head = tail = 0;
}

else {
IntSLLNode <T>*tmp;
for (tmp = head; tmp->next != tail; tmp = tmp->next);
delete tail;
tail = tmp;
tail->next = 0;
}
}

//template class IntSLList<int>;
#endif //
