#include "utils.h"
#include "CLI.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

/**
 * @brief Converts the current system time to a formatted string.
 * 
 * This function takes in the system clock in time_t format, and using the in-built
 * functions, convert it to a string format in Day-Month-Year Hour:Minute:Second format.
 * 
 * @return Current date and time as a string in "DD-Month-YYYY HH:MM:SS" format.
 */
string get_date() {
    auto createdDate = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm* local_tm = localtime(&createdDate);

    // Format as string
    ostringstream oss;
    oss << put_time(local_tm, "%d-%B-%Y %H:%M:%S");
    return oss.str();
}

/**
 * @brief Read the objects in the vector and print them to the file
 * 
 * This function reads all the objects in the Task vector one by one,
 * and write the object values to the file.
 * 
 * @param file Output stream to write JSON data
 * @param An empty vector of type Task to write to
 */
void write_to_file(ofstream &file,const vector<Task> &objects) {
    file << "[\n";
    for (size_t i = 0; i < objects.size(); i++) {
        // Format the output to the JSON file
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

/**
 * @brief Reads the file and converts them to Task objects and insert them to the vector
 * 
 * This function reads the JSON file line by line and find each keyword positions (e.g. id, description, status, etc.).
 * It will then create a Task object and assign all the values to all the fields,
 * after all the fields are filled, it gets pushed to the vector.
 * 
 * @param Input stream to write JSON data
 * @param Vector of Task objects to read
 */
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
            string temp = "\"id\": ";
            string idStr = line.substr(position_1 + temp.size());
            // Extract and assign the ID value
            tempTask.ID = stoi(idStr);                         
        }
        else if (position_2 != string::npos) {
            string temp = "\"description\": \"";
            string descriptionStr = line.substr(position_2 + temp.size());
            size_t end = line.find("\"",position_2 + temp.size());
            string text = descriptionStr.substr(0,end - position_2 - temp.size());
            // Extract and assign the description value
            tempTask.description = text;
        }
        else if (position_3 != string::npos) {
            string temp = "\"status\": \"";
            string statusStr = line.substr(position_3 + temp.size());
            size_t end = line.find("\"",position_3 + temp.size());
            string text = statusStr.substr(0,end - position_3 - temp.size());
            // Extract and assign the status value
            tempTask.status = text;                             
        }
        else if (position_4 != string::npos) {
            string temp = "\"createdAt\": \"";
            string createdStr = line.substr(position_4 + temp.size());
            size_t end = line.find("\"",position_4 + temp.size());
            string text = createdStr.substr(0,end - position_4 - temp.size());
            // Extract and assign the createdAt value
            tempTask.createdAt = text;                            
        }
        else if (position_5 != string::npos) {
            string temp = "\"updatedAt\": \"";
            string updatedStr = line.substr(position_5 + temp.size());
            size_t end = line.find("\"",position_5 + temp.size());
            string text = updatedStr.substr(0,end - position_5 - temp.size());
            // Extract and assign the updatedAt value
            tempTask.updatedAt = text;         
            // Insert the object towards the end of the vector     
            objects.push_back(tempTask);
        }
    }
}

/**
 * @brief Simplified way to write to the JSON file, making use of the write_to_file function
 * 
 * This function takes in the vector of Task objects and uses the function write_to_file to
 * write all the objects in the vector to the JSON file.
 * 
 * @param vector of Task objects 
 */
void writeJSON(vector<Task> &taskVector) {
    ofstream writeFile("./src/list.json");
    if (!writeFile) {
        cerr << "File could not be created or opened." << endl;
    }
    write_to_file(writeFile, taskVector);
}

/**
 * @brief Simplified way to read to the JSON file, making use of the read_to_file function
 * 
 * This function takes in the vector of Task objects and uses the function read_to_file to
 * read all values in the JSON file to fill the values to a Task object and insert them
 * to the vector of type Task objects.
 * 
 * @param vector of type Task
 */
void readJSON(vector<Task> &taskVector) {
    ifstream readFile("./src/list.json");
    if (!readFile) {
        cerr << "File could not be opened, add a task to get started." << endl;
    }
    read_from_file(readFile, taskVector);
}