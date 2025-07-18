#include "CLI.h"
#include "utils.h"

Tasks::Tasks() {
    this->ID = -1;
    this->description = "";
    this->status = "";
    this->createdAt = "";
    this->updatedAt = "";
}

void Tasks::add_task(int nextID, string description) {
    this->ID = nextID;
    this->description = description;
    status = "todo";
    this->createdAt = get_date();
}

void update_task(int ID, string description, vector<Tasks> taskVector) {

}