#include <iostream>
#include "Hash.h"
#include "node.h"
#include <string>
using namespace std;


int main()
{

//	node temp;
//	node temp2;
//	node temp3;
//	node temp4;
//	node temp5;
//	node temp6;
//	node * tempPtr;
//
//	temp.SetAll("Anthony", 3.96);
//	temp2.SetAll("Andrew", 3.5);
//	temp3.SetAll("Austin", 4.0);
//
//
//	HashTable<node, string> table(50);
//
//	table.insert(temp);
//	table.insert(temp2);
//	table.insert(temp3);
//	table.insert(temp4);
//	table.insert(temp5);
//	table.insert(temp6);
//
//
//	tempPtr = table.find("Anthony");
//
//	cout << tempPtr->GetData();

	vector < vector<string> > myVec(30);

	myVec[0].push_back("Tom");
	cout << "Vector capacity: " << myVec.capacity() << endl;
	cout << "My capacity: "     << myVec[0].capacity();
	cout << "My capacity2: "    << myVec[23].capacity() << endl;
}
