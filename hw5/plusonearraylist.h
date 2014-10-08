#ifndef PLUSONEARRAYLIST_H
#define PLUSONEARRAYLIST_H
#include "arraylist.h"
#include <iostream>
using namespace std;
template <class T>
class PlusOneArrayList : public ArrayList<T>
{
	public:
	PlusOneArrayList() : ArrayList<T>()
	{
		
	}

	PlusOneArrayList(int arrayCapacity) : ArrayList<T>(arrayCapacity)
	{
		
	}

	~PlusOneArrayList()
	{
		delete[] this->data;
	}

	void resize()
	{
		PlusOneArrayList<T>* newArray = new PlusOneArrayList<T>((this->capacity)+1);
		for(int i = 0; i < this->currSize; i++)
		{
			newArray->data[i] = this->data[i];
		}
		newArray->currSize = this->currSize;
		//delete[] this;
		*this = *newArray;
	}

};

#endif
