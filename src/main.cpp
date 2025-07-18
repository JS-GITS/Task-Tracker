#include "../utilities/CLI.h"
#include "../utilities/utils.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    string user_input = argv[1];
    if (argc < 2) {
        cout << "Usage: ./task-cli <input>" << endl;
        return 1;
    }

    vector<Task> taskVector;

    if (user_input == "add" && argc == 3) {
        readJSON(taskVector);
        Task newTask;
        Task lastElement = taskVector[taskVector.size()-1];
        int nextID = lastElement.ID + 1;
        string description = argv[2];
        newTask.add_task(nextID,description);
        taskVector.push_back(newTask);
        writeJSON(taskVector);
    }
    else if (user_input == "update" && argc == 4) {
        size_t ID = stoi(argv[2]);
        string description = argv[3];
        readJSON(taskVector);
        Task::update_task(ID, description, taskVector);
        writeJSON(taskVector);
    }
    else if (user_input == "delete" && argc == 3) {
        size_t ID = stoi(argv[2]);
        readJSON(taskVector);
        Task::delete_task(ID, taskVector);
        writeJSON(taskVector);
    }
    else if((user_input == "mark-in-progress" || user_input == "mark-done") && argc == 3) {
        size_t ID = stoi(argv[2]);
        readJSON(taskVector);
        Task::mark_progress(ID, user_input, taskVector);
        writeJSON(taskVector);
    }
    if (user_input == "list") {
        string selection = argv[2];
        if((selection == "todo" || selection == "in-progress" || selection == "done") && argc == 3) {
            readJSON(taskVector);
            Task::list(selection, taskVector);
        }
    }
    return 0;
}