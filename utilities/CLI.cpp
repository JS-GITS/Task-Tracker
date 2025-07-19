#include <iostream>
#include "CLI.h"
#include "utils.h"

// Constructor of the Class Task
Task::Task() {
    this->ID = 0;
    this->description = "";
    this->status = "";
    this->createdAt = "";
    this->updatedAt = "";
}


// Takes in the next ID for a task and its description, it will then assign those values to the object
void Task::add_task(size_t nextID, string &description) {
    this->ID = nextID;
    this->description = description;
    status = "todo";
    this->createdAt = get_date();
}

// Takes the ID, description, and the vector of Tasks and updates the description using the ID
void Task::update_task(size_t ID, string &description, vector<Task> &taskVector) {
    for (Task &i:taskVector) {
        if (i.ID == ID) {
            i.description = description;
            i.updatedAt = get_date();
            return;
        }
    }
    cerr << "Task with the current ID does not exist." << endl;
    exit(1);
}

// Locates the index of the ID and deletes it from the vector of Tasks
void Task::delete_task(size_t ID, vector<Task> &taskVector) {
    for (size_t i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].ID == ID) {
            taskVector.erase(taskVector.begin() + i);
            return;
        }
    }
    cerr << "Task with the current ID does not exist." << endl;
    exit(1);
}

// Searches the task with the same ID and change the status
void Task::mark_progress(size_t ID, string &status, vector<Task> &taskVector) {
    for (Task &i:taskVector) {
        if (i.ID == ID) {
            if (status == "mark-todo") {
                i.status = "todo";
                return;
            }
            else if (status == "mark-in-progress") {
                i.status = "in-progress";
                return;
            }
            else if (status == "mark-done") {              
                i.status = "done";
                return;
            }
        }
    }
    cerr << "Task with the current ID does not exist." << endl;
    exit(1);
}

// Lists out all the tasks
void Task::list(const vector<Task> &taskVector) {
    for (const Task &i:taskVector) {
        cout << i.description << endl;
    }
}

// Searches all the tasks with the following status
void Task::list(string &status, const vector<Task> &taskVector) {
    if (status == "todo") {
        for (const Task &i:taskVector) {
            if (i.status == "todo") {
                cout << i.description << endl;
            }
        }
    }
    else if (status == "in-progress") {
        for (const Task &i: taskVector) {
            if (i.status == "in-progress") {
                cout << i.description << endl;
            }
        }
    }
    else if (status == "done") {
        for (const Task &i: taskVector) {
            if (i.status == "done") {
                cout << i.description << endl;
            }
        }
    }  
}