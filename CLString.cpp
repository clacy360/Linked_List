///
// Author: Cami Lacy
// Assignment: P4 Linked List
//
// Description: This file contains the function 
// definitions to the CLString header file's function 
// declarations. We can call these function
// definitions in the main.cpp to create and compare
// strings as well as reading and writing files. 
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


#include "CLString.h"
#include<cctype>

/*
Increments capacity be 20
*/
int CLString::capGrow(int argLength)
{
	// Local Variables
	int tempCap = 20;

	while (argLength >= tempCap)
	{
		tempCap += 20;
	}

	return tempCap;
} // end capGrow

/*
Default Constructor: creates an empty string
*/
CLString::CLString()
{
	// Local variables
	cap = 20;
	end = 0;
	str = new char[cap];
	str[0] = '\0';

	currentCount++;
	createdCount++;

} // end default constructor

/*
Copy Constructor: Creates a string that's a 
duplicate of the argument
*/
CLString::CLString(const CLString& mstr)
{
	// Local variables
	cap = mstr.cap;
	end = mstr.end;
	str = new char[cap];
	for (int i = 0; i <= end; ++i)
	{
		str[i] = mstr.str[i];
	}
	createdCount++; 
	currentCount++; 

} // end copy constructor

/*
cstring constructor:
Creates a string that contains the info from the argument
e.g. CLString greeting("hello there")
*/
CLString::CLString(const char* charConst)
{
	// Local variables
	int testLength = 0;


	// Find length of string
	for (int i = 0; charConst[i] != '\0'; i++)
	{
		testLength++;
	}
	
	// Determine capacity 
	cap = capGrow(testLength);

	// Set the capacity
	str = new char[cap];

	// Put into allocated memory
	for (end = 0; charConst[end] != '\0'; ++end); 
	for (int i = 0; i <= end; ++i)
	{
		str[i] = charConst[i];
	}

	// Increment objects created
	currentCount++;
	createdCount++;

} // end cstring constructor

/*
Destructor: release the dynamic memroy
*/
CLString::~CLString()
{
	delete[] str;
	currentCount--;

} // end destructor

/*
Example: The length of string ("cat" would turn 3)
*/
int CLString::length() const
{
	return end;

} // end of length()

/*
The total amount of memory available for use
*/
int CLString::capacity() const
{

	return cap;

} // end capacity()

/*
Return a pointer to a constant
cstring version of the CLString
object
*/
const char* CLString::c_str() const
{
	return str;

} //end of c_str()

/*
Read one string from the istream argument.
This function will now return the istream 
which is the normal behavior.
*/
istream& operator>>(istream& istrm, CLString& argstr)
{
	// Local Variables
	char readText[100]; // Array holding 100 char spots
	int testLength = 0;

	// Put into allocated memory
	if (istrm >> readText)
	{

		// Find length of string
		for (int i = 0; readText[i] != '\0'; i++)
		{
			testLength++;
		}
		testLength++;

		// Determine capacity 
		argstr.cap = argstr.capGrow(testLength);

		// Set the capacity and delete
		delete[]argstr.str;
		argstr.str = new char[argstr.cap];

		// Put into allocated memory
		argstr.end = testLength-1;
		for (int i = 0; i <= argstr.end; ++i)
		{
			 
			// If data of readText at index i is punctuation
			if (ispunct(readText[i]) != 0)
			{
				// If index i is at element before end of word
				if (i == argstr.end-1)
				{
					argstr.str[i] = '\0';
					break;
				}
			}
			argstr.str[i] = readText[i];

		}

		// Increment objects created
		argstr.currentCount++;
		argstr.createdCount++;

	}
		return istrm;
} // end istream reading


/*
Write the string out to the ostream argument,
but don't add any end of line (could be cout
or an ofstream variable). This function will 
now return the ostream which is the normal 
behavior.
*/
ostream& operator<<(ostream& ostrm, const CLString& argstr)
{

	ostrm << argstr.str;
	return ostrm;

} // end writing ostream

/*
Returns the character at a certain location (at(0) for
a "cat" would return 'c') if the index isn't inside the
string(negative or too large) then return '\0'
*/
char CLString::operator[](int index)
{
	char tempChar;

	tempChar = str[index];

	return tempChar;
} // end at []

