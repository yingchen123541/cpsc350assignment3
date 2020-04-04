#include <iostream>

/** GenStack.h
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment3  Syntax Checker
* purpose: define constructors, array and functions
* Version 3.0
* Date: April 3rd, 2020
*
*/


using namespace std;

class GenStack
{
  public:
    GenStack();//default constructor
    GenStack(int maxSize);//overload constructor
    ~GenStack();//destructor

    //functions
    void push(char data);//insert
    //pop will return char
    char pop(); //remove using pop

    //helper function
    bool isFull();
    bool isEmpty();
    char peek();
    string StackEmptyException();
    //size is an actual keyword
    int mSize; //max size of my stack
    int top; // variable to keep track of indices representing the top of myStack

    char *myArray; // each char is 1 byte
};
