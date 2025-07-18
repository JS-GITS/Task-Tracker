#include "utils.h"
#include "CLI.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

string get_date() {
    auto createdDate = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm* local_tm = localtime(&createdDate);

    // Format as string
    ostringstream oss;
    oss << put_time(local_tm, "%d-%B-%Y %H:%M:%S");
    return oss.str();
}

void write_to_file(ofstream &file,const vector<Task> &objects) {
    file << "[\n";
    for (size_t i = 0; i < objects.size(); i++) {
        file << "   {\n";
        file << "       \"id\": " << objects[i].ID << ",\n";
        file << "       \"description\": \"" << objects[i].description << "\",\n";
        file << "       \"status\": \"" << objects[i].status << "\",\n";
        file << "       \"createdAt\": \"" << objects[i].createdAt << "\",\n";
        file << "       \"updatedAt\": \"" << objects[i].updatedAt << "\"\n";
        file << "   }";
        if (i != objects.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "]\n";
}

void read_from_file(ifstream &file, vector<Task> &objects) {
    if (!file) {
        return;
    }
    Task tempTask;
    string line;
    while (getline(file,line)) {
        size_t position_1 = line.find("\"id\"");
        size_t position_2 = line.find("\"description\"");
        size_t position_3 = line.find("\"status\"");
        size_t position_4 = line.find("\"createdAt\"");
        size_t position_5 = line.find("\"updatedAt\"");
        if (position_1 != string::npos) {
            string idStr = line.substr(position_1 + 6);
            tempTask.ID = stoi(idStr);
        }
        else if (position_2 != string::npos) {
            string descriptionStr = line.substr(position_2 + 16);
            size_t end = line.find("\"",position_2 + 16);
            string text = descriptionStr.substr(0,end-position_2-16);
            tempTask.description = text;
        }
        else if (position_3 != string::npos) {
            string statusStr = line.substr(position_3 + 11);
            size_t end = line.find("\"",position_3 + 11);
            string text = statusStr.substr(0,end-position_3-11);
            tempTask.status = text;
        }
        else if (position_4 != string::npos) {
            string createdStr = line.substr(position_4 + 14);
            size_t end = line.find("\"",position_4 + 14);
            string text = createdStr.substr(0,end-position_4-14);
            tempTask.createdAt = text;
        }
        else if (position_5 != string::npos) {
            string updatedStr = line.substr(position_5 + 14);
            size_t end = line.find("\"",position_5 + 14);
            string text = updatedStr.substr(0,end-position_5-14);
            tempTask.updatedAt = text;
            objects.push_back(tempTask);
        }
    }
}

void writeJSON(vector<Task> &taskVector) {
    ofstream writeFile("./src/list.json");
    if (!writeFile) {
        cerr << "File could not be created or opened." << endl;
    }
    write_to_file(writeFile, taskVector);
}

void readJSON(vector<Task> &taskVector) {
    ifstream readFile("./src/list.json");
    if (!readFile) {
        cerr << "File could not be opened, add a task to get started." << endl;
    }
    read_from_file(readFile, taskVector);
}