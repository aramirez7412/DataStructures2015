/*
 * Node.h
 *
 *  Created on: Feb 28, 2015
 *      Author: aramirez7412
 */

#ifndef NODE_H_
#define NODE_H_


#include <iostream>

template<class A, class B>
class Node;

//template<class A,class B>
//Node<A,B> & operator < (const Node<A,B> & lhs, const Node<A,B> & rhs);
//


template<class A, class B>
class Node
{
private:


	A priorityClass;
	B data;

public:

	//Constructor


	Node(const A & setPriority, const B & setData);
	Node();

	//Destructor
	~Node();


	void setPriorityClass(const A & setPriority);
	void setData(const B & setData);

	void setAllData(const A & setPriority, const B & newData);

	B getData();


	A returnPriority();
	B returnData();

	bool operator < (Node<A, B> rhs) const;

	bool operator > (Node<A, B> rhs) const;

	Node<A,B> & operator = (Node<A, B> rhs);

	void output();
//	friend Node<A,B> & operator < (const Node<A,B> lhs, const Node<A,B> & rhs);

};

//template<class A, class B>
//Node<A,B> & operator = (const Node<A,B> & lhs, const Node<A,B> & rhs)
//{
//
//}

template<class A, class B>
B Node<A,B>::getData()
{
	return data;
}

template<class A, class B>
void Node<A,B>::output()
{
//	std::cout << "Data     : " << data          << std::endl;
	std::cout << "Val: " << priorityClass << " ,";
}


template<class A, class B>
void Node<A,B>::setAllData(const A & priorityData, const B & newData)
{
	priorityClass = priorityData;
	data          = newData;
}

/******************************************************************************
 * Overloaded assignment operator
 * _____________________________________________________________________________
 *
 */
template<class A, class B>
Node<A, B> & Node<A,B>::operator  = (Node<A,B> rhs)
{
	if(this == & rhs)
	{
		return *this;
	}

	data = rhs.data;
	priorityClass = rhs.priorityClass;

	return *this;



}

template<class A, class B>
Node<A,B>::Node(const A & setPriority, const B & setData)
{
	priorityClass = setPriority;
	data          = setData;
}


template<class A, class B>
void Node<A,B>::setPriorityClass(const A & setPriority)
{
	priorityClass = setPriority;
}

template<class A, class B>
void Node<A,B>::setData(const B & setData)
{
	data = setData;
}

template<class A, class B>
A Node<A,B>::returnPriority()
{
	return priorityClass;
}

template<class A, class B>
B Node<A,B>::returnData()
{
	return data;
}

template<class A, class B>
Node<A, B>::Node()
{
}


template<class A, class B>
Node<A, B>::~Node()
{

}
//Returns the attribute left
//template<class A, class B>
//Node<A, B>* Node<A,B>::getLeft() const
//{
//	//returns left pointer
//	return left;
//}
//
////Returns the attribute right
//template<class A, class B>
//Node<A, B>* Node<A, B>::getRight() const
//{
//	return right;
//}

//Overloaded the less than operator to distinguish if the the poitners node to
//the leftis less than the pointers node to the right
template<class A, class B>
bool Node<A, B>::operator<(Node<A, B> rhs) const
{
	//First checks the nodes priority, if the priority is the same than...
	if(priorityClass == rhs.priorityClass)
	{

		//It checks the data (probably should do an additional check to ensure
		//that there is no duplicate names but there is only two peices of data
		//wiithin this node so we cannot check anything else
		return (data < rhs.data);
	}
	else
	{
		//Returns true if the left node is less than the right node
		return (priorityClass < rhs.priorityClass);
	}
}


template<class A, class B>
bool Node<A, B>::operator>( Node<A,B> rhs) const
{
	//First checks the nodes priority, if the priority is the same than...
	if(priorityClass == rhs.priorityClass)
	{

		//It checks the data (probably should do an additional check to ensure
		//that there is no duplicate names but there is only two peices of data
		//wiithin this node so we cannot check anything else
		return (data > rhs.data);
	}
	else
	{
		//Returns true if the left node is greater than the right node
		return (priorityClass > rhs.priorityClass);
	}
}
#endif /* NODE_H_ */
