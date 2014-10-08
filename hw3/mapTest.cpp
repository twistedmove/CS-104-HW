#include <iostream>
#include "map.h"
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    Map<char, int>* test = new Map<char, int>();
    cout << test->size() << endl;
    test->add('a', 42);
    cout << "the map is " << test->size() << " elements large" << endl;
    cout << "a is at " << test->find('a') << endl;
    cout << "a is associated with " << test->get('a') << endl;
    test->add('b', 30);
    cout << "the map is " << test->size() << " elements large" << endl;
    cout << "b is at " << test->find('b') << endl;
    cout << "a is at " << test->find('a') << endl;
    cout << "b is associated with " << test->get('b') << endl;

    Map<string, string>* test1 = new Map<string, string>();
    cout << "the map is " << test1->size() << " elements large" << endl;
    test1->add("tal", "legacy");
    cout << "the map is " << test1->size() << " elements large" << endl;
    cout << "tals house name is " << test1->get("tal") << endl;
    test1->print();
}