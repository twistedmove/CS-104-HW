#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;

void addLetters(string letters, int numLetters, string combination, int n, int index)
{
	//stop recursing when a row is filled, print out the combination
	if (index == n)
	{
		cout<<combination<<endl;
	}
	else
	{
		for (int i = 0; i < numLetters; i++)
		{
			combination[index] = letters[i];
			addLetters(letters, numLetters, combination, n, index+1);
		}
	}
}

int main(int argc, const char * argv[])
{
	//input string
	string S = argv[1];
	//number of letters in a combination
	int n = atoi(argv[2]);
	//get length of S
	int lenS = S.length();
	//number of possible combinations
	double numPossible = pow(lenS,n);
	cout<<numPossible<<endl;
	//iterator
	int index = 0;
	//string to store the combination
	string combination = "";
	addLetters(S, lenS, combination, n, index);
}