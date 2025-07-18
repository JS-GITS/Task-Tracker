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

void write_to_file(ofstream &file,const vector<Tasks> &objects) {
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

void read_from_file(ifstream file,const vector<Tasks> &objects) {

}