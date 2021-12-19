///
// Name: Cami Lacy
// Program Name: P4 Linked List
//
// Description: This program will read in words from
// two files. It will insert these ordered words into 
// doubly linked lists, and sort them so that each 
// list will have words unique only to itself. 
// It will also track the CLString objects
// created, and test its own copy constructor. 
// This program does not take input from the user, 
// and it displays the sizes of the doubly linked 
// lists and objects created to the screen. Lastly,
// it will write those unique words of each list to 
// two separate files. 
// 
///


#include <iostream>
#include<fstream>
#include<iomanip>
#include "CLString.h"
#include "DblLinkedList.h"
using namespace std;

// Function Prototypes//

// Temporarily adds two strings to list
void changer(DblLinkedList dll);


int main()
{
	// Local Variables
	ifstream fin1;
	ifstream fin2;
	ofstream fout1;
	ofstream fout2;
	DblLinkedList list1;
	DblLinkedList list2;
	DblLinkedList modList1;
	DblLinkedList modList2;
	CLString tempStr;

	// Open files
	fin1.open("infile1.txt");
	fin2.open("infile2.txt");
	fout1.open("outfile1.txt");
	fout2.open("outfile2.txt");

	// If file opens
	if (fin1.is_open())
	{
		// Read data into list1
		while (fin1 >> tempStr)
		{
			list1.insert(tempStr);

		}

		// If second file opens 
		if (fin2.is_open())
		{
			// Read data into list2
			while (fin2 >> tempStr)
			{

				list2.insert(tempStr);

			}

			// Display list sizes to screen
			cout << "~~ ORIGINAL LIST SIZES ~~" << endl;
			cout << left << setw(20) << "Size of list1: " << list1.getCount() << endl;
			cout << setw(20) << "Size of list2: " << list2.getCount() << endl;
			cout << setw(20) << "Size of modList1: " << modList1.getCount() << endl;
			cout << setw(20) << "Size of modList2: " << modList2.getCount() << endl << endl;


			// Set modified lists equal to original lists
			modList1 = list1;
			modList2 = list2;

			// Display list sizes to screen
			cout << "~~ SET MODLISTS EQUAL TO LISTS ~~ " << endl;
			cout << setw(20) << "Size of list1: " << list1.getCount() << endl;
			cout << setw(20) << "Size of list2: " << list2.getCount() << endl;
			cout << setw(20) << "Size of modList1: " << modList1.getCount() << endl;
			cout << setw(20) << "Size of modList2: " << modList2.getCount() << endl << endl;

			// Remove strings in list2 from modList1
			list2.resetIterator();
			while (list2.hasMore())
			{
				tempStr = list2.next();

				modList1.remove(tempStr);

			}

			// Remove strings in list1 from modList2
			list1.resetIterator();
			while (list1.hasMore())
			{
				tempStr = list1.next();

				modList2.remove(tempStr);

			}

			// Display list sizes to screen
			cout << "~~ SIZE AFTER REMOVING STRINGS ~~" << endl;
			cout << setw(20) << "Size of list1: " << list1.getCount() << endl;
			cout << setw(20) << "Size of list2: " << list2.getCount() << endl;
			cout << setw(20) << "Size of modList1: " << modList1.getCount() << endl;
			cout << setw(20) << "Size of modList2: " << modList2.getCount() << endl << endl;

			// Changer function tests the copy constructor
			cout << "~~ SIZE WHEN CALLING CHANGER ~~" << endl;
			cout << setw(20) << "Size of list1: " << list1.getCount() << endl;
			cout << setw(20) << "Size of list2: " << list2.getCount() << endl;
			cout << setw(20) << "Size of modList1: ";
			changer(modList1);
			cout << endl;
			cout << setw(20) << "Size of modList2: ";
			changer(modList2);
			cout << endl << endl;

			// Display list sizes to screen
			cout << "~~ SIZE AFTER CHANGER  ~~" << endl;
			cout << setw(20) << "Size of list1: " << list1.getCount() << endl;
			cout << setw(20) << "Size of list2: " << list2.getCount() << endl;
			cout << setw(20) << "Size of modList1: " << modList1.getCount() << endl;
			cout << setw(20) << "Size of modList2: " << modList2.getCount() << endl << endl;

			// Display CLString creation
			cout << "Total count of CLString objects: " << CLString::getCreatedCount() << endl;
			cout << "Current count of CLString objects: " << CLString::getCurrentCount();
			cout << endl << endl;

			// Check if first write file is open
			if (fout1.is_open())
			{
				// Output modList1 to outFile1
				fout1 << modList1;


			}
			else
			{
				cout << "ERROR: Could not open first write file!\n\n";
			}

			// Check if second write file opens
			if (fout2.is_open())
			{
				// Output modList2 to outFile2
				fout2 << modList2;
			}
			else
			{
				cout << "ERROR: Could not open second write file!\n\n";
			}
		}
		else
		{
			cout << "ERROR: Could not open second read file!" << endl;
		}

	}
	else
	{
		cout << "ERROR: Could not open first read file!" << endl;
	}

	// Close the files
	fin1.close();
	fin2.close();
	fout1.close();
	fout2.close();

	cout << endl << endl;

	system("pause");
	return 0;
}

// ********************FUNCTIONS BELOW******************** //

void changer(DblLinkedList dll)
{

	dll.insert("ZIP");
	dll.insert("ZAP");

	cout << dll.getCount();

}