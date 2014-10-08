#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdint.h>
#include "stack.h"
//#include "arraylist.h"
#include "mapImpl.h"

using namespace std;


bool isInt(const string s)
{
	return (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9");
}

bool createVar(const string s)
{
	bool literal = true;
	if(s == "F")
	{
		return false;
	}
	return literal;
}

void changeVar(bool &temp1)
{
	temp1 = !temp1;
}

string changeBack(bool temp1)
{
	string s;
	if(temp1)
	{
		s = "T";
	}
	else
	{
		s = "F";
	}
	return s;
}

bool isBool(const string s)
{
	return (s == "T" || s == "F");
}

bool isOperator(const string s)
{
	return (s == "|" || s == "&");
}

bool isNot(const string s)
{
	return (s == "~");
}

bool isSpace(const string s)
{
	return (s == " ");
}

bool isOpenParens(const string s)
{
	return (s == "(");
}

bool isCloseParens(const string s)
{
	return (s == ")");
}

int main(int argc, char* argv[])
{
	try
	{
		if(argc != 3)
		{
			throw invalid_argument("Not enough arguments!");
		}
	}
	catch(invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	ifstream file1(argv[1]);
	ifstream file2(argv[2]);
	try
	{
		if(file1.fail())
		{
			throw invalid_argument("File 1 failed to open!");
		}
		if(file2.fail())
		{
			throw invalid_argument("File 2 failed to open!");
		}
	}
	catch(invalid_argument& e)
	{
		cout << e.what() << endl;
	}

	Map<string, string>* variableAssignments = new Map<string, string>;
	string temp = "";
	while(getline(file2, temp))
	{
		stringstream ss;
		ss << temp;
		string var;
		ss >> var;
		string assignment;
		ss >> assignment;
		variableAssignments->add(var, assignment);
		temp = "";
	}
	
	while(getline(file1, temp))
	{
		try
		{
			Stack<string>* evaluator = new Stack<string>;
			int tempSize = temp.size();
			int index = 0;
			string curr = temp.substr(index, 1);
			//cout << "curr: " << curr << endl;
			int openParensCount = 0;
			//First character should be an open parentheses or a NOT
			if(!isOpenParens(curr) && !isNot(curr))
			{
				throw invalid_argument("Malformed");
			}
			evaluator->push(curr);
			if(isOpenParens(curr))
			{
				++openParensCount;
			}
			//cout << "first pushed: " << curr << endl;
			++index;
			curr = temp.substr(index, 1);
			//cout << "after first, curr is: " << curr << endl;
			while(index < tempSize)
			{
				string top = evaluator->top();
				int currTopLength = top.size();
				string currTop = top.substr(currTopLength-1);
				//cout << "top is: " << currTop << endl;
				//white spaces do not matter to us
				if(isSpace(curr))
				{
					//cout << "curr: " << curr << endl;
					//cout << "skipped white space" << endl;
					++index;
					curr = temp.substr(index, 1);
					//cout << "curr: " << curr << endl;
					continue;
				}
				else if(isOpenParens(curr) || isNot(curr))
				{
					//cout << "curr is open parens or not: " << curr << endl;
					evaluator->push(curr);
					//cout << "pushed: " << curr << endl;
					if(isOpenParens(curr))
					{
						++openParensCount;
					}
					++index;
					curr = temp.substr(index, 1);
					//cout << "curr: " << curr << endl;
					continue;
				}
				else if(isOpenParens(currTop) && !(isInt(curr) || isNot(curr) || isCloseParens(curr)))
				{
					throw invalid_argument("Malformed");
				}
				else if(isNot(currTop) && !(isOpenParens(curr) || isNot(curr) || isInt(curr)))
				{
					throw invalid_argument("Malformed");
				}
				else if(isBool(currTop) && !(isInt(curr) || isOperator(curr) || isCloseParens(curr) || isNot(curr)))
				{
					throw invalid_argument("Malformed");
				}
				else if(isOperator(evaluator->top()) && isOperator(curr))
				{
					throw invalid_argument("Malformed");
				}
				else if((isOpenParens(currTop)) && isInt(curr))
				{
					string variable;
					while(isInt(curr))
					{
						//cout << "curr is an int: " << curr << endl;
						variable += curr;
						++index;
						curr = temp.substr(index, 1);
						//cout << "curr: " << curr << endl;
					}
					string actual = variableAssignments->get(variable);
					//cout << "actual: " << actual << endl;
					evaluator->push(actual);
					//cout << "pushed: " << variable << endl;
					continue;
				}
				else if((isNot(currTop)) && isInt(curr))
				{
					string variable;
					while(isInt(curr))
					{
						//cout << "curr is an int: " << curr << endl;
						variable += curr;
						++index;
						curr = temp.substr(index, 1);
						//cout << "curr: " << curr << endl;
					}
					string actual = variableAssignments->get(variable);
					bool temp2 = createVar(actual);
					changeVar(temp2);
					actual = changeBack(temp2);
					evaluator->pop();
					//cout << "actual: " << actual << endl;
					evaluator->push(actual);
					//cout << "pushed: " << variable << endl;
					continue;
				}
				else if(isInt(curr))
				{
					string variable;
					while(isInt(curr))
					{
						//cout << "curr is an int: " << curr << endl;
						variable += curr;
						++index;
						curr = temp.substr(index, 1);
						//cout << "curr: " << curr << endl;
					}
					string actual = variableAssignments->get(variable);
					//cout << "actual: " << actual << endl;
					evaluator->push(actual);
					//cout << "pushed: " << variable << endl;
					continue;
				}
				else if(isBool(currTop) && (isOperator(curr) || isOpenParens(curr) || isNot(curr)))
				{
					//cout << "int on top, curr: " << curr << endl;
					evaluator->push(curr);
					//cout << "pushed: " << curr << endl;
					++index;
					curr = temp.substr(index, 1);
					//cout << "curr: " << curr << endl;
					continue;
				}
				else if((isOperator(currTop) || isNot(evaluator->top())) && !isCloseParens(curr))
				{
					//cout << "operator on top, curr: " << curr << endl;
					evaluator->push(curr);
					//cout << "pushed: " << curr << endl;
					++index;
					curr = temp.substr(index, 1);
					//cout << "curr: " << curr << endl;
					continue;
				}
				else if((isOperator(curr) || isNot(curr)) && isBool(currTop))
				{
					//cout << "operator is curr, curr: " << curr << endl;
					evaluator->push(curr);
					//cout << "pushed: " << curr << endl;
					++index;
					curr = temp.substr(index, 1);
					continue;
				}
				else if(openParensCount < 0)
				{
					throw invalid_argument("Malformed");
				}
				else if(isCloseParens(curr))
				{	
					//cout <<"printing at beginning" << endl;
					//evaluator->print();
					//cout << "Evaluating!" << endl;
					bool temp2;
					string opHolder;
					bool currEvaluation;
					int counter = 0;
					string evaluated;
					while(!isOpenParens(currTop))
					{
						if(counter > 0)
						{
							evaluator->push(evaluated);
						}
						//cout << "top at start of while loop: " << currTop<< endl;
						temp2 = createVar(currTop);
						evaluator->pop();
						currTop = evaluator->top();
						opHolder = currTop;
						evaluator->pop();
						currTop = evaluator->top();
						bool temp3 = createVar(currTop);
						evaluator->pop();
						if(opHolder == "&")
						{
							currEvaluation = temp2 && temp3;
						}
						else if(opHolder == "|")
						{
							currEvaluation = temp2 || temp3;
						}
						evaluated = changeBack(currEvaluation);
						//cout << "evaluated: " << evaluated << endl;
						
						currTop = evaluator->top();
						//cout << "top at end of while loop: " << currTop << endl;
						//evaluator->push(evaluated);
						
						++counter;
						//cout << "stack at end of while loop" << endl;
						//evaluator->print();
					}
					evaluated = changeBack(currEvaluation);
					currTop = evaluator->top();
					//cout << "top is: " << currTop << endl;
					evaluator->pop(); //pop the open parens
					evaluator->push(evaluated);
					--openParensCount;
					++index;
					curr = temp.substr(index, 1);
					//evaluator->print();
					continue;
				}

				++index;
				curr = temp.substr(index, 1);
				//cout << "curr: " << curr << endl;
			}
			if(openParensCount > 0)
			{
				throw invalid_argument("Malformed");
			}
			string final = evaluator->top();
			cout << final << endl;
			evaluator->pop();
			/*while(!evaluator->isEmpty())
			{

			}*/
			//evaluator->print();
			//cout << endl;
		}
		catch(invalid_argument& o)
		{
			cout << o.what() << endl;
			cout << endl;
		}
	}

}