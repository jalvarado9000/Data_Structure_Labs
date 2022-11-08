#ifndef INTDLLIST_H
#define INTDLLIST_H
/**********************
COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
Double linked List
This class implements the double linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next = null
******************/

#include "IntDLLNode.h"

template <class T>
class IntDLList{
public:
	//Default constructor: creates an empty list
	IntDLList();

	//Destructor: deallocate memory
	~IntDLList();

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

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printRevList(): prints all nodes in the list from tail to head
	void printRevList();

private:
	IntDLLNode<T> *head; //A pointer to the first node
	IntDLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntDLList<T>::IntDLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntDLList<T>::~IntDLList()
{
	//Declare a pointer prtNode
	IntDLLNode<T> *prtNode;
	//prtNode points head
	prtNode = head;

	//While there is a node in the list, remove it
	while (prtNode != 0)
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
void IntDLList<T>::printList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo() << " ";
		prtNode = prtNode->getNext();
	}
}

/***********************
	//printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void IntDLList<T>::printRevList()
{
	IntDLLNode<T>* prtNode;
	prtNode = tail;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo() << " ";
		prtNode = prtNode->getPrev();
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool IntDLList<T>::isEmpty()
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
void IntDLList<T>::addToHead(T val)
{
    //checks if head is poiting to nothing,if not...
	if(head!=0){
            //creates a new node, set previous node to null, assigns val value to the node.
                head->setPrev(new IntDLLNode<T>(0,val,head));
            //set the new node to be head node.
                head = head-> getPrev();}
        else
                {tail = head = new IntDLLNode<T>(0,val,head);}
}

template <class T>
void IntDLList<T>::addToTail(T val)
{
    //checks if tail is empty
	if(tail!=0){
            //creates a new node
            tail->setNext(new IntDLLNode<T>(tail,val,0));
            //sets tail to the new node
            tail = tail->getNext();
        }
        //if list empty seta head and tail to the first node created
        else{head = tail = new IntDLLNode<T>(tail,val,0);}
}

template <class T>
void IntDLList<T>::deleteFromHead()
{
    //checks if the list is empty
	 if (head != 0){
        //sets tmp to point to tail
        IntDLLNode<T> *tmp;
        tmp = head;
        //head now is pointing to the next node
        head = head->getNext();
        //checks if where head is now pointing is empty, if true tail is also empty
        if(head==0){ tail = 0;}
        //sets heads prev pointer to null
        else{head->setPrev(0);}
        //deletes the old head node
            delete tmp;
        }
}

template <class T>
void IntDLList<T>::deleteFromTail()
{
    //checks if the list is empty
    if (head!=0){
    //creates a temporary node to point to tail
    IntDLLNode<T> *tmp;
        tmp = tail;
    //tails is set to the previous node, so we dont loose track of the new tail
        if(head != tail){
                tail = tmp->getPrev();
                tail->setNext(0);
            }

        else{head = tail = 0;}
        //deletes the old tail that was stored in tmp
        delete tmp;
        }
}
#endif // INTDLLIST_H
