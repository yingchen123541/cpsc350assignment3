#include "GenStack.h"
//need another main.cpp after this GenStack.cpp

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

GenStack::~GenStack()
{
  //try without [] if doesn't compile
   delete myArray;
}

//function
void GenStack::push(char data)
{
  //check if full before inserting
  //increment top and insert
  myArray[++top] = data;
}

char GenStack::pop()
{
  //check if it's empty before proceeding to remove
  return myArray[top--];
}

char GenStack::peek(){
  return myArray[top];
}

bool GenStack::isFull()
{
  return (top == mSize-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
