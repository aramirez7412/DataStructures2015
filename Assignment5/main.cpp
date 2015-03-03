#include "Header.h"
#include "binaryTree.h"
#include <iomanip>

int main()
{
	binaryTree<char> myTree;

	OutputHeader(cout, "Anthony Ramirez", "CS1D", "Tuesday/Thursday",
					5, "Binary Tree",'A');

	//Testing the insert methods
	myTree.insert('c');
	myTree.insert('d');
	myTree.insert('e');
	myTree.insert('a');
	myTree.insert('b');


	cout << "*****************************************************************\n";
	cout << "* Testing search method: searching for y                        *\n";
	cout << "*****************************************************************\n";
	if(myTree.search('y'))
	{
		cout << "Node was Found";
	}
	else
	{
		cout << "Node was Not found" << endl << endl;
	}

	cout << "*****************************************************************\n";
	cout << "* Testing search method: searching for a                        *\n";
	cout << "*****************************************************************\n";
	if(myTree.search('a'))
	{
		cout << "Node was Found";
	}
	else
	{
		cout << "Node was Not found" << endl << endl;
	}
	cout << endl;
	cout << endl;
	cout << "*****************************************************************\n";
	cout << "* Testing height method                                         *\n";
	cout << "*****************************************************************\n";
	cout << "Height count: " << myTree.findHeight() << endl << endl;

	cout << "*****************************************************************\n";
	cout << "* Testing inorder traversal                                     *\n";
	cout << "*****************************************************************\n";

 	myTree.inorderTraversal();
	return 0;
}
