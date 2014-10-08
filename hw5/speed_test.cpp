// speed_test.cpp
#include <iostream>
#include <chrono>

// list definitions
#include "ilist.h"
#include "linkedlistImpl.h"
#include "arraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"

using namespace std;

double MeasureFrontInsertTime(IList<int>* list, int insertCount = 50000)
{
    //double time = 0.0;
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < insertCount; ++i)
    {
        cout << i << endl;
        list->insert(0, i);
    } 
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    return time_span.count();
}

double MeasureBackInsertTime(IList<int>* list, int insertCount = 50000)
{
    //double time = 0.0;
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < insertCount; ++i)
    {
        //cout << i << endl;
        list->insert(i, i);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    return time_span.count();
}

int main()
{
    double frontTime = 0.0, backTime = 0.0;
    IList<int>** lists = new IList<int>*[8];

    // feel free to pass some argument to your constructor or just leave it to the default constructor
    lists[0] = new LinkedList<int>();          // front insert
    lists[1] = new LinkedList<int>();          // back  insert
    lists[2] = new PlusOneArrayList<int>();    // front insert
    lists[3] = new PlusOneArrayList<int>();    // back  insert
    lists[4] = new PlusTenArrayList<int>();    // front insert
    lists[5] = new PlusTenArrayList<int>();    // back  insert
    lists[6] = new DoublingArrayList<int>();   // front insert
    lists[7] = new DoublingArrayList<int>();   // back  insert

    for (int i = 0; i < 2; i += 2)
    {
        frontTime = MeasureFrontInsertTime(lists[i]);
        //backTime  = MeasureBackInsertTime (lists[i + 1]);
        cout << frontTime << endl;
        //cout << backTime << endl;
        // release: you can optionally measure delete (removing all items) duration
        //delete lists[i];
        //delete lists[i + 1];
    }
    //delete [] lists;
    return 0;
}