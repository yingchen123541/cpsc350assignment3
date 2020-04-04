#include "GenStack.h"

/** GenStack.cpp
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment3  Syntax Checker
* purpose: fill in constructors for array, make functions to use in main class
* Version 3.0
* Date: April 3rd, 2020
*
*/

//default constructor
GenStack::GenStack(){
  myArray = new char[128];
  mSize = 128;
  top = -1;
}

//overload constructor
GenStack::GenStack(int maxSize)
{
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;
}
//destructor 
GenStack::~GenStack()
{
   delete myArray;
}

//function
void GenStack::push(char data)
{

  //function to insert variables in stack
  myArray[++top] = data;
}

char GenStack::pop()
{
  //function to remove the last element in stack
  return myArray[top--];
}
//return the first element in stack
char GenStack::peek(){
  return myArray[top];
}
//function to check whether the stack is full
bool GenStack::isFull()
{
  return (top == mSize-1);
}
//function to check whether the stack is empty
bool GenStack::isEmpty()
{
  return (top == -1);
}