/*
These overloaded operators:
Compare the object string (objStr) to the argument
string(argStr) by subtracting each element of argStr
from objStr until a difference is found or until all
elements have been compared.
*/

//
//Returns true if this object is "less than"
//the argument object.
//
bool CLString::operator<(const CLString& argstr) const
{
	// Local variables
	bool temp = false;
	int difNum = 0;
	int i = 0;
	int tempThis = 0;
	int tempArg = 0;

	// Compare each letter
	while ((this->str[i] != '\0' || argstr.str[i] != '\0') && (difNum == 0))
	{
		// Convert letters to lowercase
		tempThis = tolower(this->str[i]);
		tempArg = tolower(argstr.str[i]);
		
		// If first c string's letter is smaller
		if (tempThis < tempArg)
		{
			difNum = 5;
			temp = true;
		}
		else if (tempThis > tempArg)
		{

			difNum = 5;
			temp = false;
		}

		i++;
	}
	return temp;
} // end < less than

/*
Returns true if this object is "greater than"
the argument object.
*/
bool CLString::operator>(const CLString& argstr) const
{
	// Local variables
	bool temp = false;
	int i = 0;
	int difNum = 0;
	int tempThis = 0;
	int tempArg = 0;

	// Compare each letter
	while ((this->str[i] != '\0' || argstr.str[i] != '\0') && (difNum == 0))
	{
		// Convert letters to lowercase
		tempThis = tolower(this->str[i]);
		tempArg = tolower(argstr.str[i]);
		
		// If first c string's letter is larger
		if (tempThis > tempArg)
		{

			difNum = 5;
			temp = true;
		}
		// If first c string's letter is smaller
		else if (tempThis < tempArg)
		{
			temp = false;
			difNum = 5;
		}
		i++;
	}

	return temp;
} // end > greater than

/*
Returns true if this object is "equal"
to the argument object.
*/
bool CLString::operator==(const CLString& argstr) const
{

	// Local variables	
	int i = 0;
	int difNum = 0;
	bool temp = true;
	int tempThis = 0;
	int tempArg = 0;

	// Loops through to compare letters
	while ((this->str[i] != '\0' || argstr.str[i] != '\0') && (difNum == 0))
	{
		// Convert letters to lowercase
		tempThis = tolower(this->str[i]);
		tempArg = tolower(argstr.str[i]);
		
		// If first c string's letter is smaller
		if (tempThis < tempArg)
		{
			difNum = 5;
			temp = false;
		}
		// If first c string's letter is larger
		else if (tempThis > tempArg)
		{
			difNum = 5;
			temp = false;
		}
		i++;

	}

	return temp;
} // end == equal to

/*
= operator: Changes objStr to have same info as argStr 
*/
CLString CLString::operator=(const CLString& argStr)
{
	// Local variables
	end = argStr.end;

	// Grow if necessary
	cap = capGrow(end);
	delete[] str;
	str = new char[cap];

	// Loop through each character
	for (int i = 0; i <= end; ++i)
	{
		str[i] = argStr.str[i];
	}
	return *this;

} // end = operator

/*
this function creates and returns a new CLString
variable that's the combo of both the rvalue and
the lvalue. For example, "bat" + "man" would return
"batman"
*/
 CLString CLString::operator+(const CLString& rvalue) const
{
	 // Local variables
	 int i = 0;
	 CLString newStr;

	// Find length
	 newStr.end = end + rvalue.end;

	 // Determine capacity 
	 newStr.cap = newStr.capGrow(newStr.end);

	 // Set the capacity and delete
	 delete[] newStr.str;
	 newStr.str = new char[newStr.cap]; 

	  //Read into newstring
	 for (i = 0; str[i] != '\0'; i++)
	 {
		 newStr.str[i] = str[i];
	 }
	 for (int j = 0; rvalue.str[j] != '\0'; j++)
	 {
		newStr.str[i] = rvalue.str[j];
		i++;
	 }
	 newStr.str[i] = '\0';

	return newStr;

} // end + operator

/*
Current Count:
The count of how many CLString instances
are currently "alive"
Number continues to increase and decrease
throughout program
*/
int CLString::currentCount = 0;
int CLString::getCurrentCount()
{
	return currentCount;
}

/*
Created Count:
The count of how many CLString instances
have been created in the program
Does not decrease in destructor...
*/
int CLString::createdCount = 0;
int CLString::getCreatedCount()
{
	return createdCount;
}