#include "maxheap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

struct intGreater
{
	bool operator()(const int lhs, const int rhs)
	{
		return lhs > rhs;
	}
};

//modified binary search which runs in O(logn) that will look for the grade to be assigned
//by finding the smallest grade which is bigger than or equal to the student's ability
int bsearch(vector<int>& toSearch, int val, int start, int end)
{
	int index = 0;
	while(start < end)
	{
		int mid = (start + end) / 2;
		if(val < toSearch.at(mid))
		{
			end = mid;
			continue;
		}
		else if(val > toSearch.at(mid) && val <= toSearch.at(mid + 1))
		{
			start = mid + 1;
			index = start;
			break;
		}
		else
		{
			start = mid + 1;
			continue;
		}
	}
	return index;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		throw invalid_argument("Not the right number of command line arguments!");
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);

	if(input.fail() || output.fail())
	{
		throw runtime_error("A file failed to open!");
	}

	intGreater bigger; //comparator
	MaxHeap<int, intGreater> instructorGrades(2, bigger); //sorts and holds the grades to be given out
	vector<int> possibleGrades; //holds the sorted grades to be given out
	vector<string> students; //holds the student names in order
	vector<int> grades; //holdes the students' grades in order
	bool isPossible = true;

	string temp = "";

	int index = 0;
	while(getline(input, temp))
	{
		if(index == 0)
		{
			++index;
			continue;
		}
		if(!isdigit(temp[0])) //has a student name and grade if it doesn't start with a number
		{
			stringstream ss;
			ss << temp;
			string name;
			ss >> name;
			int score;
			ss << temp;
			ss >> score;
			students.push_back(name);
			grades.push_back(score);
		}
		else if(isdigit(temp[0])) //has a score to be assigned if it starts with a number
		{
			stringstream ss;
			ss << temp;
			int score;
			ss >> score;
			instructorGrades.add(score);
		}
		temp = "";
	}

	//get the instructor grades in sorted order through heapsort, which runs in O(n*logn)
	while(!instructorGrades.isEmpty())
	{
		possibleGrades.insert(possibleGrades.begin(), instructorGrades.peek());
		instructorGrades.remove();
	}

	if(grades.size() == possibleGrades.size())
	{
		//find the grade to be assigned, give it to the student, take it out of the possibilities
		for(vector<int>::iterator it = grades.begin(); it != grades.end(); ++it)
		{
			int toAssign = bsearch(possibleGrades, (*it), 0, possibleGrades.size() - 1);
			if((*it) > possibleGrades.at(toAssign))
			{
				isPossible = false;
			}
			*it = possibleGrades.at(toAssign);
			possibleGrades.erase(possibleGrades.begin() + toAssign);
		}
	}
	else
	{
		isPossible = false;
	}
	//write the new assignments to the output file
	if(isPossible)
	{
		int numStudents = students.size();
		int tempIndex = 0;
		while(tempIndex < numStudents)
		{
			output << students.at(tempIndex) << " " << grades.at(tempIndex) << endl;
			++tempIndex;
		}
	}
	else
	{
		output << "This assignment is impossible!" << endl;
	}
	

	output.close();
	return 0;
}