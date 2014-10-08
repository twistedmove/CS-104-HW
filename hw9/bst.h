#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/* -----------------------------------------------------
 * Exceptions
 ------------------------------------------------------*/

class KeyNotFoundException : public std::exception
{ // thrown when the user searches for a non-existing key
	public:
   	KeyNotFoundException() throw() {}
	~KeyNotFoundException() throw() {}
};

/* -----------------------------------------------------
 * Regular Binary Tree Nodes
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class Node 
{
public:
	Node(const KeyType& k, const ValueType& v) //create a root node
	{
		_item.first = k;
		_item.second = v;
		_parent = _left = _right = NULL;
	}

	Node(const KeyType& k, const ValueType& v, Node<KeyType, ValueType> *p)  // the default is to create new nodes as leaves
	{ 
		_item.first = k; 
		_item.second = v; 
		_parent = p; 
		_left = _right = NULL; 
	}

	bool operator==(const Node<KeyType, ValueType>& rhs)
	{
		return _item.first == rhs.getItem().first;
	}

	const std::pair<KeyType, ValueType>& getItem() const
	{ 
		return _item; 
	}

	//	std::pair<KeyType, ValueType> & getItem ()
	//	{ Return; }

	const KeyType& getKey() const
	{ 
		return _item.first; 
	}

	const ValueType& getValue() const
	{ 
		return _item.second; 
	}

	void setValue(const ValueType& v)
	{
		_item.second = v;
	}

    /* the next three functions are virtual because for Red-Black-Trees,
    we'll want to use Red-Black nodes, and for those, the 
    getParent, getLeft, and getRight functions should return 
    Red-Black nodes, not just ordinary nodes.
    That's an advantage of using getters/setters rather than a struct. */

	virtual Node<KeyType, ValueType>* getParent() const
	{ 
		return _parent; 
	}

	virtual Node<KeyType, ValueType>* getLeft() const
	{ 
		return _left; 
	}

	virtual Node<KeyType, ValueType>* getRight() const
	{ 
		return _right; 
	}


	void setParent(Node<KeyType, ValueType>* p)
	{ 
		_parent = p; 
	}

	void setLeft(Node<KeyType, ValueType>* l)
	{ 
		_left = l; 
	}

	void setRight(Node<KeyType, ValueType>* r)
	{ 
		_right = r; 
	}

	virtual ~Node()
	{}

protected:
	std::pair<KeyType, ValueType> _item;
	Node <KeyType, ValueType> *_left, *_right, *_parent;
};

/* -----------------------------------------------------
 * Regular Binary Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class BinarySearchTree 
{
public:
	BinarySearchTree () 
	{ 
		root = NULL; 
	}
	virtual ~BinarySearchTree () 
	{ 
		deleteAll(root); 
	}

	/* you need to implement the lookup function.
    It should throw a KeyNotFoundException if k is not in the tree.
    You are allowed/encouraged to create private helper functions.*/  
	const ValueType& lookup(const KeyType& k) const
	{
		Node<KeyType, ValueType>* temp = lookupHelper(k, root);
		if(temp == NULL)
		{
			throw KeyNotFoundException();
		}
		else
		{
			return temp->getValue();
		}
		return NULL;
	}

	void add(KeyType key, ValueType value)
	{
		if(!root)
		{
			root = new Node<KeyType, ValueType>(key, value);
		}
		else
		{	
			Node<KeyType, ValueType>* temp = root;
			while(temp)
			{
				if(key <= temp->getKey())
				{
					Node<KeyType, ValueType>* temp1 = temp->getLeft();
					if(!temp1)
					{
						temp->setLeft(new Node<KeyType, ValueType>(key, value, temp));
						temp = temp1;
						continue;
					}
					else
					{
						temp = temp1;
						continue;
					}
				}
				else
				{
					Node<KeyType, ValueType>* temp1 = temp->getRight();
					if(!temp1)
					{
						temp->setRight(new Node<KeyType, ValueType>(key, value, temp));
						temp = temp1;
						continue;
					}
					else
					{
						temp = temp1;
						continue;
					}
				}
			}
		}
	}

    /* prints the entire tree structure in a nice format, denoting subtrees in [] brackets.
	This could be helpful if you want to debug your functions. */
	void print() const
	{ 
	     printRoot (root);
	     std::cout << "\n";
	}

	/*-------------------------------------
         * An In-Order Const iterator
	 *-------------------------------------*/
	class iterator 
	{
	public:
	    iterator(Node<KeyType,ValueType>* root) 
	    {
	        curr = root;
	        if(curr)
	        {
				while(curr->getLeft())
				{
		  			curr = curr->getLeft();
				}
	    	}
		}

		const std::pair<KeyType,ValueType>& operator*() const
	    { 
	  	    return curr->getItem(); 
	  	}

	  	const std::pair<KeyType,ValueType>* operator->() const
	    { 
	    	return &(curr->getItem());
	    }

	  	bool operator==(const iterator& rhs) const
	  	{
	    	return curr == rhs.curr; 
	  	}

	  	bool operator!=(const iterator& rhs) const
	  	{
	    	return curr != rhs.curr;
	  	}

	  	iterator& operator++()
	  	{
	  		if(curr->getRight())
	  		{
	  			curr = curr->getRight();
	  			while(curr->getLeft())
	  			{
	  				curr = curr->getLeft();
	  			}
	  			return *this;
	  		}
	  		else
	  		{
	  			Node<KeyType, ValueType>* p = curr->getParent();
	  			while((p != NULL) && (curr == p->getRight()))
	  			{
	  				curr = p;
	  				p = p->getParent();
	  			}
	  			curr = p;
	  			return *this;
	  		}
	  	}  
	  
	protected:
	 	Node<KeyType, ValueType>* curr;
	};

	iterator begin() 
	{ 
		iterator it (root); 
		return it; 
	}
	iterator end()   
	{ 
		iterator it (NULL); 
		return it; 
	}

protected:
	Node<KeyType, ValueType>* root;
	
	void printRoot(Node<KeyType, ValueType>* r) const
	{
    	if(r)
	  	{
	    	std::cout << "[";
	    	printRoot (r->getLeft());
	    	std::cout << " (" << r->getKey() << ", " << r->getValue() << ") ";
    		printRoot (r->getRight());
    		std::cout << "]";
	  	}
	}

	void deleteAll(Node<KeyType, ValueType> *r)
	{
	  	if (r)
	    {
	      	deleteAll (r->getLeft());
	      	deleteAll (r->getRight());
	      	delete r;
	    }
	}

	Node<KeyType, ValueType>* lookupHelper(const KeyType& k, Node<KeyType, ValueType>* r) const
	{
		if(r == NULL || r->getKey() == k)
		{
			return r;
		}
		else if(k < r->getKey())
		{
			return (lookupHelper(k, r->getLeft()));
		}
		else
		{
			return (lookupHelper(k, r->getRight()));
		}
	}
};

#endif