#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Country
{
	int color;
	char country;
	vector<char> adjacencies;
	Country* next;
};

bool allCountriesColored(int* colorings)
{
	bool colored = true;
	for(int i = 0; i < sizeof(colorings); i++)
	{
		if(colorings[i] == 0)
		{
			colored = false;
		}
	}
	return colored;
}

void search(string row)
{
	
}

int main(int argc, char * argv[])
{
	ifstream myFile(argv[1]);
	//test to make sure the file opened
	if (myFile.fail())
	{
		cout<<"File failed to open"<<endl;
	}
	else
	{
		//Get the first line 
		string firstLine;
		getline(myFile, firstLine);
		//Store the number of countries and dimensions
		stringstream ss;
		ss<<firstLine;
		int numCountries = 0;
		ss>>numCountries;
		int numRows = 0;
		ss>>numRows;
		int numCols = 0;
		ss>>numCols;
		//Create an array of strings to store all the lines
		string* map = new string[numRows];
		//Read in all the lines
		for(int i=0; i < numRows; i++)
		{
			getline(myFile, map[i]);
			cout<<map[i]<<endl;
		}
		//Array to hold the possible color choices
		int colors[4] = {1,2,3,4};
		//Array to hold the countries
		char *countries = new char[numCountries];
		

	}
}