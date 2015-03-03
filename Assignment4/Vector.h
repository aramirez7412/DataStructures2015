/*******************************************************************************
 * This template is dedicated to the a vector ADT that is implemented with
 * a doubly linked list.
 *
 * Further documentation.....
 ******************************************************************************/
#ifndef VECTOR_H_
#define VECTOR_H_

#include "Node.h"
#include "Iterator.h"
#include "ConstIterator.h"
using namespace std;


template<class type>
class vector
{
private:

//	const int NULL = 0;


private:

	Node<type> * _head;
	Node<type> * _tail;

	int _size;
	int _maxSize;
public:
	typedef iteratorClass<type> iterator;


//	class it : public iterator<type>
//	{
//		it(){};
//
//	};
	//Default constructor
	vector();

	//Copies another vector into the current vector
//	vector(vector<type> someVector);

	//Creates a vector with size n
	vector(int size);

	//Creates a vector with size n with all nodes initialized to element
//	vector(int size, const type element); not implemented


	//Sorts the entire vector
	void sort();

	//Checks if the vector is empty
	bool empty();

	//returns the current size of the vector
	int size();


	//pushes an element to the back of the vector
	void push_back(const type & data); // DONE

	void createTrailer(); //DONE


	//This method will pop the last node off of the vector
	bool vpop_back(type & popped_data); //DONE

	//Maybe
	//void pop_front();

	//THis insert will take an iterator position as a parameter and the value of
	//the element that will be input
	void insert(iteratorClass<type> * position, const type element);


	//returns an iterator at the beginning of the vector
	iteratorClass<type>  begin();

	//returns an iterator at the end of the vector
	iteratorClass<type>  end();

	//peek front
	type front();

	//peek back
	type back();


	bool vpop_front(type & popped_data);

	void outputList();

};


template<class type>
bool vector<type>::vpop_front(type & popped_data)
{
	Node<type>* temp;

	if(_head == 0)
	{
		return false;
	}
	else
	{
		temp  = _head;
		if(_head->GetNext() != _tail)
		{
			_head->GetNext()->SetPrevious(0);
			_head = _head->GetNext();
		}
		else
		{
			_head->SetNext(_tail);
			_tail->SetPrevios(_head);
		}

		temp->Orphan();
		delete temp;

		temp = NULL;
		return true;
	}
}


template<class typeName>
void vector<typeName>::outputList()
{
	//D E C L A R A T I O N S
	Node<typeName> * traverse; //Processing - this pointer will be used to
							   //traverse the queue

	//P R O C E S S I N G

	traverse = _head;
	if(_head == _tail)
	{
		cout << "The list is empty nothing output" << endl;
	}
	else
	{
		while(traverse != _tail)
		{
			cout << "Data: " << traverse->GetData() << endl;

			traverse = traverse->GetNext();
		}
	}
}

template<class type>
bool vector<type>::empty()
{
	return _head == _tail;
}

template<class type>
type vector<type>::front()
{
	try
	{
		if(empty())
		{
			throw;
		}
		else
		{
			return _head->GetData();
		}
	}
	catch(...)
	{
		cout << "Failed to see front";
	}
}


template<class type>
type vector<type>::back()
{

	try
	{
		if(empty)
		{
			throw;
		}
		else
		{
			return _tail->GetPrevious()->GetData();
		}
	}
	catch(...)
	{
		cout << "Failed to see back";
	}

}

template<class type>
iteratorClass<type> vector<type>::begin()
{
	iteratorClass<type> begin;

	begin.setIterator(_head);

	return begin;
}


template<class type>
iteratorClass<type> vector<type>::end()
{
	iteratorClass<type> temp;

	temp.setIterator(_head);

	return temp;
}

template<class type>
int vector<type>::size()
{
	return _size;
}

template<class type>
void vector<type>::insert(iteratorClass<type> * position, const type element)
{
	Node<type> * traverse;
	Node<type> * newNode;
	bool found;

	found = false;

	traverse = _head;
	while(traverse != _tail && !found)
	{
		if(traverse == position->returnIterator())
		{
			found = true;
		}
		else
		{
			traverse = traverse->GetNext();

		}
	}

	if(found)
	{
		if(_head == position->returnIterator())
		{
			newNode = new Node<type>;

			newNode->setNext(_head);
			_head->SetPrevious(newNode);

			_head = newNode;
		}
		else
		{
			newNode = new Node<type>;

			newNode->SetData(element);

			newNode->setNext(position->returnIterator());
			newNode->setPrevious(position->returnIterator()->GetPrevious());
			newNode->getPrevious()->setPrevious(newNode);
			newNode->getNext()->setPrevious(newNode);
		}

		_size++;
	}
}

