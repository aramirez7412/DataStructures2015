/*******************************************************************************
 * Dequeue_Template
 * -----------------------------------------------------------------------------
 * This template will be an input restricted double ended queue ka Dequeue. A
 * Dequeue is an ADT that generalizes a queue, for which elements can be added
 * to or removed from either the front (head) or back (tail). This differs from
 * a queue ADT or FIFO where elements can only be added to one end and removed
 * from the other. This Dequeue is of the Input restricted sub-type. Some
 * operations include push_back, push_front, pop_back, pop_front, peek_back,
 * peek_front.
 *******************************************************************************/

#ifndef DEQUEUE_TEMPLATE_H_
#define DEQUEUE_TEMPLATE_H_

//Pre-Processor Directives
#include "Node.h"    //Node contains the template for the container
#include <string>    //Used for strings
#include <sstream>   //Used for utilizing the string stream
#include <iomanip>   //Used for output manipulation
#include <iostream>  //Used to output to the console
using namespace std;
//



template <class typeName>
class Dequeue
{
	/***************************************************************************
	 * P R I V A T E
	 * -------------------------------------------------------------------------
	 * The private attributes are found here
	 ***************************************************************************/

private:

	//P R I V A T E ~ A T T R I B U T E S

	Node<typeName> * _head;
	Node<typeName> * _tail;

public:

	//P U B L I C ~ M E T H O D S

	//M U T A T O R S

	/***************************************************************************
	* Title      : Dequeue
	* Type       : Constructor
	* Description: This method will push a node to the front of the list
	****************************************************************************/
	//Title		 : constructor
	//Type       : method
	//Description: This method will construct an instance of a Dequeue and
	//			   initialize all of its attributes.
	Dequeue();


	/***************************************************************************
	* Title      : ~Dequeue
	* Type       : De-Constructor
	* Description: This method will destruct a queue
	****************************************************************************/
	~Dequeue();


	/***************************************************************************
	* Title      : push_back
	* Type       : Method
	* Description: This method will push a node to the end of the list
	****************************************************************************/
	void push_back(const typeName& data);

	/***************************************************************************
	* Title      : push_front
	* Type       : Method
	* Description: This method will push a node to the front of the list
	****************************************************************************/
	void push_front();

	/***************************************************************************
	* Title      : pop_front
	* Type       : method
	* Description: This method will pop off a node from the front of the list.
	* 			   A variable will be passed in to take the value of the popped
	* 			   element. The method will return a boolean that will establish
	* 			   if the list is empty or not.
	****************************************************************************/
	bool pop_front(typeName & poppedData);

	/***************************************************************************
	* Title      : pop_back
	* Type       : method
	* Description: This method will pop off a node to the end of the list.
	* 			   A variable will be passed in to take the value of the popped
	* 			   element. The method will return a boolean that will establish
	* 			   if the list is empty or not.
	****************************************************************************/
	bool pop_back(typeName & poppedData);


	//A C C E S S O R S
	//The following methods do not manipulate data within the nodes
	/***************************************************************************
	* Title      : peek_front
	* Type       : method
	* Description: This method will return the item in the front of the list
	****************************************************************************/
	typeName peek_front();

	/***************************************************************************
	* Title      : peek_back
	* Type       : method
	* Description: This method will return the item in at the end of the list
	****************************************************************************/
	typeName peek_back();

	/***************************************************************************
	* Title      : outputList
	* Type       : method
	* Description: This method will output the full list
	****************************************************************************/
	void outputList();

	/***************************************************************************
	* Title      : DestroyList
	* Type       : method
	* Description: This method will destroy the list
	****************************************************************************/
	void DestroyList();

	Node<typeName>* GetHead();


	Node<typeName>* GetTail();

	int GetSize();

};


template<class typeName>
int Dequeue<typeName>::GetSize()
{
	int index;

	index = 0;
	Node<typeName>* ptr;

	ptr = _head;
	while(ptr != NULL)
	{
		ptr = ptr->GetNext();
		index++;
	}

	return index;

}

template<class typeName>
Node<typeName>* Dequeue<typeName>::GetHead()
{
	return _head;
}

template<class typeName>
Node<typeName>* Dequeue<typeName>::GetTail()
{
	return _tail;
}


/*******************************************************************************
 * Method Implementation
 *******************************************************************************/

//Title		 : constructor
//Type       : method
//Description: This method will construct an instance of a Dequeue and
//			   initialize all of its attributes.
template<class typeName>
Dequeue<typeName>::Dequeue()
{
		_head = NULL;
		_tail = NULL;
}


//Title		 : Destructor
//Type       : method
//Description: This method will destruct an instance of a Dequeue and
//			   delete all memory
template<class typeName>
Dequeue<typeName>::~Dequeue()
{
	//begin try block

		delete _head;
	//end try
	//begin catch

	//end catch
}


