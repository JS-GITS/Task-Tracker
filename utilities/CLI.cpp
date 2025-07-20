#include <iostream>
#include <iomanip>
#include "CLI.h"
#include "utils.h"

/**
 * @brief Assigns the member variables of an object of class Task when initalized
 * 
 * When an object of class Task is created, all the member variables are assigned to be empty
 * or 0 when initialized.
 */
Task::Task() {
    this->ID = 0;
    this->description = "";
    this->status = "";
    this->createdAt = "";
    this->updatedAt = "";
}

/**
 * @brief Assigns all the member variables of the object with the necessary information
 * 
 * Takes in the next ID for a task, description, status, and current date, it will then 
 * assign those values to the object.
 * 
 * @param the next task ID to be added to the list of tasks
 * @param description assigned to the current task
 */
void Task::add_task(size_t nextID, string &description) {
    this->ID = nextID;
    this->description = description;
    status = "todo";
    this->createdAt = get_date();
}

/**
 * @brief Assigns a new description to that task ID
 * 
 * Takes the ID, description, and the vector of Tasks and updates the 
 * description using the ID, as well as assigning the date to the updatedAt member variable.
 * 
 * @param the current task ID being updated
 * @param the new description assigned to the task ID
 * @param vector of Tasks from the file
 */
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

/**
 * @brief Deletes the task with the given task ID
 * 
 * Takes in the task ID and searches through the vector of Tasks,
 * whichever task corresponds to that ID, will be erased from the vector
 * 
 * @param the current task ID being deleted
 * @param vector of Tasks from the file 
 */
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

/**
 * @brief Searches the task with the same ID and change its status
 * 
 * Takes in the task ID and searches through the vector of Tasks,
 * whichever task corresponds to that ID, the function will change
 * its progress to the given status
 * 
 * @param the current task ID being deleted
 * @param the given status to change to (e.g. todo, in-progress, done)
 * @param vector of Tasks from the file 
 */
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

/**
 * @brief Lists out all the tasks from the file
 * 
 * Reads the Tasks from the vector after reading them from the JSON file,
 * then use the print_table function to print the tasks to the output stream
 * in a neatly manner.
 * 
 * @param vector of Tasks from the file 
 */
void Task::list(const vector<Task> &taskVector) {
    int IDWidth = 5;
    int descriptionWidth = 27;
    int statusWidth = 15;
    int createdAtWidth = 25;
    int updatedAtWidth = 25;
    size_t counter = 0;
    size_t descriptionLength;
    string stringPiece;
    vector <string>stringPieces;
    cout << "ID   | Description               | Status        | Created At              | Updated At\n";
    cout << "-----+---------------------------+---------------+-------------------------+-------------------------\n";
    for (const Task &i:taskVector) {
        stringPiece = i.description.substr(counter,24);
        while (stringPiece.size() == 24) {
            stringPiece += "-";
            stringPieces.push_back(stringPiece);
            counter += 24;
            stringPiece = i.description.substr(counter,24);
        }
        counter = 0;
        stringPieces.push_back(stringPiece);
        cout << left << setw(IDWidth) << i.ID << " " << setw(descriptionWidth) << stringPieces[0]
        << " " << setw(statusWidth) << i.status << " " << setw(createdAtWidth) << i.createdAt
        << " " << setw(updatedAtWidth) << i.updatedAt << endl;
        for (int i = 1; i < stringPieces.size(); i++) {
            cout << "      " << stringPieces[i] << endl;
        }
        stringPieces.clear();
    }
}

/**
 * @brief Lists out all the tasks from the file with the following status
 * 
 * Reads the Tasks from the vector after reading them from the JSON file,
 * check each task which corresponds to the following status, then use
 * the print_table function to print the tasks to the output stream
 * in a neatly manner.
 * 
 * @param the given status to search for
 * @param vector of Tasks from the file 
 */
void Task::list(string &status, const vector<Task> &taskVector) {
    vector<Task> tempVector;
    if (status == "todo") {
        for (const Task &i:taskVector) {
            if (i.status == "todo") {
                tempVector.push_back(i);
            }
        }
        list(tempVector);
    }
    else if (status == "in-progress") {
        for (const Task &i: taskVector) {
            if (i.status == "in-progress") {
                tempVector.push_back(i);
            }
        }
        list(tempVector);
    }
    else if (status == "done") {
        for (const Task &i: taskVector) {
            if (i.status == "done") {
                tempVector.push_back(i);
            }
        }
        list(tempVector);
    }  
}