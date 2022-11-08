/**********************
COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
Singly linked node
This class implements the singly linked node using templates
Each nodes two attributes:
	-info: stores the actual value
	-next: a pointer to the next node in the list
******************/
#ifndef INTSLLNODE_H
#define INTSLLNODE_H
#include "IntSLList.h"

#include <iostream>
using namespace std;

/**********************************
Class Declaration
***********************/
template <class T>
class IntSLLNode{
public:
	IntSLLNode(); //Default constructor
	IntSLLNode(T, IntSLLNode<T>*); //Special constructor
	T getInfo(); // getInfo
	IntSLLNode<T>* getNext(); // getNext
	void setInfo(T); // setInfo
	void setNext(IntSLLNode<T> *); // Set next

	T info; // Actual data
	IntSLLNode<T> *next; // Points to the next node in the list
};




/*****
	Default constructor
	Creates a empty node
*****/
template <class T>
IntSLLNode<T>::IntSLLNode()
	{ next = 0; }

/******
	Special constructor:
	Creates a node with value i in the info attribute and next pointing to null
	@params:
		i: actual value to be stored
		*n: pointer to the next node
*******/
template <class T>
IntSLLNode<T>::IntSLLNode(T i, IntSLLNode<T> *n)
 {	info = i;
	next = n; }

/********
	getInfo
	returns the info value
*********/
template <class T>
T IntSLLNode<T>::getInfo()
	{ return info; }

/********
	getNext
	returns a point to next node the list
**********/
template <class T>
IntSLLNode<T> *IntSLLNode<T>::getNext()
	{ return next; }

/********
	setInfo
	Set i as the node info
*******/
template <class T>
void IntSLLNode<T>::setInfo(T i)
	{ info = i; }

/********
	setNext
	Points next attribute to the next list node
********/
template <class T>
void IntSLLNode<T>::setNext(IntSLLNode<T> *n)
	{ next = n; }

	//template class IntSLLNode<int>;

	#endif // INTSLLNODE_H
