#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node() {
        next = NULL;
    }
};

class LinkedList {
private:
    node *head;
    node* newHead;

public:
    LinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void insertAtFront(int value) {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

     
    void splitLinkedList(int val){
        node *temp = head;
         while(temp->data!=val){
            temp = temp ->next;
         }

        newHead = temp->next;
        temp->next = NULL;

    } 

    void DisplayNodes() {
        node *temp = head;
        cout << "Values in the linked list are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
     void DisplayNewNodes() {
        node *temp = newHead;
        cout << "Values in the New Split linked list are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

  
};

int main() {
    LinkedList l1;
  
    l1.insertAtFront(6);
    l1.insertAtFront(5);
    l1.insertAtFront(4);
    l1.insertAtFront(3);
    l1.insertAtFront(2);
    l1.insertAtFront(1);

    l1.DisplayNodes();
    l1.splitLinkedList(3);

    l1.DisplayNodes();
    l1.DisplayNewNodes();
    


    return 0;
}
