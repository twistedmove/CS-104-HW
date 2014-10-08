#ifndef DOUBLINGARRAYLIST_H
#define DOUBLINGARRAYLIST_H
#include "arraylist.h"
#include <iostream>
using namespace std;
template <class T>
class DoublingArrayList : public ArrayList<T>
{
	public:
	DoublingArrayList() : ArrayList<T>()
	{
		
	}

	DoublingArrayList(int arrayCapacity) : ArrayList<T>(arrayCapacity)
	{
		
	}

	~DoublingArrayList()
	{
		delete[] this->data;
	}

	void resize()
	{
		DoublingArrayList<T>* newArray = new DoublingArrayList<T>((this->capacity)*2);
		newArray->currSize = this->currSize;
		for(int i = 0; i < this->currSize; i++)
		{
			newArray->data[i] = this->data[i];
		}
		*this = *newArray;
		//delete newArray;
	}


};

#endif
