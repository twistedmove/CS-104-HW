#include "rbbst.h"
#include <iostream>

using namespace std;

int main()
{
	RedBlackTree<int, string>* test = new RedBlackTree<int, string>();
	cout << "test 1" << endl;
	test->add(10, "kabir");
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 2" << endl;
	test->add(20, "apple");
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 3" << endl;
	test->add(30, "daniel");
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 4" << endl;
	test->add(15, "kody");
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 5" << endl;
	test->add(25, "satsuki");
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 6" << endl;
	test->add(12, "andrew");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 7" << endl;
	test->add(5, "dinesh");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 8" << endl;
	test->add(3, "sasha");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 9" << endl;
	test->add(8, "berk");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 10" << endl;
	test->add(27, "elya");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 11" << endl;
	test->add(40, "quincy");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();	
	cout << endl;

	cout << "test 12" << endl;
	test->add(50, "vance");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 13" << endl;
	test->add(45, "curtis");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();
	cout << endl;

	cout << "test 14" << endl;
	test->add(9, "joey");
	cout << "finished adding" << endl;
	for(RedBlackTree<int, string>::iterator it = test->begin(); it != test->end(); ++it)
	{
		cout << (*it).first << "," << (*it).second << ", color: " << (&it) << endl;
	}
	test->print();

	delete test;
	return 0;
}