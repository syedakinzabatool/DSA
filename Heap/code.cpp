#include<iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {
        size++;
        arr[size] = value;
        int index = size;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteRoot() {
        if (size <= 0) {
            cout << "Heap is empty, cannot delete." << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;
        while (true) {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if (leftChild <= size && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    int value;
    int input[5] = {50, 55, 53, 52, 54};
    for(int i = 0; i < 5; i++) {
        value = input[i];
        h.insert(value);
    }
    h.display();
    h.deleteRoot();
    h.display();
    return 0;
}