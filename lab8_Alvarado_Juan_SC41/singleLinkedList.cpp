//Juan M. Alvarado Caraballo
//S01035309
#include "IntSLList.h"
#include "intsllnode.h"

// singleLinkedList.cpp : Defines the entry point for the console application.

int main()
{
	IntSLList<int> list;
	int i;

	cout << endl << "**** New List using addToHead ****" << endl;
	cout << endl << "List: ";
	for (i = 1; i < 10; i++)
	{
		list.addToHead(i);
	}

	list.printList();
	cout << endl;

	cout << ">> Delete from head" << endl;
	while(!list.isEmpty())
	{
		cout << "Before delete: ";
		list.printList();
		list.deleteFromHead();
		cout << "| After delete: ";
		list.printList();
		cout << endl;
	}

	cout << endl << "**** New List using addToTail ***" << endl;
	cout << endl << "List: ";
	for (i = 1; i< 10; i++)
	{
		list.addToTail(i);
	}

	list.printList();
	cout<<endl;

	cout << ">> Delete from tail " << endl;

	while(!list.isEmpty())
	{
		cout << "Before delete: ";
		list.printList();
		list.deleteFromTail();
		cout << "| After delete: ";
		list.printList();
		cout << endl;
	}
	return 0;
}
