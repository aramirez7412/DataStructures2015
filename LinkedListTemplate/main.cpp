#include "LinkedList.h"
#include "Node.h"

bool isPalindrome(string someString);

int main()
{
	const int ARRAY_SIZE = 10;

	string stringArray[ARRAY_SIZE] = {"Dad",
							  	      "radar",
							  	      "Otto",
							  	      "mom",
							  	      "tigers",
							  	      "A man, a plan, a canal, Panama",
							  	      "Isn\'t this class cool?",
							  	      "Was it a car or a cat I saw?",
							  	      "Sit on a potato pan, Otis",
							  	      "Saddleback is a great place to learn"};

	string      tempString;
	int         length;
	int 	    index;





//	if(isPalindrome("M o  m"))
//	{
//		cout << "Is a palindrome" << endl;
//	}
//	else
//	{
//		cout << "Not a palindrome" << endl;
//	}
//
	cout << left;
	cout << setw(7) << "Word" << "Result" << endl;
	cout << setw(7) << "----" << "------" << endl;

	for(int index = 0; index < ARRAY_SIZE; index++)
	{
		cout << setw(7) << stringArray[index];

	   isPalindrome(stringArray[index])?cout << "Is a palindrome":cout << "Not a palindrome";
	   cout << endl;
	}



}
