#include <iostream>
#include <ctime>
#include "maxheap.h"

using namespace std;

struct intGreater
{
	bool operator()(const int lhs, const int rhs)
	{
		return lhs > rhs;
	}
};

int main()
{
	intGreater bigger;
	MaxHeap<int, intGreater> test(10, bigger);
	srand(time(0));
	for(int i = 0; i < 4; i++)
	{
		int temp = rand() % 50 + 1;
		test.add(temp);
	}
	cout << "intitial tree:" << endl;
	test.print();
	cout << "peek: " << test.peek() << endl;
	test.remove();
	cout << "removed an item" << endl;
	test.print();
	test.remove();
	cout << "removed an item" << endl;
	test.print();
	test.remove();
	cout << "removed an item" << endl;
	test.print();
	test.remove();
	cout << "removed an item" << endl;
	test.print();

	return 0;
}