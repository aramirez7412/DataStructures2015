/*******************************************************************************
 * This template is designated for the implementation of an iterator that will
 * be used for the vector ADT
 *
 *******************************************************************************/
#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "Node.h"
using namespace std;

template<class type>
class iteratorClass
{
private:
	Node<type> * ptr;

//	const int NULL = 0;

public:

	iteratorClass();

	iteratorClass(const Node<type> & someNode);

	bool operator!=(const iteratorClass<type> & otherIt );

	bool operator == (const iteratorClass<type> & otherIt);

	bool operator < (const iteratorClass<type> & otherIt);

	bool operator > (const iteratorClass<type> & otherIt);

	void operator = (const iteratorClass<type> & otherIt);

	void operator ++ ();
	void operator --();

	void setIterator(Node<type> * somePtr);
	type returnIterator();

	Node<type*> operator ~();
};



template<class type>
type iteratorClass<type>::returnIterator()
{
	return ptr->GetData();
}

template<class type>
iteratorClass<type>::iteratorClass(const Node<type> & someNode)
{
	ptr = someNode;
}

template<class type>
iteratorClass<type>::iteratorClass()
{
}

template<class type>
bool iteratorClass<type>::operator!=(const iteratorClass<type> & otherIt)
{
	return ptr != otherIt.ptr;
}

template<class type>
bool iteratorClass<type>::operator == (const iteratorClass<type> & otherIt)
{
	return ptr == otherIt.ptr;
}

template<class type>
bool iteratorClass<type>::operator < (const iteratorClass<type> & otherIt)
{
	return ptr->GetData() < otherIt->GetData();
}

template<class type>
bool iteratorClass<type>::operator > (const iteratorClass<type> & otherIt)
{
	return ptr->GetData() > otherIt->GetData();
}

template<class type>
void iteratorClass<type>::operator = (const iteratorClass<type> & otherIt)
{
	ptr = otherIt.ptr;
}

template<class type>
void iteratorClass<type>::operator ++()
{
	ptr = ptr->GetNext();
}


template<class type>
void iteratorClass<type>::operator--()
{
	ptr =  ptr->GetPrevious();
}

template<class type>
void iteratorClass<type>::setIterator(Node<type> * somePtr)
{
	ptr = somePtr;
}



#endif /* ITERATOR_H_ */
