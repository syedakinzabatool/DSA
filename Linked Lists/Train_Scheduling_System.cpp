//Task#05
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Train {
    string trainNumber;
    string departureTime; // Format: HH:MM
    string arrivalTime;   // Format: HH:MM
    string route;        // e.g., "CityA to CityB"
    string status;       // "On Time", "Delayed", "Cancelled"
    Train* prev;
    Train* next;
};

Train* trainList = nullptr;

Train* createTrain(string trainNumber, string departureTime, string arrivalTime, string route, string status) {
    Train* newTrain = new Train;
    newTrain->trainNumber = trainNumber;
    newTrain->departureTime = departureTime;
    newTrain->arrivalTime = arrivalTime;
    newTrain->route = route;
    newTrain->status = status;
    newTrain->prev = nullptr;
    newTrain->next = nullptr;
    return newTrain;
}

void addTrain(string trainNumber, string departureTime, string arrivalTime, string route, string status) {
    Train* newTrain = createTrain(trainNumber, departureTime, arrivalTime, route, status);
    if (trainList == nullptr) {
        trainList = newTrain;
    } else {
        Train* temp = trainList;
        while (temp->next != nullptr && temp->departureTime < departureTime) {
            temp = temp->next;
        }
        newTrain->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newTrain;
        }
        temp->next = newTrain;
        newTrain->prev = temp;
    }
    cout << "Train added: " << trainNumber << "\n";
}

void updateTrainStatus(string trainNumber, string status) {
    Train* temp = trainList;
    while (temp != nullptr) {
        if (temp->trainNumber == trainNumber) {
            temp->status = status;
            cout << "Train " << trainNumber << " status updated to: " << status << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Train not found.\n";
}

void removeTrain(string trainNumber) {
    Train* temp = trainList;
    while (temp != nullptr) {
        if (temp->trainNumber == trainNumber) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                trainList = temp->next; // If head is deleted
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Train removed: " << trainNumber << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Train not found.\n";
}

void findNextTrain() {
    time_t now = time(0);
    struct tm* currentTime = localtime(&now);
    char buffer[6];
    strftime(buffer, sizeof(buffer), "%H:%M", currentTime);
    string currentTimeStr = buffer;

    Train* temp = trainList;
    Train* nextTrain = nullptr;

    while (temp != nullptr) {
        if (temp->departureTime > currentTimeStr) {
            nextTrain = temp;
            break;
        }
        temp = temp->next;
    }

    if (nextTrain) {
        cout << "Next Train:\n";
        cout << "Train Number: " << nextTrain->trainNumber << ", Departure: " << nextTrain->departureTime
             << ", Arrival: " << nextTrain->arrivalTime << ", Route: " << nextTrain->route
             << ", Status: " << nextTrain->status << "\n";
    } else {
        cout << "No upcoming trains.\n";
    }
}

void displayTrainsForRoute(string route) {
    Train* temp = trainList;
    cout << "Trains for route: " << route << "\n";
    while (temp != nullptr) {
        if (temp->route == route) {
            cout << "Train Number: " << temp->trainNumber << ", Departure: " << temp->departureTime
                 << ", Arrival: " << temp->arrivalTime << ", Status: " << temp->status << "\n";
        }
        temp = temp->next;
    }
}

void reverseTraversal() {
    if (trainList == nullptr) {
        cout << "No trains in the schedule.\n";
        return;
    }
    Train* temp = trainList;
    while (temp->next != nullptr) {
        temp = temp->next; // Move to the end of the list
    }
    cout << "Past Departures:\n";
    while (temp != nullptr) {
        cout << "Train Number: " << temp->trainNumber << ", Departure: " << temp->departureTime
             << ", Arrival: " << temp->arrivalTime << ", Route: " << temp->route
             << ", Status: " << temp->status << "\n";
        temp = temp->prev; // Move backward
    }
}

void clearTrainSchedule() {
    while (trainList != nullptr) {
        Train* temp = trainList;
        trainList = trainList->next;
        delete temp;
    }
    cout << "Train schedule cleared.\n";
}

int main() {
    addTrain("101", "12:30", "14:30", "CityA to CityB", "On Time");
    addTrain("102", "13:00", "15:00", "CityA to CityC", "Delayed");
    addTrain("103", "11:15", "13:15", "CityB to CityD", "On Time");

    findNextTrain();
    displayTrainsForRoute("CityA to CityC");
    reverseTraversal();
    
    updateTrainStatus("101", "Cancelled");
    removeTrain("102");
    
    clearTrainSchedule();
    
    return 0;
}