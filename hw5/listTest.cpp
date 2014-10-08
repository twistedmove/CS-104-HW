#include "linkedlistImpl.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList<int>* test = new LinkedList<int>();
    cout << "The first LinkedList is " << test->size() << " elements long" << endl;
    cout << "Next line should throw an exception: " << endl;
	test->set(0, 10);
    cout << "Next lines should work" << endl;
    test->insert(0, 42);
    test->insert(1, 8);
    test->insert(2, 15);
    test->insert(0, 12);
    test->insert(4,25);
    test->set(2, 41);
    test->remove(4);
    test->set(3, 16);
    test->insert(1,5);
    cout << "All elements in the first LinkedList: " << endl;
    test->print();
    cout << "The LinkedList is now " << test->size() << " elements long" << endl;
    LinkedList<int>* test2 = new LinkedList<int>(*test);
    cout << "All elements in the second LinkedList, should be same: " << endl;
    test2->print();
    LinkedList<int>* test3 = test;
    cout << "All elements in the third LinkedList, should be same: " << endl;
    test3->print();
}