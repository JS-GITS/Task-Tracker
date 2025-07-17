#include "CLI.h"
#include "utils.h"

void Tasks::add_task(int nextID, string description) {
    this->ID = nextID;
    this->description = description;
    status = "todo";
    this->createdAt = get_date();
}