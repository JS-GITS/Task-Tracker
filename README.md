# Task-Tracker
### Project idea from https://roadmap.sh/projects/task-tracker
[![](./assets/preview.gif)](https://roadmap.sh/projects/task-tracker)

Clone the repository and run the following command:
```bash
git clone https://github.com/JS-GITS/Task-Tracker.git
cd ./Task-Tracker
make
```


Run the following commands to use the script:
```bash
Adding a new task
./main add "Buy groceries"

# Updating tasks
./main update 1 "Buy groceries and cook dinner"

# Deleting tasks
./main delete 1

# Marking a task as todo, in progress, or done
./main mark-todo 1
./main mark-in-progress 1
./main mark-done 1

# Listing all tasks
./main list
./main list done
./main list todo
./main list in-progress
```
## Requirements
The application should run from the command line, accept user actions and inputs as arguments, and store the tasks in a JSON file. The user should be able to:
1. Add, Update, and Delete tasks
2. Mark a task as in progress or done
3. List all tasks
4. List all tasks that are done
5. List all tasks that are not done
6. List all tasks that are in progress
