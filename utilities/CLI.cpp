#include <iostream>
#include "CLI.h"
#include "utils.h"

Task::Task() {
    this->ID = -1;
    this->description = "";
    this->status = "";
    this->createdAt = "";
    this->updatedAt = "";
}

void Task::add_task(int nextID, string description) {
    this->ID = nextID;
    this->description = description;
    status = "todo";
    this->createdAt = get_date();
}

void Task::update_task(int ID, string description, vector<Task> &taskVector) {
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

void Task::delete_task(int ID, vector<Task> &taskVector) {
    for (int i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].ID == ID) {
            taskVector.erase(taskVector.begin() + i);
            return;
        }
    }
    cerr << "Task with the current ID does not exist." << endl;
    exit(1);
}

void Task::mark_progress(int ID, string status, vector<Task> &taskVector) {
    for (Task &i:taskVector) {
        if (i.ID == ID) {
            if (status == "mark-in-progress") {
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

void Task::list(string status, const vector<Task> &taskVector) {
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