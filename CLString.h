///
// Author: Cami Lacy
// Assignment: P4 Linked List
//
// Description: This header file contains the 
// CLString class. This class holds several member
// function declarations that act like the original
// string library.
//
// We can find a string's length, capacity, and even
// print out the string. Additionally, we can read from
// and write to files, compare strings, and set strings
// equal to each other. It is also possible to find
// what character is at a certain location in the cstring. 
// Moreover, we can track the number of active objects
// created as well as the total objects created. 
// This file also contains the big four and can add words
// to create a new word. 
//
///

#ifndef CLSTRING_H 
#define CLSTRING_H
#include<iostream>
using namespace std;


class CLString 
{
public:
	CLString();						// Default constructor
	CLString(const CLString& mstr);	// Copy constructor
	CLString(const char*);			// cstring constructor
	~CLString();					// Destructor

	// CLString length and capacity
	int length() const;
	int capacity() const;

	// Reading and writing
	friend istream& operator>>(istream& istrm, CLString& argstr);
	friend ostream& operator<<(ostream& ostrm, const CLString& argstr);

	// Operator overloading
	char operator[](int index);
	bool operator<(const CLString& argstr) const;
	bool operator>(const CLString& argstr) const;
	bool operator==(const CLString& argstr) const;
	CLString operator+(const CLString& rvalue) const; 
	CLString operator=(const CLString& argStr);


	// Track CLString creation
	const char* c_str() const; 
	static int getCurrentCount();
	static int getCreatedCount(); 

private:
	char* str;
	int cap;
	int end;
	static int currentCount;
	static int createdCount;
	int capGrow(int argLength); // potentially grows capacity

}; // end CLString class
#endif