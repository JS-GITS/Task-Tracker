#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <ctime>

// Header class Task to contain all the info on a task
using namespace std;
/**
 * @class Task
 * @brief Represents a single task containing various information
 *
 * The Task class holds information about a task such as its ID,
 * description, status, creation date, updated date, and provides methods to manipulate the task.
 * It supports adding, updating, deleting tasks; as well as marking progress, and listing tasks.
 *
 * Usage:
 * Task newTask;
 *
 * @author Justin
 * @version 1.0
 * @date 19-7-2025
 */
class Task {
    public:
        size_t ID;              // Unique Identifier for each task
        string description;     // Description of the task
        string status;          // Current status ("todo", "in-progress", "done")
        string createdAt;       // Task creation date
        string updatedAt;       // Task last updated date
        Task();
        void add_task(size_t nextID, string &description);
        static void update_task(size_t ID, string &description, vector<Task> &taskVector);
        static void delete_task(size_t ID, vector<Task> &taskVector);
        static void mark_progress(size_t ID, string &status, vector<Task> &taskVector);
        static void list(const vector<Task> &taskVector);
        static void list(string &status, const vector<Task> &taskVector);
};
#endif