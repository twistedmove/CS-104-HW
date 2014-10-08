#include "map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

int main(int argc, char * argv[])
{
	try
	{
		if(argc != 2)
		{
			throw invalid_argument("Not the right number of inputs");
		}
		ifstream myFile(argv[1]);
		//test to make sure the file opened
		if (myFile.fail())
		{
			cout<<"File failed to open"<<endl;
		}
		else
		{
			string tempS = "";
			Map<string, string>* emails = new Map<string, string>();
			//read all the emails into the map
			while(getline(myFile, tempS))
			{
				stringstream ss;
				ss<<tempS;
				string email = "";
				ss>>email;
				string name = "";
				ss>>name;
				name += " ";
				string temp;
				ss>>temp;
				name += temp;
				emails->add(email, name);
			}
			cout << "Welcome to the email lookup program!" << endl;
			while(true)
			{
				string input;
				cout << "Please type in an email address, or a period to quit: ";
				cin >> input;
				if(input == ".")
				{
					cout << "Thanks for using this program!" << endl;
					break;
				}
				else
				{
					int index = emails->find(input);
					if(index == -1)
					{
						cout << "This doesn't exist in the database!" << endl;
					}
					else
					{
						cout << "The name of the person is: " << emails->get(input) << endl;
					}
				}
			}
		}
	}
	catch(invalid_argument& o)
	{
		cout << o.what() << endl;
	}	
}