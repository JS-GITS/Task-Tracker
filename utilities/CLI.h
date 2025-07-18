#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <ctime>

using namespace std;
class Task {
    public:
        int ID;
        string description;
        string status;
        string createdAt;
        string updatedAt;
        Task();
        void add_task(int nextID, string description);
        void update_task(int ID, string description, vector<Task> &taskVector);
        void delete_task(int ID, vector<Task> &taskVector);
        void mark_progress(int ID, string status, vector<Task> &taskVector);
        void list(string status, vector<Task> &taskVector);
};
#endif