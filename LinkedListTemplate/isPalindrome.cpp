#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


bool isPalindrome(string someString)
{
	int length;
	bool isPalindrome;
	List<char> word;
	int i;
	int j;




	length = someString.length();

	if(length > 2)
	{
		for(int index = 0; index < length; index++)
		{
			if(!ispunct(someString[index]) || !isspace(someString[index]))
			{
				word.Enqueue(toupper(someString[index]));
			}
		}

		cout << word.OutputList() << endl;

		cout << "Test stub " << endl;
		cin.ignore(100,'\n');
		i = 0;
		j = length - 1;

		isPalindrome = true;

		cout << "Test stub #2 " << endl;
				cin.ignore(100,'\n');
		cout << word[i] << "---" << word[j] << endl;

		cout << "Test stub #3"
				"" << endl;
				cin.ignore(100,'\n');

		int count = length/2;

		while(i <= count && isPalindrome)
		{

			if(word[i] != word[j])
			{
				isPalindrome = false;
			}

			cout << "J: " << j;
				i++;
				j--;
		}

	}
//	else
//	{
//		cout << endl << "There is no word that can be a palindrome here";
//	}
//
	return isPalindrome;
}
