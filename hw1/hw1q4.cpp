#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream ourfile(argv[1]);
	//test to make sure the file opened
	if (ourfile.fail())
	{
		cout<<"Failed to open the file"<<endl;
	}
	else
	{
		int numLines = 0;
		ourfile >> numLines;
		//ifstream pointer doesn't go to next line, must manually do that
		string firstLine;
		getline(ourfile,firstLine);
		//Read all lines into an array of strings
		string *lines = new string[numLines];
		for (int i=0; i < numLines; i++)
		{
			getline(ourfile, lines[i]);
			cout<<lines[i]<<endl;
		}
		//create an array of numbers of words
		int *numWords = new int[numLines];
		//counter for the numWords array
		int count = 0;
		//count backwards from the end of the file
		for (int i = numLines-1; i >= 0; i--)
		{
			int len = lines[i].length();
			//counter for the number of words in a line
			int num = 0;
			//array to store the words we are parsing
			string *words = new string[len];
			stringstream ss;
			//read the line we are parsing into the stringstream
			ss<<lines[i];
			while (ss>>words[num])
			{
				num++;
			}
			numWords[count] = num;
			cout<<numWords[count]<<endl;
			//iterate the counter for numWords
			count++;
			//clear out the stringstream for the next line
			ss.clear();
			ss.str("");
		}							   
	}
}