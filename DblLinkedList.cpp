///
// Name: Cami Lacy
// Program Name: P4 Linked List
//
// Description: This file contains the function
// definitions to the DbleLinkedList header file's 
//function declarations. We can call these function
// definitions in the main.cpp to create, add,
// remove, and reorder words. We can also
// write these words contained in nodes to
// files and track the size of lists.
// 
///

#include "DblLinkedList.h"

/*
Default constructor
*/
DblLinkedList::DblLinkedList()
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
}

/*
Copy constructor
*/
DblLinkedList::DblLinkedList(const DblLinkedList& dll)
{
	// Set to head
	dll.it = dll.head;

	// Set this head and tail to nullptr
	head = tail = nullptr;

	// Loops through list and pushbacks
	while(dll.it != nullptr)
	{
		// Push data into node(also increments count
		push_back(dll.it->data);

		// Set it to next node to crawl
		dll.it = dll.it->next;

	}

}

/*
Destructor
*/
DblLinkedList::~DblLinkedList()
{
	// Local Variables
	Node* temp = head;

	// Loops until nullptr
	while (temp != nullptr)
	{

		// temp next arrow points to nextNode
		Node* nextNode = temp->next;
		// delete temp
		delete temp;
		// set temp equal to nextNode
		temp = nextNode;

		count--;
	}
}

/*
Assignment operator
*/
DblLinkedList& DblLinkedList::operator=(const DblLinkedList& dll)
{
	// Local Variables
	Node* temp = head;

	// Reset iterator
	dll.resetIterator();

	// If lists are equal to each other
	if (&dll == this)
	{
		// Do nothing
	}
	else
	{
		// If list is empty
		if (head == nullptr && tail == nullptr)
		{

			while(dll.hasMore()) 
			{
				// Push data into node
				push_back(dll.it->data);

				// Set it to next node to crawl
				dll.it = dll.it->next;
			}
		}
		else
		{
			// Delete nodes in list
			while (temp != nullptr)
			{

				// temp next arrow points to nextNode
				Node* nextNode = temp->next;
				// delete temp
				delete temp;
				// set temp equal to nextNode
				temp = nextNode;

			}

			// Push back data
			while(dll.hasMore())
			{
				// Push data into node
				push_back(dll.it->data);

				// Set it to next node to crawl
				dll.it = dll.it->next;
			}

		}
	}

	return *this;
}

/*
Output the data to the ostream
*/
ostream& operator<<(ostream& ostrm, const DblLinkedList& dll) // ignore this experimentation
{
	dll.resetIterator();

	while (dll.hasMore())
	{
		ostrm << dll.next() << " ";
	}
	
	return ostrm;
}
//ostream& operator<<(ostream& ostrm, const DblLinkedList& dll)
//{
//	ostrm << dll;
//	return ostrm;
//}

/*
Insert the string argument into the list in
the proper place(smallest to largest). Do not
insert the string if the DLL already has a string
of that value. Return true if the string was inserted,
otherwise return false.
*/
bool DblLinkedList::insert(const CLString& str)
{
	// Local variables
	Node* temp = new Node(str);
	bool insertCheck = false;

	// Reset iterator
	resetIterator();

	// If the list is empty
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		it = temp;
		insertCheck = true;
		count++;
	}
	// If there is only one node
	else if (it->next == nullptr)
	{
		if (it->data == str)
		{
			// Don't do anything
		}
		else if (it->data < str)
		{
			push_back(str); // push back increments count
			insertCheck = true;

		}
		else if (it->data > str)
		{

			// Prev arrow points left to temp
			it->prev = temp;

			// Next arrow point right to it node
			temp->next = it;

			// Set head to temp
			head = temp;

			// Set to true
			insertCheck = true;
			count++;

		}
	}
	// If there are many nodes
	else
	{

		while (it != nullptr)
		{
			// if strings are equal
			if(it->data == str)
			{
				// Don't do anything
				break;
			}
			// Put str at back
			else if (tail->data < str)
			{
				push_back(str); // push back incrememnts count

				insertCheck = true;
				break;
			}
			// Put str at front
			else if (head->data > str)
			{
				// Prev arrow points left to temp
				head->prev = temp;

				// Next arrow point right to it node
				temp->next = head;

				// Set head to temp
				head = temp;

				// Set to true
				insertCheck = true;
				count++;
				break;
			}
			// Put str in middle
			else if((it->data < str)&&(it->next->data > str))
			{
				// The next node points left to temp
				it->next->prev = temp;

				// temp points right to next node
				temp->next = it->next;

				// It node arrows right to temp
				it->next = temp;

				// Temp arrows left to it node
				temp->prev = it;

				// Set to true
				insertCheck = true;
				count++;
				break;
			}
			else
			{

				// Move iterator
				it = it->next;
			}
		} // end while loop
	} // end else
	

	return insertCheck;

}

/*
 If the string argument is found in the DLL remove it from the
 DLL objectt. Return true if a string was removed, otherwise
 return false
*/
bool DblLinkedList::remove(const CLString& str)
{
	// Local Variables
	bool checkRemove = false;

	// Reset iterator
	resetIterator();

	while (it != nullptr)
	{
		if (it->data == str)
		{
			Node* temp = it;
			// If deleting front node
			if (it->prev == nullptr)
			{

				// Set head to next node
				head = it->next;

				// Next node points left to nullptr
				it->next->prev = nullptr;

				// Set to true;
				checkRemove = true;

				// Delete the node
				delete temp;

				// Decrement count
				count--;

				break;

			}
			// If deleting last node
			else if (it->next == nullptr)
			{
				// Set tail to prior node
				tail = tail->prev;

				// Prior node points right to nullptr
				it->prev->next = nullptr;


				// Set to true;
				checkRemove = true;

				// Delete the node
				delete temp;

				// Decrement count
				count--;

				break;

			}
			// If deleting middle node
			else
			{
				// Prior node points right to next next node
				it->prev->next = it->next;

				// Next next node points left to prior node
				it->next->prev = it->prev;

				// Set to true;
				checkRemove = true;

				// Delete the node
				delete temp;

				// Decrement count
				count--;

				break;

			}
		}
		else
		{

			// Move iterator
			it = it->next;
		}
	} // end while loop
	

	return checkRemove;
}

/*
Inserts string at back of list
*/
bool DblLinkedList::push_back(const CLString& str)
{

	// Insert string in allocated node temp
	Node* temp = new Node(str);

	// Should consider if list is empty
	if (head == nullptr)
	{
		head = temp;
		it = temp;
		tail = temp;
	}
	else
	{
		// temp points left to tail
		temp->prev = tail;

		// the previous node tail point right to temp
		tail->next = temp;

		// set tail equal to temp
		tail = temp;
	}

	// Increment count
	count++;

	return true;
}

/*
Returns the number of strings that are stored in the DLL
*/
int DblLinkedList::getCount() const
{
	return count;
}

/*
Puts iterator at head of list
*/
void DblLinkedList::resetIterator() const
{
	
	it = head;

}

/*
Returns true if the it member pointer is pointing
to a node, otherwise it returns false
*/
bool DblLinkedList::hasMore() const
{

	// if it doesn't point to nullptr then true
	if (it != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
Returns the string where your pointer is pointing 
and then moves it to the next thing(node or nullptr)
*/
CLString DblLinkedList::next() const
{
	// Local variable
	CLString tempStr;

	// Return the string
	tempStr = it->data;

	// Goes to next node after
	it = it->next;

	return tempStr;
}