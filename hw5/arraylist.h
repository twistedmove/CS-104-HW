#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "ilist.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class ArrayList : public IList<T>
{
	public:
	ArrayList() : capacity(1000), currSize(0)
	{
		data = new T[capacity]; 
	}

	ArrayList(int arrayCapacity) : capacity(arrayCapacity), currSize(0)
	{
		data = new T[capacity];
	}

	virtual ~ ArrayList()
	{
		delete[] data;
	}

	int size() const
	{
		return currSize;
	}

	int arrayCapacity() const
	{
		return capacity;
	}

	void insert(int position, const T& val)
	{
		try
		{
			if(position < 0 || position > currSize)
			{
				throw invalid_argument("This is not a valid position to insert something!");
			}	
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
		}
		if(currSize == capacity)
		{
			resize();
		}
		if(position == currSize)
		{
			data[currSize] = val;
			currSize++;
		}
		else
		{
			for(int i = currSize; i > position; i--)
			{
				data[i] = data[i-1];
			}
			data[position] = val;
			currSize++;
		}
	}

	void remove(int position)
	{
		try
		{
			if(position < 0 || position > currSize-1)
			{
				throw invalid_argument("This is not a valid position to remove something!");
			}	
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
		}

		for(int i = position; i < currSize; i++)
		{
			data[i] = data[i+1];
		}
		currSize--;
	}

	void set(int position, const T& val)
	{
		try
		{
			if(position < 0 || position > currSize-1)
			{
				throw invalid_argument("This is not a valid position to set something!");
			}	
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
		}

		data[position] = val;
	}

	T& get (int position)
	{
		try
		{
			if(position < 0 || position > currSize-1)
			{
				throw invalid_argument("This is not a valid position to get something!");
			}	
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
		}

		return data[position];
	}

	const T& get (int position) const
	{
		try
		{
			if(position < 0 || position > currSize-1)
			{
				throw invalid_argument("This is not a valid position to get something!");
			}	
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
		}

		return data[position];
	}

	void resize()
	{
		ArrayList<T>* newArray = new ArrayList<T>((this->capacity)*2);
		for(int i = 0; i < this->currSize; i++)
		{
			newArray->data[i] = this->data[i];
		}
		newArray->currSize = this->currSize;
		*this = *newArray;
		//delete newArray;
	}

	void print() const
	{
		for(int i = 0; i < currSize; i++)
		{
			cout << data[i] << endl;
		}
	}

	protected:
	int capacity;
	int currSize;
	T* data;
};


#endif