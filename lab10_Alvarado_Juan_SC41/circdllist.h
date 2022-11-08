#ifndef CIRCDLLIST_H
#define CIRCDLLIST_H


/**********************
	COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
	Circular Doubly linked List
	This class implements the circular doubly linked list using templates
	Each list has one attribute:
		-head: the node that you are step in

	Considerations:
	1. head point to null in an empty list
	2. There is not need of a tail pointer
******************/

/*
	Place you information here.
*/

#include "intDLLNode.h"

template <class T>
class circDLList{
public:
	// Default constructor: creates an empty list
	circDLList();

	// Destructor: deallocate memory
	~circDLList();

	// addToHead(T val): creates a new node with val as info,
	// and this new node is the new head
	void addToHead(T val);

	// addToTail(T val): creates a new node with val as info,
	// and this new node is the new tail
	void addToTail(T val);

	// deleteFromHead: remove head from the list,
	// the new head is the previous head->next
	// if the list had only one node, head and tail point null
	void deleteFromHead();

	// deleteFromTail: remove tail from the list,
	// the new tail is the previous node to tail
	// if the list had only one node, head and tail point null
	void deleteFromTail();

	// In the list is empty, returns true
	// otherwise, returns false
	bool isEmpty();

	// printList(): prints all nodes in the list from head to tail
	void printList();

	// printList(): prints all nodes in the list from tail to head
	void printRevList();

private:
	IntDLLNode<T> *head; // A pointer to the first node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while(!isEmpty())
		this->deleteFromHead();
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void circDLList<T>::printList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getNext() != head) {
			cout << prtNode->getInfo() << " ";
			prtNode = prtNode->getNext();
		}
		cout << prtNode->getInfo() << " ";
	}
}

/***********************
	printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void circDLList<T>::printRevList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getPrev() != head) {
			prtNode = prtNode->getPrev();
			cout << prtNode->getInfo() << " ";
		}
		cout << head->getInfo() << " ";
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool circDLList<T>::isEmpty()
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
void circDLList<T>::addToHead(T val)
{
	if (head != 0){
		// Not an empty list
		IntDLLNode<T> *tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		head = tmp;
	}
	else {
		//An empty list
		cout << "Empty list" << endl;
		head = new IntDLLNode<T>(0, val, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

template <class T>
void circDLList<T>::addToTail(T val)
{

	if (head != 0) {
       IntDLLNode<T> *tmp = new IntDLLNode<T>(0, val, 0);
       if (head == head->getNext())
       {
           head->setNext(tmp);
           tmp->setPrev(head);
           tmp->setNext(head);
           head->setPrev(tmp);
       }
       else
       {
           IntDLLNode<T> *curr = head->getNext();
           while (curr->getNext() != head)
           {
               curr = curr->getNext();
           }
           tmp->setNext(curr->getNext());
           tmp->setPrev(curr);
           curr->setNext(tmp);
           head->setPrev(tmp);
       }
   }
   else {


       head = new IntDLLNode<T>(0, val, 0);
       head->setPrev(head);
       head->setNext(head);
   }
}

template <class T>
void circDLList<T>::deleteFromHead()
{
	if (head != 0)
	{
		IntDLLNode<T> *tmp;
		tmp = head;
		if (head == head->getNext()) {
			//One node list
			head = 0;
		}
		else {
			//list with more than one node
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
			head = head->getNext();
		}
		delete tmp;
	}
}

template <class T>
void circDLList<T>::deleteFromTail()
{
	 if (head != 0)
   {
       IntDLLNode<T> *curr;
       IntDLLNode<T> *prev;
       curr = head;
       prev = curr;
       if (head == head->getNext()) {

           head = 0;
       }
       else
       {
           while (curr->getNext() != head)
           {
               prev = curr;
               curr = curr->getNext();
           }
           prev->setNext(curr->getNext());
           curr->getNext()->setPrev(prev);
           delete curr;
       }
   }
}


#endif // CIRCDLLIST_H
