##Homework 8

**Student Information:**
+ Name: Kabir Gupta
+ USC Email: kabirgup@usc.edu
+ USC ID: 5957478548

***

###Homework 8 Make/Run Instructions:

To make all:

> `make`

####Problem 2 (Evaluate Quicksort)

Works sometimes, not sure why not

####Problem 3 (Grading Students)
+ My program uses a modified binary search along with heapsort to ensure a runtime of O(n*logn)
+ It will write that the assignment is not possible if there are not an equal number of instructor grades and student abilities or if the given assignments are not possible
+ Otherwise will write the assignments to the output file with the students in the same order as given

To compile:

> `make`

To run the program with input and output files: 

> `./grades inputFile.txt outputFile.txt`

To run the program with given test input and output files:

> `./grades testInput.txt testOut.txt`

####Problem 4 (Build a d-ary heap)

+ Built a d-ary heap using the STL vector<T> container. All functions should work as expected

####Problem 5 (Evaluate d-ary heaps for different d)

To compile the test program:

> `make`

To run the test program, which will write the insertion and removal times to `heaptimes.txt`:

> `./heapeval`

+ All times are listed in `heaptimes.txt`

