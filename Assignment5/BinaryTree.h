/*
 * BinaryTree.h
 *
 *  Created on: Feb 23, 2015
 *      Author: aramirez81
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

//#include "Vector.h"
#include <stack>
#include "binaryNode.h"

using namespace std;
template<class type>
class binaryTree
{
public:
	binaryTree();
	~binaryTree();

	/***************************************************************************
	 * isEmpty
	 * -------------------------------------------------------------------------
	 * returns true if the tree is empty
	 ***************************************************************************/
	bool isEmpty();

	/***************************************************************************
	 * inorderTraversal
	 * -------------------------------------------------------------------------
	 * Performs in in order Traversal and prints the content of the node in
	 * in order traversal
	 ***************************************************************************/
	void inorderTraversal () const;

	/***************************************************************************
	 * postorderTraversal
	 * -------------------------------------------------------------------------
	 * Performs a postorder traversal and pritns the content of the node in
	 * post order traversal order
	 ***************************************************************************/
	void postorderTraversal() const;

	/***************************************************************************
	 * treeHeight
	 * -------------------------------------------------------------------------
	 * returns the trees hieght
	 ***************************************************************************/
	int treeHeight() const;

	/***************************************************************************
	 * treeNodeCount
	 * -------------------------------------------------------------------------
	 * Will determine the number of nodes within the tree
	 ***************************************************************************/
	int treeNodeCount() const;

	bool search(const type & searchItem) const;

	/***************************************************************************
	 * treeLeavesCount
	 * -------------------------------------------------------------------------
	 * returns the tree number of leaves in the tree
	 ***************************************************************************/
	int treeLeavesCount() const;

	/***************************************************************************
	 * destroyTree
	 * -------------------------------------------------------------------------
	 * memory space occupied by each tree is deallocated
	 ***************************************************************************/
	void destroyTree();


//	void deleteFromTree(binaryNode<type>* &p);

	void deleteNode(const type & deleteItem);


	/***************************************************************************
	 * search
	 * -------------------------------------------------------------------------
	 * Returns true if searchItem is found in the binary tree; otherwise,
	 * returns false
	 ***************************************************************************/
	bool search(const type & searchItem);

	/***************************************************************************
	 * insert
	 * -------------------------------------------------------------------------
	 * If there is no node with the same data as the binary tree it is inserted
	 ***************************************************************************/
	void insert(const type& insertItem);

	/***************************************************************************
	 * max
	 * -------------------------------------------------------------------------
	 * returns the larger of x and y
	 ***************************************************************************/
	int max(int x, int y) const;

	int height(binaryNode<type>*p) const;

	int findHeight();

private:
	binaryNode<type> * _root;
};

template<class type>
int binaryTree<type>::findHeight()
{
	return height(_root);
}


template<class type>
int binaryTree<type>::max(int x, int y) const
{
	if(x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}


template<class type>
int binaryTree<type>::height(binaryNode<type> *p) const
{
	if(p == NULL)
	{
		return 0;
	}
	else
	{
		return 1+ max(height(p->GetLeft()),height(p->GetRight()));
	}
}



/*******************************************************************************
 * search
 * -----------------------------------------------------------------------------
 */
template<class type>
bool binaryTree<type>::search(const type & searchItem)
{
	binaryNode<type> * current;
	bool found = false;

	if(_root == 0)
	{
		cout << "Cannot search an empty tree. " << endl;
	}
	else
	{
		current = _root;

		while(current != 0 && !found)
		{
			if(current->GetData() == searchItem)
			{
				found = true;
			}
			else if(current->GetData() > searchItem)
			{
				current = current->GetLeft();
			}
			else
			{
				current = current->GetRight();
			}
		}
	}

	return found;
}


/*******************************************************************************
 * binaryTree
 * -----------------------------------------------------------------------------
 * Constructor. Initializes root to NULL
 *******************************************************************************/
template<class type>
binaryTree<type>::binaryTree()
{

	_root = NULL;
}

/*******************************************************************************
 * ~binaryTree
 * -----------------------------------------------------------------------------
 * Destructor
 *******************************************************************************/
template<class type>
binaryTree<type>::~binaryTree()
{
}

/*******************************************************************************
 * isEmpty
 * -----------------------------------------------------------------------------
 * returns true if the binary tree is empty
 *******************************************************************************/
template<class type>
bool binaryTree<type>::isEmpty()
{
	return _root == NULL;
}


/***************************************************************************
 * Insert
 */
template<class type>
void binaryTree<type>::insert(const type& insertItem)
{
	binaryNode<type> * current;
	binaryNode<type> * trailCurrent;
	binaryNode<type> * newNode;

	newNode = new binaryNode<type>;
	newNode->SetData(insertItem);
	newNode->SetRight(NULL);
	newNode->SetLeft(NULL);

	if(_root == NULL)
	{
		_root = newNode;

		cout << endl << "Inserting: " << newNode->GetData() << endl;
	}
	else
	{
		current = _root;

		while(current != NULL)
		{
			trailCurrent = current;

			if(current->GetData() == insertItem)
			{
				cout << "The item to be inserted is already in the tree" << endl;
				return;
			}
			else if(current->GetData() > insertItem)
			{
				current = current->GetLeft();
			}
			else
			{
				current = current->GetRight();
			}
		}

		if(trailCurrent->GetData() > insertItem)
		{
			trailCurrent->SetLeft(newNode);
		}
		else
		{
			trailCurrent->SetRight(newNode);
		}

		cout << endl << "Inserting: " << newNode->GetData() << endl;

	}

}


template<class type>
void binaryTree<type>::inorderTraversal() const
{
	stack<binaryNode<type>*> myStack;
	binaryNode<type> * current;
	binaryNode<type> * temp;
	current = _root;

	while((current != NULL) || (!myStack.empty()))
	{
		if(current != NULL)
		{
			myStack.push(current);
			current = current->GetLeft();
		}
		else
		{
			current = myStack.top();
			myStack.pop();
			cout << endl << endl;
			cout << "Current Data: " << current->GetData();
			cout << endl;

			if(current->GetLeft() != NULL)
			{
				cout << "Data to the Left: " << current->GetLeft()->GetData()<<endl;

			}
			else
			{
				cout << "Nothing to the left" << endl;
			}

			if(current->GetRight()!= NULL)
			{
				cout << "Data to the right: " << current->GetRight()->GetData()<< endl;
			}
			else
			{
				cout << "Nothing to the right" << endl << endl;
			}
			current = current->GetRight();
		}
	}
	cout << endl;
}


#endif /* BINARYTREE_H_ */
