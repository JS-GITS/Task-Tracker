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

    ifstream readFile("./src/list.json");
    vector<Task> taskVector;

    if (user_input == "add" && argc == 3) {
        if (!readFile) {
            Task newTask;
            newTask.add_task(1,argv[2]);
            ofstream writeFile("./src/list.json");
            write_to_file(writeFile,taskVector);
        }
        else {
            Task newTask;
            read_from_file(readFile, taskVector);
            int nextID = taskVector.size() + 1;
            newTask.add_task(nextID,argv[2]);
            taskVector.push_back(newTask);
            ofstream writeFile("./src/list.json");
            write_to_file(writeFile, taskVector);
        }
    }
    else if (user_input == "")
    return 0;
}