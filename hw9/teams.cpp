#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		throw invalid_argument("Not the right number of command line arguments!");
	}

	ifstream input(argv[1]);
	if(input.fail())
	{
		throw runtime_error("A file failed to open!");
	}

	map<int, string> students;
	vector<string> names;
	map<string, string> teams;
	vector<int> scores;
	bool isPossible = true;

	string temp = "";
	getline(input, temp);
	stringstream ss;
	ss << temp;
	int numStudents;
	ss >> numStudents;
	if(numStudents % 2 != 0)
	{
		isPossible = false;
	}

	temp = "";
	while(getline(input, temp))
	{
		stringstream ss1;
		ss1 << temp;
		string name;
		ss1 >> name;
		ss1 << temp;
		int score;
		ss1 >> score;
		students.insert(make_pair(score, name));
		names.push_back(name);
	}

	
	map<int, string>::iterator it1 = students.begin(); 
	map<int, string>::reverse_iterator rit = students.rbegin();
	while(it1 != students.end() && rit != students.rend())
	{
		int teamScore = 0;
		teams.insert(make_pair(it1->second, rit->second));
		teamScore += it1->first;
		teamScore += rit->first;
		scores.push_back(teamScore);
		++it1;
		++rit;
	}
	int teamScore = scores[0];
	for(vector<int>::iterator it = scores.begin(); it != scores.end(); ++it)
	{
		int temp = *it;
		if(temp != teamScore)
		{
			isPossible = false;
		}
	}
	if(isPossible)
	{
		for(vector<string>::iterator it = names.begin(); it != names.end(); ++it)
		{
			string partner = teams[(*it)];
			cout << *it << " " << partner << endl;
		}
	}
	else
	{
		cout << "This assignment is impossible" << endl;
	}	
	return 0;
}