/***************************************************************************
* Title      	: push_back
* Type       	: Method
* Description	: This method will push a node to the end of the list
* Testing Status: Done with testing
****************************************************************************/
template<class typeName>
void Dequeue<typeName>::push_back(const typeName & data)
{
	//D E C L A R A T I O N S
	Node<typeName> * ptr; //Processing - This pointer variable will be used to
						  //             create dynamic memory. This variable
						  // 			 will be responsible for adding a new
						  //			 node to the back of the list

	//I N I T I A L I Z A T I O N S
	ptr= new Node <typeName>; //New node being pushed to the back of the list

	//Stores the data being passed in to the new Nodes "_data" attribute
	// (See Node class interface and check SetData method for more details)
	ptr->SetData(data);

	//this "if-statement" will check if the list is not empty by comparing the
	//_head attribute to NULL
	if(_head == NULL)
	{
		_head = ptr;
		_tail = ptr;
	}
	else
	{
		//the node that the _tail is pointing too will now point the nodes next
		//to ptr the new node being pushed to the back
		_tail->SetNext(ptr);

		//Assigns the new node's "previous pointer" to the current _tail
		ptr->SetPrevious(_tail);

		//reassigns _tail to ptr.aka Updating the _tail to point to the new node!
		_tail = ptr;

	}

}

/***************************************************************************
* Title      : pop_front
* Type       : method
* Description: This method will pop off a node from the front of the list.
* 			   A variable will be passed in to take the value of the popped
* 			   element. The method will return a boolean that will establish
* 			   if the list is empty or not.
****************************************************************************/
template<class typeName>
bool Dequeue<typeName>::pop_front(typeName & poppedData)
{
	//D E C L A R A T I O N S
	Node<typeName> * ptr; //Processing - This pointer will be used to delete the
						  //             first node of the queue

	bool containsData = true;
	//I N I T I A L I Z A T I O N S
	ptr     = NULL;
//	try
//	{
		if(_head == NULL)
		{
			//Reassigns isEmpty to true since the queue is now empty
			containsData = false;

		}
		else if(_head == _tail)
		{
			ptr = _head;

			poppedData = ptr->GetData();

			_head = NULL;
			_tail = NULL;

			ptr->Orphan();

			delete ptr;
		}
		else
		{
			//If precedence reaches this block than removal of node will happen as
			//usual. Ptr will point to the last node
			ptr = _head;

			poppedData = ptr->GetData();



			//_head pointer will change the second node's prev pointer
			//to NULL since it will become the last node in the list
			_head->GetNext()->SetPrevious(NULL);


			//_tail is re-assigned to the second-to-last node aka updating the _head
			_head = _head->GetNext();

			//Oprhans the node associated with ptr.
			ptr->Orphan();

			//deallocated memory associated with ptr
			delete ptr;
		}


	return containsData;
}


/***************************************************************************
* Title      : pop_back
* Type       : method
* Description: This method will pop off a node to the end of the list.
* 			   A variable will be passed in to take the value of the popped
* 			   element. The method will return a boolean that will establish
* 			   if the list is empty or not.
****************************************************************************/
template <class typeName>
bool Dequeue<typeName>::pop_back(typeName & poppedData)
{
	//D E C L A R A T I O N S

	Node<typeName> * ptr; // Processing - This pointer will be used to delete
						  //			  the last node from the queue
	bool containsData;
	//I N I T I A L I Z A T I O N S
	ptr          = NULL;
	containsData = true;
//	try
//	{
		if(_tail == NULL)
		{
			containsData = false;
			//Reassigns isEmpty to signify that the queue is empty now
		}
		//This "if statement will check if _head's value is equal to _tail's value
		else if(_head == _tail)
		{
			//Assigns ptr to head so proper deletion of the node can be done
			ptr = _tail;

			poppedData = ptr->GetData();

			_head = NULL;
			_tail = NULL;

			ptr->Orphan();

			delete ptr;
			//Returns false since the queue does NOT contain any nodes
		}
		else
		{

			//If precedence reaches this block than removal of node will happen as
			//usual. Ptr will point to the last node
			ptr = _tail;

			poppedData = ptr->GetData();


			//_head pointer will change the second node's prev pointer
			//to NULL since it will become the last node in the list
			_tail->GetPrevious()->SetNext(NULL);


			//_tail is re-assigned to the second-to-last node aka updating the _tail
			_tail = _tail->GetPrevious();

			//Oprhans the node associated with ptr.
			ptr->Orphan();

			//deallocated memory associated with ptr
			delete ptr;
		}
//	}
//	catch(...)
//	{
//
//	}
	return containsData;
}

/***************************************************************************
* Title      : peek_front
* Type       : method
* Description: This method will return the item in the front of the list
****************************************************************************/
template<class typeName>
typeName Dequeue<typeName>::peek_front()
{
	if(_head != NULL)
	{
		return _head->GetData();
	}
}

/***************************************************************************
* Title      : peek_back
* Type       : method
* Description: This method will return the item in at the end of the list
****************************************************************************/
template<class typeName>
typeName Dequeue<typeName>::peek_back()
{
	if(_tail != NULL)
	{
		return _tail->GetData();
	}
}

/***************************************************************************
* Title      : outputList
* Type       : method
* Description: This method will output the full list
****************************************************************************/
template<class typeName>
void Dequeue<typeName>::outputList()
{
	//D E C L A R A T I O N S
	Node<typeName> * traverse; //Processing - this pointer will be used to
							   //traverse the queue

	//P R O C E S S I N G

	traverse = _head;
	if(_head == NULL)
	{
		cout << "The list is empty nothing output" << endl;
	}
	else
	{
		while(traverse != NULL)
		{
			cout << "Data: " << traverse->GetData() << endl;

			traverse = traverse->GetNext();
		}

	}
}


/***************************************************************************
* Title      : DestroyList
* Type       : method
* Description: This method will destroy the list
****************************************************************************/
template<class typeName>
void Dequeue<typeName>::DestroyList()
{
	delete _head;
	_head = NULL;
}

#endif /* DEQUEUE_TEMPLATE_H_ */
