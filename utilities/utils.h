#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "CLI.h"
using namespace std;
// get_date is a function that returns the current date
string get_date();
void write_to_file(ofstream &file,const vector<Task> &objects);
void read_from_file(ifstream &file, vector<Task> &objects);
#endif