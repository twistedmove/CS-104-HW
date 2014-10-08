#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<int>* test = new Stack<int>;
	cout << "New stack, should be empty." << endl;
	cout << "Stack is size: " << test->size() << endl;
	cout << "Is empty? Should output 1: " << test->isEmpty() << endl;
	cout << "Pushing 10 onto the stack." << endl;
	test->push(10);
	cout << "Is empty? Should output 0: " << test->isEmpty() << endl;
	cout << "Element on top is: " << test->top() << endl;
	test->push(5);
	test->push(42);
	cout << "Added 2 more elements, printint out stack" << endl;
	test->print();
	cout << "Element on top is: " << test->top() << endl;
	cout << "Popping the top element" << endl;
	test->pop();
	cout << "Element on top is: " << test->top() << endl;
	cout << "Is empty? Should output 0: " << test->isEmpty() << endl;
}