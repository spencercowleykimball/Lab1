#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
  vector <string> tasks;
  TodoList() {
      cout << "In Constructor" << endl;
      ifstream infile ("TODOList.txt");
      string line;
      if (infile.is_open())
      {
        while (getline(infile, line))
        {
          cout << line << "\n";
          tasks.push_back(line);
        }
        infile.close();
      }
  }
  virtual ~TodoList() {
      cout << "In Destructor" << endl;
      ofstream outfile;
      outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
      for(int i = 0; i < tasks.size(); i++) {
        cout << tasks[i] << "\n";
        outfile << tasks[i] << endl;
      }
      outfile.close();
  } 
  
  /*    
	*   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"    
	*/ 
  virtual void add(string _duedate, string _task) {
    cout << "In add " << _duedate<< " " << _task << endl;
    tasks.push_back(_duedate+" "+_task);
  }
  
  /*    
  *   Removes an item from the todo list with the specified task name    
  *    
  *   Returns 1 if it removes an item, 0 otherwise 
  */    
  virtual int remove(string _task) 
  {
		int removed = 0;
    cout << "Here " << _task << endl;
    for (int i = 0; i < (tasks.size()); i++) {
			string toFindTask = tasks.at(i);
			cout << "tasks[" << i << "] " << tasks[i] << endl;
      if(toFindTask.find(_task) != string::npos) {
        tasks.erase(tasks.begin() + i);
				removed = 1;
      }
    }

		return removed;
  }   
  
  /*    
  *   Prints out the full todo list to the console    
  */    
  virtual void printTodoList()
  {
    cout << "All tasks" << endl;
		for (int i = 0; i < (tasks.size()); i++) {
			cout << tasks.at(i) << endl;
    }
		cout << endl;

  } 

  /*    
  *   Prints out all items of a todo list with a particular due date (specified by _duedate)    
  */    
  virtual void printDaysTasks(string _duedate)
  {
    cout << "In daystasks" << endl;
    int stringLength = _duedate.size(); //Get length of input day

		cout << _duedate << endl;

		for (int i = 0; i < (tasks.size()); i++) {
			
			string toFindTask = tasks.at(i);
      
			if(!toFindTask.find(_duedate)) {
				string dayTasks = tasks[i];
				dayTasks.erase(dayTasks.begin(), dayTasks.begin() + stringLength);
				
				cout << dayTasks << endl;
			}
    }
		cout << endl;

  }

};


#endif