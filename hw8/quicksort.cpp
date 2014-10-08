#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//void backQuicksort(int* myList, int start, int end);

int partition(int* myList, int start, int end, int p)
{
	int pivot = myList[p];
	swap(myList[p], myList[end]);

	int left = start;
	int right = end;

	while(left < right)
	{
		while(myList[left] <= pivot && left < right)
		{
			left++;
		}
		while(myList[right] >= pivot && right > left)
		{
			right--;
		}
		if(left < right)
		{
			swap(myList[left], myList[right]);
		}
	}
	swap(myList[left], myList[end]);
	return left;
}

void randQuicksort(int* myList, int start, int end)
{
	if(start >= end)
	{
		return;
	}
	
	int p = rand() % end;
	int index = partition(myList, start, end, p);
	randQuicksort(myList, start, index - 1);
	randQuicksort(myList, index + 1, end);
	
}

int main()
{
	srand(time(0));
	int test[10];
	for(int i = 0; i < 10; i++)
	{
		test[i] = rand() % 50;
	}
	cout << "before sorting:" << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << test[i] << endl;
	}
	randQuicksort(test, 0, 10);

	cout << "after sorting: " << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << test[i] << endl;
	}
	
	return 0;
}