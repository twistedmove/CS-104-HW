using namespace std;

template<class T, class Comparator>
MaxHeap<T, Comparator>::MaxHeap(int theD, Comparator myComp)
{
	if(theD < 2)
	{
		throw out_of_range("d is too small");
	}
	d = theD;
	storage = new vector<T>();
	comp = myComp;
	size = 0;
}

template<class T, class Comparator>
MaxHeap<T, Comparator>::~MaxHeap()
{
	delete storage;
}

template<class T, class Comparator>
void MaxHeap<T, Comparator>::add(const T& item)
{
	storage->push_back(item);
	++size;
	int index = size-1;
	int parent = index/d;

	while((parent >= 0) && (comp(storage->at(index), storage->at(parent)) == 1))
	{
		iter_swap(storage->begin() + index, storage->begin() + parent);
		index = parent;
		parent = index/d;
	}
}

template<class T, class Comparator>
const T& MaxHeap<T, Comparator>::peek() const
{
	if(size == 0)
	{
		throw out_of_range("can't peek when there is nothing in the heap!");
	}
	return storage->front();
}

template<class T, class Comparator>
void MaxHeap<T, Comparator>::remove()
{
	if(isEmpty())
	{
		throw out_of_range("can't remove when there is nothing in the heap!");
	}
	storage->at(0) = storage->at(size-1);
	storage->pop_back();
	--size;
	heapify(0);
}

template<class T, class Comparator>
void MaxHeap<T, Comparator>::heapify(int index)
{
	int level = (log(size)/log(d));
	if(size < d && size > 1)
	{
		level = 1;
	}
	int numInLevel = pow(d, level);
	int totalPossible = 0;
	for(int i = 0; i <= level; i++)
	{
		totalPossible += pow(d, i);
	}
	if(index >= (totalPossible - numInLevel))
	{
		return;
	}
	int greatestChild = d*index + 1;
	int currChild = d*index + 1;
	//find the greatest child
	if(currChild <= (size - 1))
	{
		while(currChild <= (d*index + d))
		{
			if(currChild <= (size - 1))
			{
				if(comp(storage->at(currChild), storage->at(greatestChild)) == 1)
				{
					greatestChild = currChild;
				}
			}
			++currChild;
		}
		if(greatestChild <= (size - 1))
		{
			if(comp(storage->at(greatestChild), storage->at(index)) == 1)
			{
				iter_swap(storage->begin() + index, storage->begin() + greatestChild);
				heapify(greatestChild);
			}
		}
	}
}

template<class T, class Comparator>
bool MaxHeap<T, Comparator>::isEmpty()
{
	return (size == 0);
}

template<class T, class Comparator>
int MaxHeap<T, Comparator>::heapSize() const
{
	return size;
}

template<class T, class Comparator>
void MaxHeap<T,Comparator>::print()
{
	int levels = (log(size)/log(d));
	if(size < d && size > 1)
	{
		levels = 1;
	}
	int level = 0;
	typename vector<T>::iterator it = storage->begin();
	while(level <= levels)
	{
		if(it == storage->end())
		{
			break;
		}
		else
		{
			int numInLevel = pow(d, level);
			for(int i = 0; i < numInLevel; i++)
			{
				if(it == storage->end())
				{
					break;
				}
				else
				{
					if((i % d) == 0 && i != 0)
					{
						cout << "| ";
					}
					cout << *it << " ";
					++it;
				}
			}
		}
		cout << endl;
		++level;
	}
}