#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	List<int>* test = new List<int>();
    cout << "The list is " << test->size() << " elements long" << endl;
	test->set(0, 10);
    test->insert(0, 42);
    test->insert(1, 8);
    test->insert(2, 15);
    test->insert(0, 12);
    test->insert(4,25);
    test->set(2, 41);
    test->remove(4);
    test->set(3, 16);
    test->insert(1,5);
    test->print();
    cout << "The list is " << test->size() << " elements long" << endl;
}