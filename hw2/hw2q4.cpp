#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

struct Item {
  int val;
  Item* next;
};

void append(Item*& head, int v)
{
	//base case is if there is nothing in the head yet (no items in the list)
	if(head == NULL)
	{
		head = new Item;
		head->val = v;
		head->next = NULL;
	}
	else
	{
		//walk to the end of the list
		Item* temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}
		//create a new item
		Item* newItem = new Item;
		newItem->val = v;
		newItem->next = NULL;
		//set the next pointer of the last item in the list to point to the new item
		temp->next = newItem;
	}
}

//function to print out every item in the linked list 
void print(Item* head)
{
	Item* temp = head;
	//while we're not at the end of the list, print out what's in the value field of each Item
	while(temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

//even numbers have no remainder when divided by 2
bool isEven (int n)
{
	return (n % 2 == 0);
}

//take the square root of the number, cast it to int to get rid of the decimals
//multiply the root by itself, if it's still the same without decimals then it's a perfect square
bool isSquare (int n)
{
	if(n < 0)
	{
		return false;
	}
	int root = (int)sqrt(n);
	return (root*root == n);
}

bool isPrime (int n)
{
	//prime numbers can't be less than or equal to 1
	if(n <= 1)
	{
		return false;
	}
	else
	{
		//start with the assumption that the number is prime, test to see if it is not
		bool prime = true;
		//start at 3 because 2 is a prime number
		for(int i = 3; i < n; i++)
		{
			if(n % i == 0)
			{
				prime = false;
			}
		}
		return prime;
	}
}

Item* filter(Item *head, bool (*f)(int), Item* filtered)
{
	//base case is when we pass in the end of the list, print out the list at that point
	if(head == NULL)
	{
		print(filtered);
		return filtered;
	}
	//pass the value field of the item into the predicate function we're checking for
	//if it evaluates to true, add it to the Item
	if(f(head->val))
	{
		append(filtered, head->val);
	}
	//recursively pass in the next Item in the list
	filter(head->next, f, filtered);

	return filtered;
}

int main(int argc, char* argv[])
{
	ifstream myFile(argv[1]);
	//test to make sure file opened
	if(myFile.fail())
	{
		cout<<"File failed to open"<<endl;
	}
	//see which filter we are applying
	char whichFilter = *argv[2];
	//read all integers into a linked list
	Item* original = NULL;
	string tempS = "";
	while(getline(myFile, tempS))
	{
		stringstream ss;
		ss<<tempS;
		int tempI = 0;
		while(ss>>tempI)
		{
			append(original, tempI);
		}
		tempS = "";
	}
	Item* newList = NULL;
	Item* sorted = NULL;
	//if filter A, we want to use the isEven filter
	if(whichFilter == 'A')
	{
		sorted = filter(original, &isEven, newList);
	}
	//if B, we want the isSquare filter
	else if(whichFilter == 'B')
	{
		sorted = filter(original, &isSquare, newList);
	}
	//if C, we want the isPrime filter
	else if(whichFilter == 'C')
	{
		sorted = filter(original, &isPrime, newList);
	}
	//otherwise we don't have a valid filter
	else
	{
		cout<<"This is not a valid filter"<<endl;
	}
}