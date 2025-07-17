#ifndef CLI_H
#define CLI_H

#include <string>
#include <ctime>

using namespace std;
class Tasks {
    public:
        int ID;
        string description;
        string status;
        string createdAt;
        string updatedAt;
        void add_task(int nextID, string description);
        void update_task(int ID, string description);
        void delete_task(int ID);
        void mark_progress(int ID);
        void list(string status);
};
#endif