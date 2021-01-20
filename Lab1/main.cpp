#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;
int main(int argc, char *argv[]) 
{
  TodoList mylist;
  for(int i = 0; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
  
  string firstarg = argv[1];

  //For the add option
  if(firstarg.compare("add") == 0) {
    cout << "Doing an add" << endl;
    string date = argv[2];
    string task = argv[3];
    cout << "date " << date << " task " << task << endl;
    mylist.add(date, task);

  }

  //For the remove option
	if(firstarg.compare("remove") == 0) {
    cout << "Doing a remove" << endl;
    string task = argv[2];

    cout << " task " << task << endl;
    mylist.remove(task);

  }

  //For the  option
	if(firstarg.compare("remove") == 0) {
    cout << "Doing a remove" << endl;
    string task = argv[2];

    cout << " task " << task << endl;
    mylist.remove(task);

  }
}
