#ifndef map_h
#define map_h
#include "linkedlistImpl.h"
using namespace std;

template <class keyType, class valueType>
struct Pair
{
    Pair()
    {
      
    }
    
    Pair(keyType myKey, valueType myValue) : key(myKey), value(myValue)
    {
    }
    
    ~Pair()
    {
        //delete key;
        //delete value;
    }
    
    keyType key;
    valueType value;
};

template <class keyType, class valueType>
class Map
{
    public:
    
    Map ();  // constructor for a new empty map
    
    ~Map (); // destructor
    
    int size () const; // returns the number of key-value pairs
    
    /* Adds a new association between the given key and the given value.
     If the key already has an association, it throws an exception.*/
    void add (const keyType & newKey, const valueType & newValue);
    
    /* Removes the association for the given key.
     If the key has no association, it throws an exception. */
    void remove (const keyType & given);
    
    /* Returns the value associated with the given key.
     If the key has no association, it throws an exception. */
    valueType& get (const keyType & given) const;
    
    /* Returns the index in the list that the given key sits at.
     Returns -1 if the key doesn't exist.*/
    int find (const keyType& given) const;
    
    void print() const; //Prints out all key-value pairs in the map

    private:
    LinkedList<Pair<keyType, valueType> >* internalStorage;
};

#endif
