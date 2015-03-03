/*
 * Queue.h
 *
 *  Created on: Feb 16, 2015
 *      Author: aramirez7412
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Deque_Template.h"

template<class typeName>
class Queue: public Deque<typeName>
{
	private:


	public:

	int      size();//

	bool     empty();//

	typeName front();

	void enqueue(const typeName & data);//

	bool dequeue(typeName & poppedData);//

	void OutputList();
};


template<class typeName>
typeName Queue<typeName>::front()
{
	return Deque<typeName>::peek_front();
}

template<class typeName>
int Queue<typeName>::size()
{
	return Deque<typeName>::size();
}


template<class typeName>
bool Queue<typeName>::empty()
{
	return Deque<typeName>::isEmpty();
}

template<class typeName>
void Queue<typeName>::enqueue(const typeName & data)
{
	Deque<typeName>::insertBack(data);
}


template<class typeName>
bool Queue<typeName>::dequeue(typeName & poppedData)
{
	Deque<typeName>::eraseFront(poppedData);
}


template<class typeName>
void Queue<typeName>::OutputList()
{
	Deque<typeName>::outputList();
}




#endif /* QUEUE_H_ */
