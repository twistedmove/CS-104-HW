#include "bst.h"
#include <iostream>

using namespace std;

int main()
{

	BinarySearchTree<int, string>* test = new BinarySearchTree<int, string>();
	cout << "test 1" << endl;
	try
	{
		test->lookup(5);	
	}
	catch(KeyNotFoundException& o)
	{
		cout << "Did not find the key!" << endl;
	}
	cout << "test 2" << endl;
	test->add(5, "kabir");
	cout << test->lookup(5) << endl;
	cout << "test 3" << endl;
	test->print();
	cout << "test 4" << endl;
	test->add(4, "albert");
	test->print();
	cout << "test 5" << endl;
	test->add(9, "daniel");
	//test->print();
	cout << test->lookup(4) << endl;
	cout << "test 6" << endl;
	try
	{
		test->lookup(2);	
	}
	catch(KeyNotFoundException& o)
	{
		cout << "Did not find the key!" << endl;
	}
	cout << "test 7" << endl;
	test->add(7, "apple");
	test->print();
	cout << "test 8" << endl;
	for(BinarySearchTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << endl;
	}

	/*BinarySearchTree<int, string>::iterator it = test->begin();
	cout << (*it).first << "," << (*it).second << endl;
	++it;
	cout << (*it).first << "," << (*it).second << endl;*/


	//testing nodes
	/*Node<int, string>* test = new Node<int, string>(5, "kabir");
	Node<int, string>* test2 = new Node<int, string>(5, "kabir");
	bool isEqual = (test == test2);
	cout << isEqual << endl;
	pair<int, string> temp = test->getItem();
	cout << temp.first << "," << temp.second << endl;
	cout << test2->getKey() << "," << test2->getValue() << endl;
	test->setParent(test2);
	cout << test->getParent() << endl;
	delete test;
	delete test2;*/
	return 0;
}