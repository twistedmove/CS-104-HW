#ifndef ITEM_H
#define ITEM_H
#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
struct Item
{
    T value;
    Item<T> *prev, *next;
};

template <class T>
class List
{
    public:
    List (); // constructor

    ~List (); // destructor

    int size () const;  // returns the number of elements in the list
    
    /* Inserts val into the list before the given position,
     shifting all later items one position to the right.
     Inserting before 0 (i.e., position = 0) makes it the
     new first element.
     Inserting before size() (i.e., position = size()) makes
     it the new last element.
     Your function should throw an exception if position is
     outside the legal range, which would be 0-size() here. */
    void insert (int position, const T & val);
    
    /* Removes the item from the given position, shifting all
     later items one position to the left.
     Throws an exception if the position given is outside the
     legal range of 0-(size()-1).Also throws an exception if the
     user attempts to remove something at position 0 if the list is
     empty.*/
    void remove (int position);
    
    /* Overwrites the given position with the given value.
     Does not affect any other positions.
     Throws an exception if the position given is outside the
     legal range of 0-(size()-1). Also throws an exception if the
     user attempts to set something at position 0 if the list is
     empty.*/
    void set (int position, const T & val);
    
    /* Returns the item at the given position.
     Throws an exception if the position given is outside the
     legal range of 0-(size()-1). */
    T& get (int position) const;
    
    /* Prints out all elements in the list. */
    void print () const;
    
    private:
    Item<T> *head;
      /* You may add further private data fields or helper methods if 
         you choose. You should not alter the public signature. */
};

template <class T>
List<T>::List()
{
    head = NULL;
}

template <class T>
List<T>::~List()
{
    for(int i = 0; i < size(); i++)
    {
        Item<T>* temp1 = new Item<T>;
        temp1 = head->next;
        delete [] head;
        head = temp1;
        head->prev= NULL;
    }
}

template <class T>
int List<T>::size()const
{
    int counter = 0;
    Item<T>* temp = head;
    while(temp)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

template <class T>
void List<T>::insert (int position, const T & val)
{
    try
    {
        if(position < 0 || position > size())
        {
            throw out_of_range("This is not a valid position to insert something");
        }
        if(position == 0 && head == NULL)
        {
            Item<T>* newFirst = new Item<T>;
            newFirst->prev = NULL;
            newFirst->next = NULL;
            newFirst->value = val;
            head = newFirst;
        }
        else if(position == 0 && head != NULL)
        {
            Item<T>* newFirst = new Item<T>;
            newFirst->prev = NULL;
            newFirst->next = head;
            newFirst->value = val;
            head->prev = newFirst;
            head = newFirst;
            
        }
        else if(position == size())
        {
            Item<T>* temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            Item<T>* newLast = new Item<T>;
            temp->next = newLast;
            newLast->next = NULL;
            newLast->value = val;
            newLast->prev = temp;
        }
        else
        {
            Item<T>* temp = head;
            for(int i = 0; i < position-1; i++)
            {
                temp = temp->next;
            }
            Item<T>* newItem = new Item<T>;
            newItem->next = temp->next;
            temp->next->prev = newItem;
            temp->next = newItem;
            newItem->value = val;
            newItem->prev = temp;
        }
    }
    catch (out_of_range& o)
    {
        cout<< o.what() << endl;
    }
}

template <class T>
void List<T>::remove (int position)
{
    try
    {
        if(position < 0 || position > size()-1)
        {
            throw out_of_range("This is not a valid position to remove something");
        }
        else if(position == 0 && size() == 0)
        {
            throw invalid_argument("Can't remove from an empty list");
        }
        Item<T>* temp = head;
        if(position == size()-1)
        {
            for(int i = 0; i < position; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete[] temp;
        }
        else if(position == 0)
        {
            Item<T>* temp1 = new Item<T>;
            temp1 = head->next;
            delete [] head;
            head = temp1;
            head->prev= NULL;
        }
        else
        {
            for(int i = 0; i < position; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete [] temp;
        }
    }
    catch (out_of_range& o)
    {
        cout<< o.what() << endl;
    }
    catch(invalid_argument& o)
    {
        cout<< o.what() << endl;
    }
}

template <class T>
void List<T>::set (int position, const T & val)
{
    try
    {
        if(position < 0 || position > size()-1)
        {
            throw out_of_range("This is not a valid position to set something");
        }
        else if(position == 0 && size() == 0)
        {
            throw invalid_argument("The list is empty, can't set anything");
        }
        Item<T>* temp = head;
        if(position == 0)
        {
            head->value = val;
        }
        else if(position == size()-1)
        {
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->value = val;
        }
        else
        {
            for(int i = 0; i < position; i++)
            {
                temp = temp->next;
            }
            temp->value = val;
        }
    }
    catch (out_of_range& o)
    {
        cout<< o.what() << endl;
    }
    catch (invalid_argument& o)
    {
        cout << o.what() << endl;
    }
}

template <class T>
T& List<T>::get (int position) const
{
    try
    {
        if(position < 0 || position > size()-1)
        {
            throw out_of_range("This is not a valid position to get something");
        }
        
        Item<T>* temp = head;
        if(position == 0)
        {
            return head->value;
        }
        else
        {
            for(int i = 0; i < position; i++)
            {
                temp = temp->next;
            }
        }
        return temp->value;
    }
    catch (out_of_range& o)
    {
        cout<< o.what() << endl;
    }
    return head->value;
}

template <class T>
void List<T>::print()const
{
    Item<T>* temp = head;
    while(temp)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

#endif