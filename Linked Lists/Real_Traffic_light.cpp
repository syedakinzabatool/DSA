//Task #07:
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

struct Intersection {
    int id;
    string currentLight;   // "Red", "Yellow", "Green"
    int redDuration;
    int yellowDuration;
    int greenDuration;
    string trafficLoad;     // "low", "medium", "high"
    Intersection* next;
    Intersection* prev;

    Intersection(int id, string light, int red, int yellow, int green, string load)
        : id(id), currentLight(light), redDuration(red), yellowDuration(yellow), greenDuration(green),
          trafficLoad(load), next(nullptr), prev(nullptr) {}
};

class TrafficSystem {
private:
    Intersection* head;

public:
    TrafficSystem() : head(nullptr) {}

    void addIntersection(int id, string light, int red, int yellow, int green, string load) {
        Intersection* newIntersection = new Intersection(id, light, red, yellow, green, load);
        if (!head) {
            head = newIntersection;
            head->next = head;
            head->prev = head;
        } else {
            Intersection* tail = head->prev;
            tail->next = newIntersection;
            newIntersection->prev = tail;
            newIntersection->next = head;
            head->prev = newIntersection;
        }
        cout << "Intersection " << id << " added.\n";
    }

    void displayStatus() {
        if (!head) {
            cout << "No intersections to display.\n";
            return;
        }

        Intersection* temp = head;
        do {
            cout << "Intersection " << temp->id << " - Light: " << temp->currentLight
                 << " (Red: " << temp->redDuration << "s, Yellow: " << temp->yellowDuration
                 << "s, Green: " << temp->greenDuration << "s), Traffic Load: " << temp->trafficLoad << "\n";
            temp = temp->next;
        } while (temp != head);
    }

    void simulateTrafficLights() {
        if (!head) {
            cout << "No intersections to manage.\n";
            return;
        }

        Intersection* current = head;
        while (true) {
            cout << "Intersection " << current->id << ": Current Light = " << current->currentLight << "\n";
            if (current->currentLight == "Green") {
                this_thread::sleep_for(chrono::seconds(current->greenDuration));
                current->currentLight = "Yellow";
            } else if (current->currentLight == "Yellow") {
                this_thread::sleep_for(chrono::seconds(current->yellowDuration));
                current->currentLight = "Red";
            } else if (current->currentLight == "Red") {
                this_thread::sleep_for(chrono::seconds(current->redDuration));
                current->currentLight = "Green";
            }
            current = current->next;
        }
    }

    void adjustLightDurations(int id, int red, int yellow, int green) {
        Intersection* temp = head;
        do {
            if (temp->id == id) {
                temp->redDuration = red;
                temp->yellowDuration = yellow;
                temp->greenDuration = green;
                cout << "Updated durations for Intersection " << id << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Intersection not found.\n";
    }

    void priorityIntersection(int id) {
        Intersection* temp = head;
        do {
            if (temp->id == id) {
                cout << "Priority mode for Intersection " << id << ". Extending green light.\n";
                temp->greenDuration += 10; // Extend green light duration
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Intersection not found.\n";
    }

    ~TrafficSystem() {
        if (head) {
            Intersection* temp = head;
            do {
                Intersection* next = temp->next;
                delete temp;
                temp = next;
            } while (temp != head);
        }
    }
};

int main() {
    TrafficSystem system;
    system.addIntersection(1, "Red", 10, 2, 15, "medium");
    system.addIntersection(2, "Red", 12, 3, 20, "high");
    system.addIntersection(3, "Red", 8, 2, 12, "low");

    system.displayStatus();

    // Simulate traffic lights in a separate thread to allow dynamic changes
    thread simulationThread(&TrafficSystem::simulateTrafficLights, &system);
    simulationThread.detach();

    // Simulate changes after some time
    this_thread::sleep_for(chrono::seconds(10));
    system.adjustLightDurations(2, 15, 4, 25);  // Adjust light duration for Intersection 2
    system.priorityIntersection(1);             // Set priority for Intersection 1

    this_thread::sleep_for(chrono::seconds(30)); // Let the simulation run for 30 seconds

    return 0;
}