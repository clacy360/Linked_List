///
// Name: Cami Lacy
// Program Name: P4 Linked List
//
// Description: This header file contains the Node 
// class and the DblLinked Class. These classes have
// several member function declarations listed here.
//
// The Node class is used to created doubly linked
// lists for the DblLinkedList class.
// The DblLinkedList class is used to add and remove 
// nodes that will contain words, track the 
// amount of nodes created for a list's size, and 
// write those words to files.
//
///

#ifndef DBLLLINKEDLIST_H
#define DBLLINKEDLIST_H
#include"CLString.h"
#include<iostream>
using namespace std;

class Node
{   
public:
	Node()
	{
		next = prev = nullptr;
	}
	Node(CLString num)
	{
		data = num;
		next = prev = nullptr;
	}

	CLString data;
	Node* next;
	Node* prev;
};


class DblLinkedList
{
public:
	DblLinkedList();							// Default constructor
	DblLinkedList(const DblLinkedList&dll);		// Copy constructor
	~DblLinkedList();							// Destructor


	DblLinkedList& operator=(const DblLinkedList& dll);	// Assignment operator

	// Outputs data to ostream
	friend ostream& operator<<(ostream& ostrm, const DblLinkedList& dll); 

	bool insert(const CLString& str);		// Insert nodes
	bool remove(const CLString& str);		// Remove nodes

	int getCount() const;				// Returns list size
	void resetIterator() const;			// Resets iterator
	bool hasMore() const;				// Check if list has more nodes
	CLString next() const;				// Returns string and moves to next


private:
	Node* head, * tail;
	// mutable says that it can change in a const member function
	mutable Node* it;	
	int count = 0; 

	bool push_back(const CLString& str);	// Push back nodes
};

#endif