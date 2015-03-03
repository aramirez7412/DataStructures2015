/*
 * Hash.h
 *
 *  Created on: Feb 4, 2015
 *      Author: adaniels4
 */

#ifndef HASH_H_
#define HASH_H_

#include <ostream>
#include <vector>
#include "node.h"
using namespace std;

template <typename T, typename K>
class HashTable
{
public:
	HashTable(int tableSize);
	void insert(T newRecord);
	T*   find(K key);
	void erase(T* pos);
//	template<class T, class K>
//	friend ostream& operator << (ostream& out, const HashTable& right);

private:
	vector< vector<T> > table;

};

template<class T, class K>
HashTable<T,K>::HashTable(int tableSize)
{
	table.resize(tableSize);
}


template <class T, class K>
void HashTable<T,K>::insert(T newNode)
{
	int index = newNode.GetHash(table.size());

	table[index].push_back(newNode);
}

template<typename T, typename K>
T* HashTable<T,K>::find(K key)
{
	T* tempPtr;
	T tempNode;
	tempNode.SetKey(key);

	tempPtr = NULL;

	int index = tempNode.GetHash(table.size());

	for(int i = 0; i < table[index].size(); i++)
	{
		if(table[index][i].GetKey()==key)
			tempPtr =  &table[index][i];
	}

	return tempPtr;
}
#endif /* HASH_H_ */