template<class type>
void vector<type>::createTrailer()
{
	Node<type> * trailer;

	trailer = new Node<type>;

	_head        = trailer;
	_tail        = trailer;


}

template<class type>
vector<type>::vector()
{
	_head = NULL;
	_tail = NULL;
	_size = 0;

	createTrailer();
}


template<class type>
void vector<type>::push_back(const type & data)
{
	//D E C L A R A T I O N S
	Node<type> * ptr; //Processing - This pointer variable will be used to
							  //             create dynamic memory. This variable
							  // 			 will be responsible for adding a new
							  //			 node to the back of the list

	//I N I T I A L I Z A T I O N S
	ptr= new Node <type>; //New node being pushed to the back of the list

	//Stores the data being passed in to the new Nodes "_data" attribute
	// (See Node class interface and check SetData method for more details)
	ptr->SetData(data);

	//this "if-statement" will check if the list is not empty by comparing the
	//_head attribute to NULL
	if(_head != _tail)
	{
		ptr->SetPrevious(_tail->GetPrevious());
		ptr->SetNext(_tail);
		_tail->GetPrevious()->SetNext(ptr);
		//the node that the _tail is pointing too will now point the nodes next
		//to ptr the new node being pushed to the back
		_tail->SetPrevious(ptr);

		//Assigns the new node's "previous pointer" to the current _tail
		ptr->SetNext(_tail);

		cout << "Data being pushed: " <<  _tail->GetPrevious()->GetData() << endl << endl;

		//		cout << "Pushing " << ptr->GetData() << " onto the Deque" << endl;
		_size++;
	}
	else
	{
		//If the list is empty both _head and _tail are assigned to ptr
		_head = ptr;
		_tail->SetPrevious(ptr);
		_head->SetNext(_tail);
//		cout << "Pushing " << ptr->GetData() << " onto the queue" << endl;
		_size++;

		cout << endl << endl;
//		cout << "Heads Data first entry: " << _head->GetData();
		cout << endl << endl;
	}

		ptr = NULL;
}


template <class typeName>
bool vector<typeName>::vpop_back(typeName & poppedData)
{
	//D E C L A R A T I O N S
	bool isEmpty; // Processing - This boolean will be returned from the
				  //			  method and will determine if the
				  //              list is empty or not.
	Node<typeName> * ptr; // Processing - This pointer will be used to delete
						  //			  the last node from the queue

	//I N I T I A L I Z A T I O N S
	isEmpty = false;
	ptr     = NULL;

	if(_head == _tail)
	{
		cout << "Cannot remove from an empty queue" << endl;

		//Reassigns isEmpty to signify that the queue is empty now
		isEmpty = true;
	}
	//This "if statement will check if _head's value is equal to _tail's value
	else if(_head == _tail->GetPrevious())
	{
		//Assigns ptr to head so proper deletion of the node can be done
		ptr = _head;

		poppedData = ptr->GetData();

		//Points both _head and _tail to NULL to simulate an empty list since
		//the last node was removed
		_head = _tail;
		_tail->SetPrevious(_head);

		//Orphans the node to ensure that all links are broken
		ptr->Orphan();

//		cout << "Removing " << ptr->GetData() << " from the queue" <<  endl;

		//deallocated memory associated with pointer.
		delete ptr;

		_size--;
		//Returns false since the queue does NOT contain any nodes
	}
	else
	{
		//If precedence reaches this block than removal of node will happen as
		//usual. Ptr will point to the last node
		ptr = _tail->GetPrevious();

		poppedData = ptr->GetData();


		ptr->GetPrevious()->SetNext(_tail);

		_tail->SetPrevious(ptr->GetPrevious());

		ptr->Orphan();

		delete ptr;

		_size--;
	}
	return isEmpty;
}

#endif /* VECTOR_H_ */
