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
        int nextID = taskVector.size() + 1;
        newTask.add_task(nextID,argv[2]);
        taskVector.push_back(newTask);
        writeJSON(taskVector);
    }
    else if (user_input == "update" && argc == 4) {
        int ID = stoi(argv[2]);
        string description = argv[3];
        readJSON(taskVector);
        Task::update_task(ID, description, taskVector);
        cout << taskVector[0].description << endl;
        writeJSON(taskVector);
    }
    return 0;
}