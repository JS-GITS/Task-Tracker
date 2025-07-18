#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "CLI.h"
using namespace std;
string get_date();                                                      // Returns the date in DD:m:YY-H:M:S format
void write_to_file(ofstream &file,const vector<Task> &objects);         // Takes the output file stream and writes the tasks from the vector to the file 
void read_from_file(ifstream &file, vector<Task> &objects);             // Reads the input file stream and assign the variables to a task and put them in a vector
void writeJSON(vector<Task> &taskVector);                               // Just faster function to execute writing to a file
void readJSON(vector<Task> &taskVector);                                // Just faster function to execute reading from a file
#endif