#include "task_utils.h"

void Tasks::add_task(int nextID, string description) {
    this->ID = nextID;
    strcpy(this->description,description);
    status = ""
}