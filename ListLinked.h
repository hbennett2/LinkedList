#ifndef LISTLINKED
#define LISTLINKED
#include "ElementType.h"
#include "Node.h"
/*-- ListLinked.h ---------------------------------------------------------------
  This header file defines the data type ListLinked for processing a 
  list by position
  This class inherits from the abstract base class List
  Basic operations are:
	 Constructor
	 empty:    Check if list is empty
	 insert:   Insert an item
	 erase:    Remove an item
	 display:  Output the list
-------------------------------------------------------------------------*/
class ListLinked 
{
public:
	/* Constructor for the list */
	ListLinked();

	/* Destructor for the list */
	~ListLinked();

	/* Indicates if the list is empty */
	bool empty();

	/* Display the list to stdout */
	void display();

	/* Insert an item into the list in order */
	void insert(ElementType e, ElementType preptrvalue);

	/* Remove the item from the list at a particular position */
	void erase(ElementType preptrvalue);

private:
	Node* first; // pointer to the first node in the list
};

#endif
#pragma once
