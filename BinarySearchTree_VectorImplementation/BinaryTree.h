/*
 * BinaryTree.h
 *
 *  Created on: Feb 28, 2015
 *      Author: aramirez7412
 */
#include <vector>
using namespace std;

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<class type>
struct binaryNode
{
	type data;
	int priority;
};


template<class type>
class binary_tree
{
private:

	vector<type> binaryTree;


public:
	binary_tree();
	~binary_tree();


	void insert(const binaryNode<type> & insertedItem);


	bool isEmpty();

	bool search(type & searchItem);

	bool deleteAnode(type & deleteItem);

	void bubble_up();

	int getSize();


};

template<class type>
int binary_tree<type>::getSize()
{
	return binaryTree.size();
}


template<class type>
void binary_tree<type>::bubble_up()
{
	//if(binaryTree[getSize] < )//
}

template<class type>
bool binary_tree<type>::isEmpty()
{
	//return binaryTree[0] == ;

}

//template<class type>
//void binary_treebubble_up()


template<class type>
void binary_tree<type>::insert(const binaryNode<type> & insertedItem)
{

	if(binaryTree.empty())
	{
		binaryTree.push_back(insertedItem)
	}
	else
	{
		binaryTree.push_back(insertedItem);

	}

	binaryTree[1] = insertedItem;
}

template<class type>
binary_tree<type>::binary_tree()
{

}
template<class type>
binary_tree<type>::~binary_tree()
{

}




#endif /* BINARYTREE_H_ */
