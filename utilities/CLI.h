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
        static void update_task(int ID, string description, vector<Task> &taskVector);
        static void delete_task(int ID, vector<Task> &taskVector);
        static void mark_progress(int ID, string status, vector<Task> &taskVector);
        static void list(string status, const vector<Task> &taskVector);
};
#endif