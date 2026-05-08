#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node() {
        next = NULL;
    }
};

class LinkedList {
    private:
        node* head;

    public:
        int count = 0;
        
        LinkedList() {
            head = NULL;
        }

        bool isEmpty() {
            return (head == NULL);
        }

        void insert_at_front(int value) {
            node* new_node = new node;
            new_node->data = value;
            new_node->next = head;
            head = new_node;
            count++;
        }

        void insert_at_end(int value) {
            node* new_node = new node;
            new_node->data = value;

            if (isEmpty()) {
                head = new_node;
            } else {
                node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_node;
            }
            count++;
        }

        int remove_from_front() {
            if (isEmpty()) {
                return -1;
            }
            int value = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return value;
        }

        int remove_from_end() {
            if (isEmpty()) {
                return -1;
            }

            if (head->next == NULL) {
                int value = head->data;
                delete head;
                head = NULL;
                count--;
                return value;
            }

            node* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }

            int value = current->next->data;
            delete current->next;
            current->next = NULL;
            count--;
            return value;
        }

        void display() {
            if (isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }

            node* current = head;
            while (current != NULL) {
                cout << "Value: " << current->data << endl;
                current = current->next;
            }
        }

        void search_value(int value) {
            if (isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }

            node* current = head;
            bool found = false;
            while (current != NULL) {
                if (current->data == value) {
                    cout << "Value " << value << " found in the list." << endl;
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                cout << "Value " << value << " not found in the list." << endl;
            }
        }

        void get_count() {
            cout << "Total number of nodes: " << count << endl;
        }

        void search_del(int value) {
            if (isEmpty()) {
                cout << "List is empty. Cannot delete." << endl;
                return;
            }

            node* current = head;
            node* previous = NULL;

            if (head->data == value) {
                node* temp = head;
                head = head->next;
                delete temp;
                count--;
                cout << "Value " << value << " deleted from the list." << endl;
                return;
            }

            while (current != NULL && current->data != value) {
                previous = current;
                current = current->next;
            }

            if (current == NULL) {
                cout << "Value " << value << " not found in the list." << endl;
                return;
            }

            previous->next = current->next;
            delete current;
            count--;
            cout << "Value " << value << " deleted from the list." << endl;
        }

        void middle_value() {
            if (isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }

            node* slow = head;
            node* fast = head;

            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            cout << "The middle value is: " << slow->data << endl;
        }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Insert a value at the front" << endl;
        cout << "2. Insert a value at the end" << endl;
        cout << "3. Remove a value from the front" << endl;
        cout << "4. Remove a value from the end" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Get total number of nodes" << endl;
        cout << "7. Search for a value" << endl;
        cout << "8. Remove a value" << endl;
        cout << "9. Find middle value" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                list.insert_at_front(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insert_at_end(value);
                break;
            case 3:
                value = list.remove_from_front();
                if (value != -1)
                    cout << "Removed value: " << value << endl;
                else
                    cout << "List is empty. No value removed." << endl;
                break;
            case 4:
                value = list.remove_from_end();
                if (value != -1)
                    cout << "Removed value: " << value << endl;
                else
                    cout << "List is empty. No value removed." << endl;
                break;
            case 5:
                cout << "Displaying list:" << endl;
                list.display();
                break;
            case 6:
                cout << "Counting nodes:" << endl;
                list.get_count();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search_value(value);  
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                list.search_del(value);
                break;
            case 9:
                list.middle_value();
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}