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

void update_task(int ID, string description, vector<Task> &taskVector) {
    for (Task i:taskVector) {
        Task *currentTask = &i;
        if (currentTask->ID == ID) {
            currentTask->description = description;
        }
    }
    cerr << "Task with the current ID does not exist." << endl;
}

void delete_task(int ID, vector<Task> &taskVector) {
    for (int i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].ID == ID) {
            taskVector.erase(taskVector.begin() + i);
        }
    }
}

void mark_progress(int ID, string status, vector<Task> &taskVector) {
    for (Task i:taskVector) {
        Task *currentTask = &i;
        if (currentTask->ID == ID) {
            if (status == "mark-in-progress") {
                currentTask->status = "in-progress";
            }
            else if (status == "mark-done") {              
                currentTask->status = "done";
            }
        }
    }
}

void list(string status, vector<Task> &taskVector) {
    if (status == "todo") {
        for (Task i:taskVector) {
            if (i.status == "todo") {
                cout << i.description << endl;
            }
        }
    }
    else if (status == "in-progress") {
        for (Task i: taskVector) {
            if (i.status == "in-progress") {
                cout << i.description << endl;
            }
        }
    }
    else if (status == "done") {
        for (Task i: taskVector) {
            if (i.status == "done") {
                cout << i.description << endl;
            }
        }
    }  
}