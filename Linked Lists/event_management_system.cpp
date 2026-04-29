// Task#01: 
#include <iostream>
#include <string>

using namespace std;

struct Participant {
    string registrationID;
    string name;
    string email;
    string status;
    Participant* next;

    Participant(string regID, string pname, string pemail, string pstatus): registrationID(regID), name(pname), email(pemail), status(pstatus), next(nullptr) {}
};

class EventManagementSystem {
private:
    Participant* registeredList;
    Participant* waitingList;
    int registeredCount;
    const int maxCapacity;

public:
    EventManagementSystem(int capacity = 50)
        : registeredList(nullptr), waitingList(nullptr), registeredCount(0), maxCapacity(capacity) {}

    void registerParticipant(string registrationID, string name, string email) {
        Participant* newParticipant = new Participant(registrationID, name, email, "Registered");

        if (registeredCount < maxCapacity) {
            // Add to registered list
            newParticipant->next = registeredList;
            registeredList = newParticipant;
            registeredCount++;
            cout << name << " has been successfully registered." << endl;
        } else {
            // Add to waiting list
            newParticipant->status = "Waiting";
            if (!waitingList) {
                waitingList = newParticipant;
            } else {
                Participant* current = waitingList;
                while (current->next) {
                    current = current->next;
                }
                current->next = newParticipant;
            }
            cout << name << " has been added to the waiting list." << endl;
        }
    }

    void cancelRegistration(string registrationID) {
        // Remove from registered list
        Participant* current = registeredList;
        Participant* prev = nullptr;

        while (current) {
            if (current->registrationID == registrationID) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    registeredList = current->next;
                }

                registeredCount--;
                cout << "Registration for " << current->name << " has been canceled." << endl;
                delete current;

                // Move the first waiting list participant to registered list
                if (waitingList) {
                    Participant* waitingParticipant = waitingList;
                    waitingList = waitingList->next;

                    waitingParticipant->status = "Registered";
                    waitingParticipant->next = registeredList;
                    registeredList = waitingParticipant;
                    registeredCount++;
                    cout << waitingParticipant->name << " has been moved from the waiting list to the registered list." << endl;
                }
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Registration ID not found." << endl;
    }

    void displayRegisteredParticipants() {
        cout << "\nRegistered Participants:" << endl;
        Participant* current = registeredList;
        if (!current) {
            cout << "No participants registered." << endl;
        } else {
            while (current) {
                cout << "ID: " << current->registrationID << ", Name: " << current->name << ", Email: " << current->email << ", Status: " << current->status << endl;
                current = current->next;
            }
        }
    }

    void displayWaitingList() {
        cout << "\nWaiting List:" << endl;
        Participant* current = waitingList;
        if (!current) {
            cout << "Waiting list is empty." << endl;
        } else {
            while (current) {
                cout << "ID: " << current->registrationID << ", Name: " << current->name << ", Email: " << current->email << ", Status: " << current->status << endl;
                current = current->next;
            }
        }
    }

    void searchByEmail(string email) {
        // Search in registered list
        Participant* current = registeredList;
        while (current) {
            if (current->email == email) {
                cout << "Participant found: ID: " << current->registrationID << ", Name: " << current->name << ", Status: " << current->status << endl;
                return;
            }
            current = current->next;
        }

        // Search in waiting list
        current = waitingList;
        while (current) {
            if (current->email == email) {
                cout << "Participant found: ID: " << current->registrationID << ", Name: " << current->name << ", Status: " << current->status << endl;
                return;
            }
            current = current->next;
        }

        cout << "Participant not found." << endl;
    }
};

int main() {
    EventManagementSystem system;

    while (true) {
        cout << "\nEvent Management System" << endl;
        cout << "1. Register a participant" << endl;
        cout << "2. Cancel a registration" << endl;
        cout << "3. Display all registered participants" << endl;
        cout << "4. Display the waiting list" << endl;
        cout << "5. Search by email" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string registrationID, name, email;
            cout << "Enter Registration ID: ";
            cin >> registrationID;
            cout << "Enter Participant Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Participant Email: ";
            cin >> email;
            system.registerParticipant(registrationID, name, email);
        } else if (choice == 2) {
            string registrationID;
            cout << "Enter Registration ID to cancel: ";
            cin >> registrationID;
            system.cancelRegistration(registrationID);
        } else if (choice == 3) {
            system.displayRegisteredParticipants();
        } else if (choice == 4) {
            system.displayWaitingList();
        } else if (choice == 5) {
            string email;
            cout << "Enter email to search: ";
            cin >> email;
            system.searchByEmail(email);
        } else if (choice == 6) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
