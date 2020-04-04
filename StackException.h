#include <iostream>
using namespace std;

class StackException{
  public:
    StackException();
    StackException(const string& err);
    ~StackException();

    string errmessage;

    string getError();

};
