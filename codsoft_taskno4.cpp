#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // clear input buffer
    getline(cin, newTask.description);
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (int i = 0; i < todoList.size(); i++) {
        cout << i + 1 << ". " << todoList[i].description;
        cout << " [" << (todoList[i].completed ? "Completed" : "Pending") << "]\n";
    }
    cout << endl;
}

void markCompleted() {
    int index;
    viewTasks();
    if (todoList.empty()) return;

    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    int index;
    viewTasks();
    if (todoList.empty()) return;

    cout << "Enter task number to remove: ";
    cin >> index;
    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    todoList.erase(todoList.begin() + index - 1);
    cout << "Task removed.\n";
}

int main() {
    int choice;
    do {
        cout << "\n==== TO-DO LIST MENU ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
