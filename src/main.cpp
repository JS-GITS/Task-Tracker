#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Tasks {
    public:
        int id;
        string description;
        string status;
        time_t createdAt;
        time_t updatedAt;
        void add_task(string description);
        void update_task(int id, string description);
        void delete_task(int id);
        void mark_progress(int id);
        void list(string status);
};

int main(int argc, char* argv[]) {
    string user_input = argv[1];
    if (argc < 2) {
        cout << "Usage: ./task-cli <input>" << endl;
        return 1;
    }
    if (user_input == "cool") {
        cout << "WOW" << endl;
    }
    return 0;
}