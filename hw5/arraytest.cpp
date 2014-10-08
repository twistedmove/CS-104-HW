#include <iostream>
#include "arraylist.h"
#include "doublingarraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
using namespace std;

int main()
{
	/*cout << "Testing the DoublingArrayList!" << endl;
	ArrayList<int>* test = new ArrayList<int>();
	cout << "array is size: " << test->size() << endl;
	cout << "array has capacity: " << test->arrayCapacity() << endl;
	test->insert(0, 10);
	cout << "array is size: " << test->size() << endl;
	cout << "item at position 0 is: " << test->get(0) << endl;
	test->get(0) = 5; //Should set position 0 to 5
	cout << "item at position 0 is: " << test->get(0) << endl;
	test->insert(1, 10);
	cout << "array is size: " << test->size() << endl;
	cout << "item at position 1 is: " << test->get(1) << endl;
	test->remove(0);
	cout << "Item at position 0 removed" << endl;
	cout << "array is size: " << test->size() << endl;
	cout << "item at position 0 is: " << test->get(0) << endl;
	test->set(0, 42);
	cout << "item at position 0 set to 42" << endl;
	cout << "item at position 0 is: " << test->get(0) << endl;
	test->insert(0, 15);
	test->insert(1, 29);
	test->insert(0, 10);
	cout << "3 items inserted, printing out list" << endl;
	test->print();
	cout << "resizing list" << endl;
	test->resize();
	cout << "array has capacity: " << test->arrayCapacity() << endl;
	cout << "printing out list to make sure it copied" << endl;
	test->print();
	cout << "removing item at position 2 (29)" << endl;
	test->remove(2);
	cout << "printing out list" << endl;
	test->print();
	//delete test;
	cout << endl;*/

	cout << "Testing the ArrayList!" << endl;
	cout << "Initializing the array!" << endl;
	ArrayList<int>* test2 = new ArrayList<int>();
	cout << "array is size: " << test2->size() << endl;
	cout << "array has capacity: " << test2->arrayCapacity() << endl;
	cout << "Inserting 10 at position 0" << endl;
	test2->insert(0, 10);
	cout << "array is size: " << test2->size() << endl;
	cout << "item at position 0 is: " << test2->get(0) << endl;
	cout << "Setting position 0 to 5" << endl;
	test2->get(0) = 5; //Should set position 0 to 5
	cout << "item at position 0 is: " << test2->get(0) << endl;
	cout << "Inserting 10 at position 1" << endl;
	test2->insert(1, 10);
	cout << "array is size: " << test2->size() << endl;
	cout << "item at position 1 is: " << test2->get(1) << endl;
	cout << "Removing item at position 0 (5)" << endl;
	test2->remove(0);
	cout << "array is size: " << test2->size() << endl;
	cout << "item at position 0 is: " << test2->get(0) << endl;
	test2->set(0, 42);
	cout << "item at position 0 set to 42" << endl;
	cout << "item at position 0 is: " << test2->get(0) << endl;
	cout << "printing list" << endl;
	test2->print();
	cout << "inserting 15 at position 0" << endl;
	test2->insert(0, 15);
	cout << "printing list" << endl;
	test2->print();
	cout << "inserting 29 at position 1" << endl;
	test2->insert(1, 29);
	cout << "printing list" << endl;
	test2->print();
	cout << "inserting 17 at position 0" << endl;
	test2->insert(0, 17);
	cout << "printing list" << endl;
	test2->print();
	cout << "resizing list" << endl;
	test2->resize();
	cout << "array has capacity: " << test2->arrayCapacity() << endl;
	cout << "printing out list to make sure it copied" << endl;
	test2->print();
	cout << "removing item at position 2 (29)" << endl;
	test2->remove(2);
	cout << "printing out list" << endl;
	test2->print();
	//delete test2;
	//cout << endl;

	/*cout << "Testing the PlusTenArrayList!" << endl;
	ArrayList<int>* test3 = new PlusTenArrayList<int>();
	cout << "array is size: " << test3->size() << endl;
	cout << "array has capacity: " << test3->arrayCapacity() << endl;
	test3->insert(0, 10);
	cout << "array is size: " << test3->size() << endl;
	cout << "item at position 0 is: " << test3->get(0) << endl;
	test3->get(0) = 5; //Should set position 0 to 5
	cout << "item at position 0 is: " << test3->get(0) << endl;
	test3->insert(1, 10);
	cout << "array is size: " << test3->size() << endl;
	cout << "item at position 1 is: " << test3->get(1) << endl;
	test3->remove(0);
	cout << "Item at position 0 removed" << endl;
	cout << "array is size: " << test3->size() << endl;
	cout << "item at position 0 is: " << test3->get(0) << endl;
	test3->set(0, 42);
	cout << "item at position 0 set to 42" << endl;
	cout << "item at position 0 is: " << test3->get(0) << endl;
	test3->insert(0, 15);
	test3->insert(1, 29);
	test3->insert(0, 10);
	cout << "3 items inserted, printing out list" << endl;
	test3->print();
	cout << "resizing list" << endl;
	test3->resize();
	cout << "array has capacity: " << test3->arrayCapacity() << endl;
	cout << "printing out list to make sure it copied" << endl;
	test3->print();
	cout << "removing item at position 2 (29)" << endl;
	test3->remove(2);
	cout << "printing out list" << endl;
	test3->print();
	//delete test3;*/
}