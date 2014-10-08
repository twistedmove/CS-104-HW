#include <stdexcept>
#include <iostream>
#include "linkedlistImpl.h"
#include "map.h"
using namespace std;

template <class keyType, class valueType>
Map<keyType, valueType>::Map()
{
    internalStorage = new LinkedList<Pair<keyType, valueType> >();
}

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
    return (internalStorage->size());
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType& newKey, const valueType& newValue)
{
    try
    {
        if(find(newKey) != -1)
        {
            throw invalid_argument("This key already has an association");
        }
        Pair<keyType, valueType>* newPair = new Pair<keyType, valueType>(newKey, newValue);
        internalStorage->insert(0,*newPair);
        //delete [] newPair;
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType& given)
{
    try
    {
        int index = find(given);
        if(index == -1)
        {
            throw invalid_argument("This key has no association");
        }
        internalStorage->remove(index);
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}

template <class keyType, class valueType>
valueType& Map<keyType, valueType>::get (const keyType& given) const
{
    valueType* theValue = new valueType;
    try
    {
        int index = find(given);
        if(index == -1)
        {
            throw invalid_argument("This key has no association");
        }
        Pair<keyType, valueType> temp = internalStorage->get(index);
        *theValue = temp.value;
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    return *theValue;
}

template <class keyType, class valueType>
int Map<keyType, valueType>::find (const keyType& given) const
{
    int index = -1;
    for(int i = 0; i < (internalStorage->size()); i++)
    {
        Pair<keyType, valueType> temp = internalStorage->get(i);
        if(temp.key == given)
        {
            index = i;
        }
    }
    return index;
}

template <class keyType, class valueType>
void Map<keyType, valueType>::print() const
{
    for(int i = 0; i < (internalStorage->size()); i++)
    {
        Pair<keyType, valueType> temp = internalStorage->get(i);
        cout << "Key: " << temp.key << ", " << "Value: " << temp.value << endl;
    }
}