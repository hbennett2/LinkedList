 /*-- ListLinked.cpp------------------------------------------------------------
   This file implements the ListLinked member functions.
--------------------------------NOTES------------------------------------------
navigate to node that contains preptrvalue so you can insert
the next node. preptr=preptr->next, put loop around it for value your looking for
next do the insertion logic to add node after node you looked for
look at data value to find value that the node actually contains
-------------------------------------------------------------------------------*/

#include "ListLinked.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Constructor  */
ListLinked::ListLinked()
{
		first = NULL;
}

/* destructor - clean up memory for remaining nodes in list */
ListLinked::~ListLinked()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		Node* save = temp;
		temp = temp->next;
		delete save;
	}
}

/* empty */
bool ListLinked::empty()
{
	if (first == NULL)
		return true;
	else
		return false;
}

/* display */
void ListLinked::display()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->data << ",";
		temp = temp->next;
	}
	cout << endl;
}

/* insert element in position */
void  ListLinked::insert(ElementType e, ElementType preptrvalue) 
{
	Node* newptr = new Node(e);
	// error message & skip if element = 0
	if (e == 0)
	{
		cout << "ERROR - Element must not equal 0." << endl;
		return;
	}

	// insert first element if list is empty 
	if (empty()) //insert the very first element
	{
			newptr->next = NULL;
			first = newptr;
	}

	else //most cases belongs to this situation 
	{
		//create and set preptr to first element 
		Node* preptr;
		preptr = first;
			
		//navigates preptr pointer and stops when certain data value is found (preptrvalue)
		while (preptr != NULL && preptr->data != preptrvalue)
		{   
			// preptr points to next node
			preptr = preptr->next;
		}
		//if value not found display error
		if (preptr == NULL) 
		{
			cout << "ERROR - Value " << preptrvalue << " not found in list." << endl;
			return;
		}
		//newptr points to next node or null if at end (insertion)
		newptr->next = preptr->next;
		//preptr will point to the new node (insertion complete)
		preptr->next = newptr;
	}
}


/* Remove specified element from the list at a specific position */
void ListLinked::erase(ElementType preptrvalue)
{
	if (preptrvalue == 0) //delete the first element
	{
		Node* ptr = first; //ptr is first node
		first = ptr->next; //first points to next node
		delete(ptr); //first node (ptr is deleted)
		cout << "ERROR - Preptr Value must not equal 0." << endl;
		return;
	}

	else
	{
		//create and set preptr to first element 
		Node* preptr;
		preptr = first;
			
		//navigates preptr pointer and stops when certain data value is found (preptrvalue)
		while (preptr != NULL && preptr->data != preptrvalue)
		{   
			// preptr points to next node
			preptr = preptr->next;
		}
		//if value not found display error
		if (preptr == NULL) 
		{
			cout << "ERROR - Value " << preptrvalue << " not found in list. " << endl;
			return;
		}
		//ptr points to node that needs to be erased
		Node* ptr = preptr->next;
		//preptr points to node after the one being erased
		preptr->next = ptr->next;
		//delete node associated with ptr
		delete(ptr);
	}
}

