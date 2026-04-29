//Task#06:
#include <iostream>
#include <string>
using namespace std;

struct Process {
    int id;
    string name;
    int executionTime;
    int remainingTime;
    Process* next;
};

class RoundRobinScheduler {
private:
    Process* head;
    Process* tail;
    int timeQuantum;

public:
    RoundRobinScheduler(int quantum) : head(nullptr), tail(nullptr), timeQuantum(quantum) {}

    Process* createProcess(int id, string name, int executionTime) {
        Process* newProcess = new Process;
        newProcess->id = id;
        newProcess->name = name;
        newProcess->executionTime = executionTime;
        newProcess->remainingTime = executionTime;
        newProcess->next = nullptr;
        return newProcess;
    }

    void addProcess(int id, string name, int executionTime) {
        Process* newProcess = createProcess(id, name, executionTime);
        if (head == nullptr) {
            head = newProcess;
            tail = newProcess;
            tail->next = head; // Circular link
        } else {
            tail->next = newProcess;
            tail = newProcess;
            tail->next = head; // Maintain circular link
        }
        cout << "Process added: " << name << " (ID: " << id << ")\n";
    }

    void schedule() {
        if (head == nullptr) {
            cout << "No processes in the queue.\n";
            return;
        }

        Process* current = head;
        while (true) {
            if (current->remainingTime > 0) {
                int timeToExecute = min(timeQuantum, current->remainingTime);
                current->remainingTime -= timeToExecute;
                cout << "Executing Process: " << current->name << " for " << timeToExecute << " units.\n";
                if (current->remainingTime == 0) {
                    cout << "Process " << current->name << " (ID: " << current->id << ") completed.\n";
                    // Remove completed process
                    if (current == head) {
                        // Head needs to be removed
                        if (head == tail) { // Only one process
                            delete current;
                            head = nullptr;
                            tail = nullptr;
                            break;
                        }
                        tail->next = head->next;
                        Process* temp = head;
                        head = head->next;
                        delete temp;
                    } else {
                        Process* prev = head;
                        while (prev->next != current) {
                            prev = prev->next;
                        }
                        prev->next = current->next;
                        delete current;
                        current = prev->next; // Move to the next process
                        continue; // Continue the loop to skip incrementing current
                    }
                }
            }
            current = current->next; // Move to the next process
            if (current == head) {
                break; // If we have completed one full cycle
            }
        }
    }

    void displayProcesses() {
        if (head == nullptr) {
            cout << "No processes in the queue.\n";
            return;
        }

        Process* temp = head;
        cout << "Current Processes:\n";
        do {
            cout << "ID: " << temp->id << ", Name: " << temp->name
                 << ", Execution Time: " << temp->executionTime
                 << ", Remaining Time: " << temp->remainingTime << "\n";
            temp = temp->next;
        } while (temp != head);
    }

    ~RoundRobinScheduler() {
        while (head != nullptr) {
            Process* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    RoundRobinScheduler scheduler(3); // Set time quantum to 3 units

    scheduler.addProcess(1, "Process A", 10);
    scheduler.addProcess(2, "Process B", 5);
    scheduler.addProcess(3, "Process C", 8);

    cout << "\nInitial Process List:\n";
    scheduler.displayProcesses();

    cout << "\nStarting Round Robin Scheduling:\n";
    scheduler.schedule();

    return 0;
}