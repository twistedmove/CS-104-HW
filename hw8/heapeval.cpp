#include "maxheap.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

struct intGreater
{
	bool operator()(const int lhs, const int rhs)
	{
		return lhs > rhs;
	}
};

double measureInsertTime(MaxHeap<int, intGreater>& test, int* sequence)
{
	auto start = chrono::high_resolution_clock::now();
	for(int i = 0; i < 10000; i++)
	{
		test.add(sequence[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
	return time_span.count();
}

double measureRemoveTime(MaxHeap<int, intGreater>& test)
{
	auto start = chrono::high_resolution_clock::now();
	for(int i = 0; i < 10000; i++)
	{
		test.remove();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
	return time_span.count();
}


int main()
{
	intGreater bigger;
	srand(time(0));
	//max-heaps
	MaxHeap<int, intGreater> test2(2, bigger);
	MaxHeap<int, intGreater> test3(3, bigger);
	MaxHeap<int, intGreater> test4(4, bigger);
	MaxHeap<int, intGreater> test10(10, bigger);
	MaxHeap<int, intGreater> test20(20, bigger);
	MaxHeap<int, intGreater> test50(50, bigger);
	MaxHeap<int, intGreater> test100(100, bigger);

	ofstream timeWriter("heaptimes.txt");
	timeWriter << "Problem 5: Evaluating d-ary heaps for different d" << endl;
	timeWriter << endl;

	for(int i = 0; i < 10; i++)
	{
		int sequence1[10000];
		for(int j = 0; j < 10000; j++)
		{
			sequence1[j] = rand() % 10000 + 1;
		}

		timeWriter << "Sequence: " << i << endl;
		timeWriter << endl;

		timeWriter << "Insert times:" << endl;

		timeWriter << "D = 2: ";
		double insertTime = measureInsertTime(test2, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 3: ";
		insertTime = measureInsertTime(test3, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 4: ";
		insertTime = measureInsertTime(test4, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 10: ";
		insertTime = measureInsertTime(test10, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 20: ";
		insertTime = measureInsertTime(test20, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 50: ";
		insertTime = measureInsertTime(test50, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << "D = 100: ";
		insertTime = measureInsertTime(test100, sequence1);
		timeWriter << insertTime << endl;

		timeWriter << endl;

		timeWriter << "Remove times:" << endl;

		timeWriter << "D = 2: ";
		double removeTime = measureRemoveTime(test2);
		timeWriter << removeTime << endl;

		timeWriter << "D = 3: ";
		removeTime = measureRemoveTime(test3);
		timeWriter << removeTime << endl;

		timeWriter << "D = 4: ";
		removeTime = measureRemoveTime(test4);
		timeWriter << removeTime << endl;
	
		timeWriter << "D = 10: ";
		removeTime = measureRemoveTime(test10);
		timeWriter << removeTime << endl;

		timeWriter << "D = 20: ";
		removeTime = measureRemoveTime(test20);
		timeWriter << removeTime << endl;

		timeWriter << "D = 50: ";
		removeTime = measureRemoveTime(test50);
		timeWriter << removeTime << endl;

		timeWriter << "D = 100: ";
		removeTime = measureRemoveTime(test100);
		timeWriter << removeTime << endl;

		timeWriter << endl;
	}

	timeWriter.close();
	return 0;
}