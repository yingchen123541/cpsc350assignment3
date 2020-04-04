

#include "GenStack.cpp"
#include<fstream>

/** GenStackMain.cpp
* Name: Yuki Chen
* Student ID: 2320235
* Email: yingchen@chapman.edu
*
* Assignment3  Syntax Checker
* purpose: open a file and see whether all the delimiters are matched up in that file
*          let the user know when there's extra delimiters or need additional delimiters in certain lines
*          exit the program and let the user fix the error then read from a file again
* Version 3.0
* Date: April 3rd, 2020
*
*/


using namespace std;

int main() {
   bool fileOk=true;
   string inputfileName;
   cout << "enter a file name" << endl;
   cin >> inputfileName;

  while(fileOk){
  //initialize variables
  string Line;
  double totalLine=0;
  string a;
  GenStack *Stack1 = new GenStack(10);
  GenStack *Stack2 = new GenStack(10);
  GenStack *Stack3 = new GenStack(10);

  ifstream InputFile;
  InputFile.open(inputfileName);
  //if input file doesn't exist
  if(!InputFile)
  {
    //output error message
    cerr << "unable to open file" << endl;
    exit(1);
  } // end if

  //input file successfully opened
  else if(InputFile)
  {
    while (getline(InputFile, Line))
    {
      //keep track of the line the error is at
      totalLine++;
      //loop through each line and add {} [] () in array
      for(int z=0; z < Line.length(); z++)
      {
        //divide each line into single letters
           a = Line.substr(z,1);
          cout << Line[z] << endl;
          //put ( [ { in different stacks to pop
          if(a=="("){
            Stack1->push('(');
          }//end if
          else if(a=="["){
            Stack2->push('[');
          }//end else if
          else if(a=="{"){
            Stack3->push('{');
          }//end else if
          //check whether Stack1 is empty before popping
          else if (a==")"){
            if (!Stack1->isEmpty()){
              Stack1->pop();
          }// end check empty if
           else{
             cout << "found an extra ')' in line " << totalLine << endl;
             exit(1);
           }// end else
        }//end else if

        else if (a=="]"){
          if (!Stack2->isEmpty()){
            Stack2->pop();
        }// end check empty if
         else{
           cout << "found an extra ']' in line " << totalLine << endl;
           exit(1);
         }// end else
      }//end else if

      else if (a=="}"){
        if (!Stack3->isEmpty()){
          Stack3->pop();
      }// end check empty if
       else{
         cout << "found an extra '}' in line " << totalLine << endl;
         exit(1);
       }// end else
    }//end else if
      }//end for
    } // end while
    if (Stack1->isEmpty()){
      cout << "reach end of file, missing ')' in line " << totalLine << endl;
    }
    cout << "totalLine: " << totalLine << endl;

  }// end else if

  string answer;
  cout << "do you want to open another file and process? enter 'yes' or 'no' " << endl;
  cin >> answer;

  if (answer=="yes")
  {
    cout << "enter your file name " << endl;
    cin >> inputfileName;
  }// end if
  else if (answer=="no")
  {
    //exit the program when user chooses no
    cout << "exit the program " << endl;
    fileOk = false;
  } // end else if
}// end fileOK while

  return 0;

}// end main
