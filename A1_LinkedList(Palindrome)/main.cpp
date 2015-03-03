/*******************************************************************************
 * Name          : Anthony Ramirez
 * CS1D		     : Tuesday/Thursday
 * Assignment #1 : name
 * Date          : 1/27/15
 ******************************************************************************/

#include "Header.h"


bool isPalindrome(string someString);
int main()
{
	OutputHeader(cout, "Anthony Ramirez", "CS1D", "Tuesday/Thursday",
				1, "Assignment name",'A');

	const int AR_SIZE = 10;
	string wordList[AR_SIZE] = { "dad",
								 "radar",
								 "Otto",
								 "mom",
								 "tigers",

								 "A man, a plan, a canal, Panama",
								 "Isn't this class cool?",
								 "Was it a car or a cat I saw",
								 "Sit on a potato pan, Otis",
								 "Saddleback is a great place to learn"};


	for(int index = 0; index < AR_SIZE; index++)
	{
		if(isPalindrome(wordList[index]))
		{
			cout << "Is a palindrome: " << wordList[index] << endl;
		}
		else
		{
			cout << "Not a palindrome: " << wordList[index] << endl;
		}
	}
	return 0;
}


bool isPalindrome(string someString)
{
	//D E C L A R A T I O N
	Dequeue<char> charList; //Processing - used to build a list. In the
							//processing segment of this function the string
						    //being passed in will be parsed an each individual
							//character will be placed within a node of the
							//double ended queue
	bool isPalindrome; //Processing - this boolean variable will be returned
					   // and will be changed dependent on whether or not
					   // the string is a palindrome.
	int length;		   //Processing - used to store the length of the string
					   //being passed in
	int count;		   //Processing - used to store length divided by two
	int index;         //Processing - used to track sentinel value of while
					   //while loop at line 45
	int whileCount;    //Used as a counter in while loop in line 57
	char temp1;        //Used to store the data from first node
	char temp2;		   //Used to store the data from the last node




	//I N I T I A L I Z A T I O N
	isPalindrome = true;
	length       = someString.length();
	whileCount   = 0;

	//Builds the Double ended queue and does not allow special characters
	// to be added
	for(index = 0; index < length; index++)
	{
		if(tolower(someString[index]) < 123 && tolower(someString[index]) > 96)
		{
			charList.push_back(tolower(someString[index]));
		}
	}

	//Gets count by getting node amount and dividing it by 2
	count 		 = charList.GetSize()/2;

	//THis while loop will continue looping until a character does not match or
	//until it is empty
	while(whileCount < count && isPalindrome)
	{
		if(!charList.pop_front(temp1) || !charList.pop_back(temp2))
		{
			isPalindrome = false;
		}
		if(temp1 != temp2)
		{

			isPalindrome = false;
		}
		whileCount++;
	}

	//Destroys the list
	charList.DestroyList();

	return isPalindrome;
}
