#include "Header.h"
#include "Vector.h"

int main()
{
	Queue<string> stringQueue;
	string temp;

	vector<string> myStringVector;
	vector<string>::iterator it;

	Node<string>* tempNode;


	cout << "******************************************" << endl;
	cout << "*                Part A                  *" << endl;
	cout << "******************************************" << endl;


	cout << "Enqueueing data" << endl;
	stringQueue.enqueue("Hello");
	stringQueue.enqueue("Was it a car or a cat I saw");
	stringQueue.enqueue("Sit on a potato pan, otis");
	stringQueue.enqueue("Isn't this class cool");

	stringQueue.OutputList();


	cout << endl << "The size of the queue is: " << stringQueue.size();
	cout << endl;


	//Testing is Empty method
	if(!stringQueue.isEmpty())
	{
		//Testing dequeue
		stringQueue.dequeue(temp);

		cout << "***********************************************";
		cout << endl << "Dequeueing " << temp << endl;
		cout << "***********************************************";
		cout << endl << endl;
	}
	else
	{
		cout << "The list is empty. Can't dequeue";
	}

	//testing output list
	stringQueue.OutputList();


	//Testing Dequeue method
	if(!stringQueue.isEmpty())
	{
		//testing dequeue
		stringQueue.dequeue(temp);

		cout << "***********************************************";
		cout << endl << "Dequeueing " << temp << endl;
		cout << "***********************************************";
		cout << endl << endl;
	}
	else
	{
		cout << "The list is empty. Can't dequeue";
	}

	stringQueue.OutputList();

	//Testing Dequeue Method
	if(!stringQueue.isEmpty())
	{
		//testing dequeue
		stringQueue.dequeue(temp);

		cout << "***********************************************";
		cout << endl << "Dequeueing " << temp << endl;
		cout << "***********************************************";
		cout << endl << endl;
	}
	else
	{
		cout << "The list is empty. Can't dequeue";
	}


	//testing size
	cout << endl << "The size of the queue is: " << stringQueue.size() << endl << endl;

	//testing output list
	stringQueue.OutputList();

	cout << endl << "This is the front: " << stringQueue.front();


	cout << endl << endl << endl;
	cout << "******************************************" << endl;
	cout << "*                Part B                  *" << endl;
	cout << "******************************************" << endl;

//
//
//	vector<string> myStringVector;
//	vector<string>::iterator it;

	myStringVector.push_back("Hello");


	myStringVector.outputList();
	myStringVector.push_back("Coffee");
	myStringVector.outputList();
	myStringVector.push_back("ComputerScience");

	myStringVector.vpop_back(temp);
	cout << endl <<"Popping back: " << temp << endl;
	myStringVector.outputList();


	it = myStringVector.begin();

	++it;

	temp = it.returnIterator();
	cout << endl << "Data Retreived using an iterator: " << temp << endl << endl;


	myStringVector.push_back("I like water polo");
	myStringVector.outputList();
	myStringVector.push_back("Pointers are awesome");
	myStringVector.outputList();
	cout << endl << endl << "Current size: " << myStringVector.size() << endl
		 << endl;

	cout << "Using is Empty method: " << endl;
	if(myStringVector.empty())
	{
		cout << "The vector is empty" << endl;
	}
	else
	{
		cout << "The vector is not empty" << endl;
	}

	myStringVector.vpop_back(temp);
	cout << endl << "Popping: " << temp << endl << endl;
	myStringVector.outputList();

	myStringVector.vpop_back(temp);
	cout << endl << "Popping: " << temp << endl << endl;
	myStringVector.outputList();

	return 0;



}
