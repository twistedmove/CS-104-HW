#include "arraylist.h"
#include <iostream>
#include <stdexcept>
template <class T>
class Stack : private ArrayList<T>
{
    public:
    // add appropriate constructors and destructors
    Stack() : ArrayList<T>()
    {

    }

    Stack(int stackCapacity) : ArrayList<T>(stackCapacity)
    {

    }

    ~Stack()
    {
        delete[] this->data;
    }

    /* returns whether the stack contains any elements */
    bool isEmpty() const
    {
        bool empty = true;
        if(size() > 0)
        {
            empty = false;
        }
        return empty;
    }
    
    /* adds a value to the top of the stack */
    void push(const T& val)
    {
        int stackSize = size();
        this->ArrayList<T>::insert(stackSize, val);
    }

    /* deletes the top value from the stack */
    void pop()
    {
        try
        {
            if(size() == 0)
            {
                throw invalid_argument("Can't pop from an empty stack!");
            }
        }
        catch(invalid_argument& o)
        {
            cout << o.what() << endl;
        }
        this->ArrayList<T>::remove(size()-1);
    }

    /* returns the top value on the stack */
    T const & top() const
    {
        return this->ArrayList<T>::get(this->size()-1);
    }

    void print() const
    {
        this->ArrayList<T>::print();
    }

    int size() const
    {
        return this->ArrayList<T>::size();
    }

    
    
};