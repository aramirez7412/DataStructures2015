#include "node.h"
using namespace std;

node::node()
{
	name = "Bob";
	GPA  = 4.0;
}

node::~node()
{

}
string node::GetKey()
{
	return name;
}

void node::SetKey(string key)
{
	name = key;
}

int node::GetHash(int M)
{
	string key = GetKey();

	int index  = 0;

	for(int i = 0; i < 0; i++)
	{
		index += (int)key[i];
	}

	//A
	//Z
	//T
	index = index % M;

	return index;
}

void node::SetAll(string newName, double gpa)
{
	name = newName;
	GPA  = gpa;
}

string node::GetData()
{
	return name;
}
