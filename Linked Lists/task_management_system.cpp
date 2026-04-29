//Tak #04:
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
    int id;
    string name;
    string description;
    string status; // "Pending" or "Completed"
    vector<int> dependencies; // IDs of dependent tasks
    Task* prev;
    Task* next;
};

Task* taskList = nullptr;
Task* lastCompletedTask = nullptr;

Task* createTask(int id, string name, string description) {
    Task* newTask = new Task;
    newTask->id = id;
    newTask->name = name;
    newTask->description = description;
    newTask->status = "Pending";
    newTask->prev = nullptr;
    newTask->next = nullptr;
    return newTask;
}

void addTask(int id, string name, string description) {
    Task* newTask = createTask(id, name, description);
    if (taskList == nullptr) {
        taskList = newTask;
    } else {
        Task* temp = taskList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTask;
        newTask->prev = temp;
    }
    cout << "Task added: " << name << "\n";
}

void markTaskCompleted(int id) {
    Task* temp = taskList;
    while (temp != nullptr) {
        if (temp->id == id && temp->status == "Pending") {
            temp->status = "Completed";
            lastCompletedTask = temp; // Remember the last completed task
            cout << "Task marked as completed: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found or already completed.\n";
}

void undoTaskCompletion() {
    if (lastCompletedTask != nullptr) {
        lastCompletedTask->status = "Pending";
        cout << "Task marked as pending again: " << lastCompletedTask->name << "\n";
        lastCompletedTask = nullptr; // Clear last completed after undo
    } else {
        cout << "No completed task to undo.\n";
    }
}

void redoTaskCompletion(int id) {
    Task* temp = taskList;
    while (temp != nullptr) {
        if (temp->id == id && temp->status == "Pending") {
            temp->status = "Completed";
            lastCompletedTask = temp; // Remember the last completed task
            cout << "Task re-marked as completed: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found or already completed.\n";
}

void viewTasks() {
    Task* temp = taskList;
    cout << "Tasks:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Status: " << temp->status << "\n";
        if (!temp->dependencies.empty()) {
            cout << "  Dependencies: ";
            for (int dep : temp->dependencies) {
                cout << dep << " ";
            }
            cout << "\n";
        }
        temp = temp->next;
    }
}

void deleteTask(int id) {
    Task* temp = taskList;
    while (temp != nullptr) {
        if (temp->id == id) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                taskList = temp->next; // If head is deleted
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Task deleted: ID " << id << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found.\n";
}

void addDependency(int taskId, int dependencyId) {
    Task* temp = taskList;
    while (temp != nullptr) {
        if (temp->id == taskId) {
            temp->dependencies.push_back(dependencyId);
            cout << "Dependency added: Task " << dependencyId << " is now a dependency of Task " << taskId << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found.\n";
}

int main() {
    addTask(1, "Design", "Design the project architecture");
    addTask(2, "Development", "Develop the application features");
    addTask(3, "Testing", "Test the application");

    viewTasks();

    markTaskCompleted(1);
    viewTasks();

    undoTaskCompletion();
    viewTasks();

    markTaskCompleted(2);
    redoTaskCompletion(2);
    viewTasks();

    addDependency(2, 1);
    viewTasks();

    deleteTask(3);
    viewTasks();

    return 0;
}