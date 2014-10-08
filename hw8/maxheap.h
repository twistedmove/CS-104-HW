#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
using namespace std;

template<class T, class Comparator>
class MaxHeap
{
	public:
	/* Constructor that builds a d-ary Max Heap using the given
    comparator to compare elements and decide which one is
    larger. This should work for any d >= 2*/
	MaxHeap (int theD, Comparator comp);

    ~MaxHeap();

    /* adds the item to the heap */
    void add (const T& item);

    /* returns the element with maximum priority.
    Throws an exception if the heap is empty. */
    const T& peek () const;
         
    /* removes the element with maximum priority. */
    void remove ();

    void heapify(int index);

    /* returns true if there are no elements on the heap. */
    bool isEmpty ();

    //returns the size of the heap
    int heapSize() const;

    //prints the heap in tree format
    void print();

	private:
	vector<T>* storage;
	Comparator comp;
	int d;
	int size;
};

#include "maxheap.cpp"


#endif