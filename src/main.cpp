#include "../utilities/CLI.h"
#include "../utilities/utils.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // Check if there are lesser than 2 CLI arguments
    if (argc < 2) {
        cerr << "Usage: ./main <input>" << endl;
        return 1;
    }
    // Assign the user input as the second CLI argument after ./main
    string user_input = argv[1];
    // Set up the vector of type Task
    vector<Task> taskVector;

    // If cases, testing for the CLI arguments
    if (user_input == "add" && argc == 3) {
        readJSON(taskVector);
        Task newTask;
        size_t nextID = 1;
        size_t lastPos = taskVector.size() - 1;
        if (lastPos != SIZE_MAX) {
            Task lastElement = taskVector[lastPos];
            nextID = lastElement.ID + 1;
        }
        string description = argv[2];
        newTask.add_task(nextID,description);
        taskVector.push_back(newTask);
        writeJSON(taskVector);
        cout << "Task has been added!" << endl;
    }
    else if (user_input == "update" && argc == 4) {
        size_t ID = stoi(argv[2]);
        string description = argv[3];
        readJSON(taskVector);
        Task::update_task(ID, description, taskVector);
        writeJSON(taskVector);
        cout << "Task has been updated!" << endl;
    }
    else if (user_input == "delete" && argc == 3) {
        size_t ID = stoi(argv[2]);
        readJSON(taskVector);
        Task::delete_task(ID, taskVector);
        writeJSON(taskVector);
        cout << "Task has been deleted!" << endl;
    }
    else if((user_input == "mark-todo" || user_input == "mark-in-progress" || user_input == "mark-done") && argc == 3) {
        size_t ID = stoi(argv[2]);
        readJSON(taskVector);
        Task::mark_progress(ID, user_input, taskVector);
        writeJSON(taskVector);
        string temp = "mark-";
        string status = user_input.substr(user_input.find("mark-") + temp.size());
        cout << "Task has been marked: " << status << endl;
    }
    else if (user_input == "list" && argc == 2) {
        readJSON(taskVector);
        Task::list(taskVector);
    }
    else if (user_input == "list" && argc == 3) {
        string selection = argv[2];
        if ((selection == "todo" || selection == "in-progress" || selection == "done") && argc == 3) {
            readJSON(taskVector);
            Task::list(selection, taskVector);
        }
    }
    else {
        // If the user input is invalid
        cerr << "Usage: ./main <function> <optional argument>" << endl;
        return 1;
    }
    return 0;
}