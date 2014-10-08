#ifndef RBBST_H_
#define RBBST_H_

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

enum Color {red, black};

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
	RedBlackNode(KeyType k, ValueType v) : Node<KeyType, ValueType>(k, v)
	{ 
		color = red; 
	}

	RedBlackNode(KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p) : Node<KeyType, ValueType>(k, v, p)
	{ 
		color = red; 
	}

	virtual ~RedBlackNode() {}

	const Color& getColor() const
	{ 
		return color; 
	}

	void setColor(Color c)
	{ 
		color = c; 
	}

    /* The type casting allows us to treat getParent, getLeft, getRight
    as returning RedBlackNode instead of Node */
	virtual RedBlackNode<KeyType, ValueType>* getParent() const
	{ 
		return (RedBlackNode<KeyType,ValueType>*) this->_parent; 
	}

	virtual RedBlackNode<KeyType, ValueType>* getLeft() const
	{ 
		return (RedBlackNode<KeyType,ValueType>*) this->_left; 
	}

	virtual RedBlackNode<KeyType, ValueType>* getRight() const
	{ 
		return (RedBlackNode<KeyType,ValueType>*) this->_right; 
	}

protected:
	Color color;

};

/* -----------------------------------------------------
 * RedBlack Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:

	RedBlackTree() : BinarySearchTree<KeyType, ValueType>()
	{
		root = NULL;
	}

	virtual ~RedBlackTree()
	{
		deleteAll(root); 
	}

	const ValueType& lookup(const KeyType& k) const
	{
		RedBlackNode<KeyType, ValueType>* temp = lookupHelper(k, root);
		if(temp == NULL)
		{
			throw KeyNotFoundException();
		}
		else
		{
			return temp->getValue();
		}
		return (ValueType)NULL;
	}

	/*It should add the (key, value) pair to the tree, 
     making sure that it remains a valid Red-Black Tree.
     If the key is already in the tree (with a possibly different associated value),
     then it should overwrite the value with the new one.*/
  	virtual void add (KeyType key, ValueType value)
  	{
  		//case 1: there is no root, new root automatically becomes black
  		if(!root)
  		{
  			root = new RedBlackNode<KeyType, ValueType>(key, value);
  			fixTree(root);
  		}
  		else
  		{
  			//first insert in the normal way
  			RedBlackNode<KeyType, ValueType>* temp = root;
  			while(1)
  			{
  				if(!temp)
  				{
  					break;
  				}
  				if(key == temp->getKey()) //if same as another key in the tree just replace the value
  				{
  					temp->setValue(value);
  					break;
  				}
  				else if(key < temp->getKey())
  				{
  					if(!(temp->getLeft())) //if left child doesn't exist slot it in
  					{
  						temp->setLeft(new RedBlackNode<KeyType, ValueType>(key, value, temp));
  						temp = temp->getLeft();
  						fixTree(temp);
  						break;
  					}
  					else
  					{
  						temp = temp->getLeft();
  					}
  				}
  				else
  				{
  					if(!(temp->getRight())) //if right child doesn't exist slot it in
  					{
  						temp->setRight(new RedBlackNode<KeyType, ValueType>(key, value, temp));
  						temp = temp->getRight();
  						fixTree(temp);
  						break;
  					}
  					else
  					{
  						temp = temp->getRight();
  					}
  				}
  			}
  		}
  	}

  	class iterator 
	{
	public:
	    iterator(RedBlackNode<KeyType,ValueType>* root) 
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

		const Color& operator&() const
		{
			return curr->getColor();
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
	  			RedBlackNode<KeyType, ValueType>* p = curr->getParent();
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
	 	RedBlackNode<KeyType, ValueType>* curr;
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

	void print() const
	{ 
	     printRoot (root);
	     std::cout << "\n";
	}


protected:
	RedBlackNode<KeyType, ValueType>* root;

	void printRoot(RedBlackNode<KeyType, ValueType>* r) const
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

	void deleteAll(RedBlackNode<KeyType, ValueType> *r)
	{
	  	if (r)
	    {
	      	deleteAll (r->getLeft());
	      	deleteAll (r->getRight());
	      	delete r;
	    }
	}

	RedBlackNode<KeyType, ValueType>* lookupHelper(const KeyType& k, RedBlackNode<KeyType, ValueType>* r) const
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

	void leftRotate(RedBlackNode<KeyType, ValueType>* y)
	{
		RedBlackNode<KeyType, ValueType>* x = y->getParent();
		x->setRight(y->getLeft()); //turn y's left subtree into x's right subtree
		if(y->getLeft())
		{
			(y->getLeft())->setParent(x);
		}
		y->setParent(x->getParent()); //y's new parent was x's parent
		//set the parent to point at y instead of x
		if(!(x->getParent())) //check to see if at the root
		{
			this->root = y;
		}
		else
		{
			if(x == ((x->getParent())->getLeft())) //x was on the left of parent
			{
				(x->getParent())->setLeft(y);
			}
			else //x was on the right of parent
			{
				(x->getParent())->setRight(y);
			}
		}
		//finally, put x on y's left
		y->setLeft(x);
		x->setParent(y);
	}

	void rightRotate(RedBlackNode<KeyType, ValueType>* y)
	{
		RedBlackNode<KeyType, ValueType>* z = y->getParent();
		z->setLeft(y->getRight()); //turn y's right subtree into z's left subtree
		if(y->getRight())
		{
			(y->getRight())->setParent(z);
		}
		y->setParent(z->getParent()); //y's new parent was z's parent
		//set z's old parent to point at y instead
		if(!(z->getParent())) //first check if at root
		{
			this->root = y;
		}
		else
		{
			if(z == ((z->getParent())->getLeft())) //z was on left of its parent
			{
				(z->getParent())->setLeft(y);
			}
			else //z was on right of its parent
			{
				(z->getParent())->setRight(y);
			}
		}
		//finally put z on y's right
		y->setRight(z);
		z->setParent(y);
	}

	void fixTree(RedBlackNode<KeyType, ValueType>* newNode)
	{
		//fix until a black parent or you hit the root
		while((newNode != root) && ((newNode->getParent())->getColor() == red) && (newNode->getColor() == red))
		{
			if(newNode->getParent() == (newNode->getParent()->getParent()->getLeft())) //parent is a left
			{
				RedBlackNode<KeyType, ValueType>* uncle = newNode->getParent()->getParent()->getRight(); //uncle is on right
				if(uncle)
				{
					if(uncle->getColor() == red) //red uncle --> case 1 & 2: recolor
					{
						newNode->getParent()->setColor(black);
						uncle->setColor(black);
						newNode->getParent()->getParent()->setColor(red);
						newNode = newNode->getParent()->getParent();
					}
					else //uncle is black
					{
						//parent is left, node is right --> case 5: rotate left of N, then rotate right
						if(newNode == newNode->getParent()->getRight())
						{
							leftRotate(newNode);
							newNode->getParent()->setColor(red);
							newNode->setColor(black);
							rightRotate(newNode);
							newNode = newNode->getParent();
						}
						else //case 4: rotate right of P and recolor
						{
							newNode->getParent()->setColor(black);
							newNode->getParent()->getParent()->setColor(red);
							rightRotate(newNode->getParent());
							newNode = newNode->getParent();
						}
					}
				}
				else //uncle doesn't exist --> implied black
				{
					//parent is left, node is right --> case 5: rotate left of N, then rotate right 
					if(newNode == newNode->getParent()->getRight())
					{
						leftRotate(newNode);
						newNode->getParent()->setColor(red);
						newNode->setColor(black);
						rightRotate(newNode);
						newNode = newNode->getParent();
					}
					else //case 4: rotate right of P and recolor
					{
						newNode->getParent()->setColor(black);
						newNode->getParent()->getParent()->setColor(red);
						rightRotate(newNode->getParent());
						newNode = newNode->getParent();
					}
				}
			}	
			else //parent is right
			{
				RedBlackNode<KeyType, ValueType>* uncle = newNode->getParent()->getParent()->getLeft(); //uncle is left
				if(uncle)
				{
					if(uncle->getColor() == red) //red uncle --> case 1 & 2: recolor
					{
						newNode->getParent()->setColor(black);
						uncle->setColor(black);
						newNode->getParent()->getParent()->setColor(red);
						newNode = newNode->getParent()->getParent();
					}
					else //uncle is black
					{
						//parent is right, node is left --> case 5: rotate right of N, then rotate left
						if(newNode == newNode->getParent()->getLeft())
						{
							rightRotate(newNode);
							newNode->getParent()->setColor(red);
							newNode->setColor(black);
							leftRotate(newNode);
							newNode = newNode->getParent();
						}
						else //case 4: rotate left of P and recolor
						{
							newNode->getParent()->setColor(black);
							newNode->getParent()->getParent()->setColor(red);
							leftRotate(newNode->getParent());
							newNode = newNode->getParent();
						}
						
					}
				}
				else //uncle doesn't exist --> implied black
				{
					//parent is right, node is left --> case 5: rotate right of N, then rotate left
					if(newNode == newNode->getParent()->getLeft())
					{
						rightRotate(newNode);
						newNode->getParent()->setColor(red);
						newNode->setColor(black);
						leftRotate(newNode);
						newNode = newNode->getParent();
					}
					else //case 4: rotate left of P and recolor
					{
						newNode->getParent()->setColor(black);
						newNode->getParent()->getParent()->setColor(red);
						leftRotate(newNode->getParent());
						newNode = newNode->getParent();
					}
					
				}
			}
		}
		//finally always set the root to be black
		root->setColor(black);	
	}
};

#endif