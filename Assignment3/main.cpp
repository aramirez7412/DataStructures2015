/*******************************************************************************
 * Name          : Anthony Ramirez
 * CS1D		     : Tuesday/Thursday
 * Assignment #3 :
 * Date          : 2/10/15
 ******************************************************************************/

#include "Header.h"
#include <vector>
#include <ostream>
#include <iterator>
#include "LinkedList.h"
/*******************************************************************************
 *
 */

bool ParenMatch(char a[], const int SIZE);

int main()
{
	OutputHeader(cout, "Anthony Ramirez", "CS1D", "Tuesday/Thursday", 1, "Lab name",'A');

	const int STRING_AR = 6;
	const int FLOAT_AR = 5;

	string array[STRING_AR] = {"Paula","JoAnn", "Jack", "Mark", "Paul", "Eric"};
	float    floatArray[FLOAT_AR]  = {2788.123, 243.76, 8445.5612, 19833.121, 12.4};
	int     intArray[8] = {98,88,88,123,8445,9833,12,354};

	Dequeue<string> myStringDeque;
	Dequeue<float>  myFloatDeque;
	Dequeue<int>    myIntDeque;


	List<string> myStringList;
	List<float>  myFloatList;
	List<int>    myIntList;

	//Initializes vectors to the arrays
	vector<string> stringVector(array, array+6);
	vector<float>  floatVector(floatArray, floatArray+5);
	vector<int>    intVector(intArray, intArray+8);

	//Declaring ostream iterators to output the vectors
	ostream_iterator<string> outString(cout, " ");
	ostream_iterator<float>  outFloat(cout, " ");
	ostream_iterator<int>    outInt(cout, " ");

	cout << "*********************************************" << endl;
	cout << "* Vector" << endl;
	cout << "*********************************************" << endl;
	//Outputing the string vector

	cout << "Inputing strings..." << endl;

	for(int index = 0; index < STRING_AR; index++)
	{
		cout << array[index] << endl;
	}


	cout << endl;
	cout << "Outputing Vector containing strings: " << endl;
	copy(stringVector.begin(), stringVector.end(), outString);
	//Displaying results of string vector

	cout <<endl << endl<<  "Popping Last Entered: Eric" << endl;
	stringVector.pop_back();

	copy(stringVector.begin(), stringVector.end(), outString);



	cout << "Inputing floats..." << endl;

	for(int index = 0; index < FLOAT_AR; index++)
	{
		cout << floatArray[index] << endl;
	}

	cout << endl;
	cout << "Outputting Vector containing floats: " << endl;
	copy(floatVector.begin(), floatVector.end(), outFloat);


	cout << endl << endl << "Popping Last Entered: 12.4" << endl;
	floatVector.pop_back();
	copy(floatVector.begin(), floatVector.end(), outFloat);

	//Integer
	cout << "Inputing integers..." << endl;

	for(int index = 0; index < 8; index++)
	{
		cout << intArray[index] << endl;
	}

	cout << endl;
	cout << "Outputting Vector containing integers: " << endl;
	copy(intVector.begin(), intVector.end(), outInt);

	cout << endl << endl << "Popping Last Entered: 354" << endl;
	intVector.pop_back();
	copy(intVector.begin(), intVector.end(), outInt);

	cout << endl << endl;

	//Using a Deque
//	string array[STRING_AR] = {"Paula","JoAnn", "Jack", "Mark", "Paul", "Eric"};
//		float    floatArray[FLOAT_AR]  = {2788.123, 243.76, 8445.5612, 19833.121, 12.4};
//		int     intArray[8] = {98,88,88,123,8445,9833,12,354};
//
//		Dequeue<string> myStringDeque;
//		Dequeue<float>  myFloatDeque;
//		Dequeue<int>    myIntDeque;


	cout << "*********************************************" << endl;
	cout << "* Deque" << endl;
	cout << "*********************************************" << endl;


	//String Deque
	for(int index = 0; index < STRING_AR; index++)
	{
		myStringDeque.push_back(array[index]);
	}
	cout << endl << endl;

	cout << "String Deque: " << endl;
	myStringDeque.outputList();


	//Float Deque
	for(int index = 0; index < FLOAT_AR; index++)
	{
		myFloatDeque.push_back(floatArray[index]);
	}

	cout << endl << endl;
	cout << "Float Deque: " << endl;
	myFloatDeque.outputList();

	//Int Deque
	for(int index = 0; index < 8; index++)
	{
		myIntDeque.push_back(intArray[index]);
	}
	cout << endl << endl;
	myIntDeque.outputList();

//
//	List<string> myStringList;
//		List<float>  myFloatList;
//		List<int>    myIntList;

	cout << "*********************************************" << endl;
	cout << "* Singly Linked List" << endl;
	cout << "*********************************************" << endl;
	//String List
	for(int index = 0; index < STRING_AR; index++)
	{
		myStringList.Enqueue(array[index]);
	}
	cout << endl << endl;

	cout << "String List: " << endl;
	myStringList.OutputList();


	//Float List
	for(int index = 0; index < FLOAT_AR; index++)
	{
		myFloatList.Enqueue(floatArray[index]);
	}

	cout << endl << endl;
	cout << "Float List: " << endl;
	myFloatList.OutputList();

	//Int Deque
	for(int index = 0; index < 8; index++)
	{
		myIntList.Enqueue(intArray[index]);
	}
	cout << endl << endl;
	myIntList.OutputList();



	cout << endl << endl << endl;
	cout << "*********************************************" << endl;
	cout << "* Parenthesis Algorithm" << endl;
	cout << "*********************************************" << endl;

	char arrayOne[4] ={ '{','}','{','}'};
	char arrayTwo[5] = {'{',')','(',')','}'};
	char arrayThree[6] = {'[','(',')','[',']',']'};
	char arrayFour[8] = {'[','(',')','[',']',')',')',')'};

	cout << endl << "Array One " << "{2x+3} {7x+8}" << endl;
	if(ParenMatch(arrayOne, 4))
	{
		cout << endl <<"*****Match******"<< endl;

	}
	else
	{
		cout << endl <<"*****NO Match******"<< endl;
	}

	cout << endl << "Array Two " << "{2x + 5) (6x+4)}" << endl;

	if(ParenMatch(arrayTwo, 5))
	{
		cout << endl << "*****Match******"<< endl;

	}
	else
	{
		cout << endl << "*****NO Match******" << endl;
	}


	cout << endl << "Array Three " << "[(8x+5) - 4x[9x+3]]" << endl;
	if(ParenMatch(arrayThree, 6))
	{
		cout << endl << "*****Match******" << endl;

	}
	else
	{
		cout << endl << "*****NO Match******" << endl;
	}

	cout << endl << "Array Four " << "{(8x+5) - 5x[9x+3]})" << endl;
	if(ParenMatch(arrayFour, 8))
	{
		cout << endl << "*****Match******" << endl;

	}
	else
	{
		cout << endl <<"*****NO Match******" << endl;
	}



	char arrayFive[9] = {'(','(','(',')','[',']',')',')',')'};
	cout << endl << "Array Five " << "(((8x+5) - x[9x+3])))" << endl;
	if(ParenMatch(arrayFive, 9))
	{
		cout << endl << "*****Match******" << endl;

	}
	else
	{
		cout << endl << "***** NO Match******"<< endl;
	}


	char arraySix[6] = {'{','(',')','[',']',']'};

	cout << endl << "Array Siz " << "{(8x+5) - 9x[9x+3]]" << endl;
	if(ParenMatch(arraySix, 8))
	{
		cout << endl << "*****Match******" << endl;

	}
	else
	{
		cout << endl << "*****NO Match******"<< endl;
	}

}


bool ParenMatch(char a[], const int SIZE)
{
	Dequeue<char> list;
	char temp;

	for(int index = 0; index < SIZE; index++)
	{
		if(a[index] == '(' || a[index] == '{' ||a[index] == '[' )
		{
			list.push_back(a[index]);
		}
		else if(a[index] == ')' || a[index] == '}'||a[index] == ']')
		{
			if(list.isEmpty())
			{
				return false;
			}



			switch(list.peek_back())
			{
			case '{': temp = '}';
			break;

			case'[': temp = ']';
			break;

			case '(' : temp = ')';
			break;


			}


			if(temp != a[index])
			{
				return false;
			}
			else
			{
				list.pop_front(temp);
			}
		}
	}


	if(list.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}




