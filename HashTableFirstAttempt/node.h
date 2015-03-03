/*
 * node.h
 *
 *  Created on: Feb 4, 2015
 *      Author: adaniels4
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>
using namespace std;

class node
{
	public:
	node();
	~node();

	string GetKey();
	void   SetKey(string key);
	int    GetHash(int size);
	void   SetName(string newName);
	void   SetGPA(double newGPA);
	void   SetAll(string newName, double newGPA);
	string GetData();
private:

	string name;
	double GPA;
};

#endif /* NODE_H_ */
