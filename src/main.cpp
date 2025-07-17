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

    ofstream writeFile("./src/list.json");
    ifstream readFile("./src/list.json");
    vector<Tasks> taskVector;
    
    if (!writeFile) {
        cerr << "File could not be created or opened." << endl;
    }

    if (user_input == "add" && argc == 3) {
        string description = argv[2];
        write_to_file(writeFile,taskVector);
    }
    else if (user_input == "")
    return 0;
}