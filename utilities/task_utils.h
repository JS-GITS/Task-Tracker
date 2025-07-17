#ifndef TASK_UTILS_H
#define TASK_UTILS_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;
class Tasks {
    public:
        int ID;
        string description;
        string status;
        time_t createdAt;
        time_t updatedAt;
        void add_task(int nextID, string description);
        void update_task(int ID, string description);
        void delete_task(int ID);
        void mark_progress(int ID);
        void list(string status);
};
#endif