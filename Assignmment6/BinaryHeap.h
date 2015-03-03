/*
 * Heap.h
 *
 *  Created on: Feb 28, 2015
 *      Author: aramirez7412
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_


#include "Node.h"
#include <vector>
#include <iterator>
using namespace std;

template<class A, class B>
class priorityQueue
{
	private:

//	Node<A,B> * _root;
//	Node<A,B> * _insertPlacement; //insert placement will be pointing to the
//								   //parent of where the next insertion should
//							       //done
//	int currentEntryLevel; //Keeps track of what level of the tree the
//							   //Entry position should be



	vector< Node<A,B> > heap;
//	Node<A,B> * getLowestLevel();
//	Node<A,B> * getParentofRightLevel();

//	std::string sideOfRoot;

	public:


	/***************************************************************************
	 * Constructor
	 * _________________________________________________________________________
	 * Intiializes _root and _insertPlacement to NULL
	 ***************************************************************************/
	priorityQueue();


	/***************************************************************************
	 * Destructor
	 * _________________________________________________________________________
	 * Currently does nothing but eventually will add destroy tree or something
	 * like that
	 ***************************************************************************/
	~priorityQueue();

	/***************************************************************************
	 * isEmpty
	 * _________________________________________________________________________
	 * Checks to see if the binaryHeap is empty
	 ***************************************************************************/

	//done
	bool isEmpty() const;

	/***************************************************************************
	 * Insert
	 * _________________________________________________________________________
	 * inserts a node into the
	 ***************************************************************************/
	void insert(const Node<A,B> & insertedData);

	//done
	int getSize() const;



	/***************************************************************************
	 * ViewMin
	 * _________________________________________________________________________
	 * Allows the client to view the node that is located int he minimum value
	 * in the tree
	 ***************************************************************************/

	const Node<A,B>& viewMax();


	/***************************************************************************
	 * removeMin
	 * _________________________________________________________________________
	 * Removes the minimum value
	 ***************************************************************************/

	Node<A,B> removeMax(); // Removes minimum value



	//done
	bool insertData(const Node<A,B> & insertedData);

	//done
	void bubbleup(int index);

	//done
	void bubbledown(int binaryTreeSize);



	//done
	int getParentIndex(int someChild);


	//Done
	int getLeftChild(int someParent);


	//Done
	int getRightChild(int someParent);


	void OutputHeap();
};

template<class A, class B>
void priorityQueue<A,B>::OutputHeap()
{
	typename vector< Node<A,B> >::iterator someIt;

	Node<A,B> temp;
	someIt = heap.begin();

	while(someIt != heap.end())
	{
		temp = *someIt;
		temp.output();

		++someIt;

	}
}

template<class A, class B>
const Node<A,B> & priorityQueue<A,B>::viewMax()
{

		return heap.front();

}

template <class A, class B>
Node<A,B> priorityQueue<A,B>::removeMax()
{
	Node<A,B> temp = heap.front();
	heap[0] = heap[getSize()-1];
	heap.pop_back();
	bubbledown(0);
	return temp;
}
template<class A, class B>
int priorityQueue<A,B>::getParentIndex(int someChild)
{

	//checks if the child is not the 0th elemennt
	if(someChild != 0)
	{
		int i;

		//Determines the parent of the child
		i = (someChild - 1) / 2;

		return i;
	}

	return -1;
}

template<class A, class B>
int priorityQueue<A,B>::getLeftChild(int someParent)
{
	int i;

	//Determines the left child of the parent being passed in
	i = (someParent * 2) + 1;

	return (i < getSize()) ? i : -1;
}

template<class A, class B>
int priorityQueue<A,B>::getRightChild(int someParent)
{
	int i;

	//determines the right child of the parent being passed in
	i = (someParent * 2) +2;

	return (i < getSize()) ? i : -1;
}




template<class A, class B>
int priorityQueue<A,B>::getSize() const
{
	return heap.size();
}

template<class A, class B>
priorityQueue<A, B>::priorityQueue()
{
	//Assigns the root, and insertPlacement to NULL (0 in this case)

}

template<class A, class B>
priorityQueue<A, B>::~priorityQueue()
{
	//Empty for now//Will include destroy tree soon
}

template<class A, class B>
bool priorityQueue<A, B>::isEmpty() const
{
	return heap.empty();
}

//Insert into the binary Heap
template<class A, class B>
void priorityQueue<A, B>::insert(const Node<A,B> & insertedData)
{

	//Pushes new inserted data onto the heap
	heap.push_back(insertedData);

	//bubbles up the heap to restore balance
	bubbleup(getSize() - 1);
}

template<class A, class B>
void priorityQueue<A,B>::bubbleup(int index)
{
	while( (index > 0)                  &&
		   (getParentIndex(index) >= 0) &&
		   (heap[getParentIndex(index)] < heap[index]))
	{ //start here


		//must overload the assignment operator!!!!!
		Node<A,B> temp;

		temp = heap[getParentIndex(index)];

		heap[getParentIndex(index)] = heap[index];
		heap[index] = temp;

		index = getParentIndex(index);
	}
}

template<class A, class B>
void priorityQueue<A,B>::bubbledown(int index)
{

	int j = getLeftChild(index);

	Node<A,B> temp = heap[index];

	while(j > 0 && (heap[j] > temp || heap[j+1] > temp))
	{

		if(heap[j+1] > heap[j])
		{
			j++;
		}

		heap[index] = heap[j];
		index = j;
		heap[index] = temp;

		j = getLeftChild(index);

		temp = heap[index];


	}


}

#endif /* BINARYHEAP_H_ */
