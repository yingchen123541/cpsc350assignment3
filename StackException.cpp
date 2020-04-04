#include "StackException.h"

StackException::StackException(){
  errmessage="EmptyStackException, can't pop from empty stack";
}

StackException(const string& err):errmessage(err){

}

string StackException::getError()
{
  return errmessage;
}
