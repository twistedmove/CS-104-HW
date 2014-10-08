#ifndef PLUSTENARRAYLIST_H
#define PLUSTENARRAYLIST_H
#include "arraylist.h"
#include <iostream>
using namespace std;
template <class T>
class PlusTenArrayList : public ArrayList<T>
{
	public:
	PlusTenArrayList() : ArrayList<T>()
	{
		
	}

	PlusTenArrayList(int arrayCapacity) : ArrayList<T>(arrayCapacity)
	{
		
	}

	~PlusTenArrayList()
	{
		delete[] this->data;
	}

	void resize()
	{
		PlusTenArrayList<T>* newArray = new PlusTenArrayList<T>((this->capacity)+10);
		for(int i = 0; i < this->currSize; i++)
		{
			newArray->data[i] = this->data[i];
		}
		newArray->currSize = this->currSize;
		*this = *newArray;
	}

};

#endif
