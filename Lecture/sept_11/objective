September 11, 2013
Computer Science Lecture Notes


Objectives
=====================
    a. New posted stuff on webcourses
    b. Exam #1 Review
    c. Explanation of grading philosophy
    d. Binary search recursive
    e. calloc, realloc


b. Exam Review
=====================
* One Sheet of paper for notes. (front and back, typed or written)

    1. Arrays, pointer, strings, files, structs
        Manipulation of array elements
        Manipulation of struct components
        Use of strings (strcmp,strlen,strcpy)
        Dynamic Memory Allocation for structs (malloc, calloc, realloc)
        Dynamic Memory Allocation for arrays  (malloc, calloc, realloc)
        Use of free

    2. Recurssion
        Tracing
        Writing
        Fibonacci
        Factorial
        Binary Search
        Exponentiation, Fast Exponentiation
        Towers of Hanoi
        Permutation
        Floodfill ( ie Minesweeper )

    How to Study
    =====================
        1. Look over notes
        2. Look over Example Code
        3. Look over your code
        4. Look at your notes


    Types of Problems
    =====================
        Short Ans:        Write a single line of code to complete some task
        Function Tracing: Give the output of some program or segment of code
        Code writing:     Write a function or complete a segment of code to solve some problem


c. Explanation of Grading Policy
=================================
    1. Recitation Problem #1
    ========================
        Store in array all answers as you build them

    2. Assignment #1
    ========================
        Use less than 4 nested loops
        Use a function for any task that is used more than once.
        Runtime


d. Binary Search Algorithm
=================================
    [2][7][12][13][48][34][18][23][123]
     ^          ^                   ^
    Low        Mid                 High


    Prototype
    ========================
        int binSearch( int * array, int low, int high, int val);

    Pseudocode
    ========================
        int binSearch( int * array, int low, int high, int val){
            if ( low > high ){
                return 0 ;
            }

            int mid = (low+high)/2 ;

            if ( val > array[mid] ) {
                return binSearch( array, mid+1, high, val)
            }else if (val < array[mid]){
                return binSearch(array,low,mid-1,val);
            }else{
                return 1 ;
            }

        }

e. Calloc, Realloc
=================================
    1. Calloc
    ========================
        // Calloc zeros out everything before handing the pointer over
        void * calloc( 100000, sizeof(int));
        void * calloc( numOfIndexes , sizeOfEachIndex);

    2. Realloc
    ========================


