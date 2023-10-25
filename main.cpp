/*-- main.cpp------------------------------------------------------------
   This file is the driver for testing ListLinked
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <iostream>
using namespace std;

/* main is the entrypoint into every C++ program */
int main() 
{
 

    /*
    // Example of creating nodes for a linked list
    Node* n1 = new Node(5);
    Node* n2 = new Node(15);
    Node* n3 = new Node(25);
    Node* n4 = new Node(55);

    Node* list = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    // Print elements in a linked list
    Node* temp;
    temp = list;
    while (temp != NULL)
    {
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    */
   
	ListLinked* ll = new ListLinked();
    ll->insert(10, 0); //current linked list: 10 (default status, when empty)
    ll->display();
    ll->insert(20, 10); //current linked list: 10->20
    ll->insert(30, 20); //current linked list: 10->20->30
    ll->insert(40, 20); //current linked list: 10->20->40->30
    ll->insert(50, 30); //current linked list: 10->20->40->30->50
    ll->display();
    ll->insert(60, 50); //current linked list: 10->20->40->30->50->60
    ll->insert(70, 5); //error, no 5 existed in the linked list
    ll->display();
    ll->erase(30); //current linked list: 10->20->40->30->60
    ll->display();
    ll->erase(10); //current linked list: 10->40->30->60
    ll->display();
    ll->erase(50); //error, no 50 existed in the linked list
    ll->display();
	// #3, Add 5 inserts
	// #6, Add 5 erases
	delete ll;

	//cin.get();
     
	return 0;

}
