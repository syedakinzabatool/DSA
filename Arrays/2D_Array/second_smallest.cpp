#include <iostream>

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int arr[ROWS][COLS] = {{9, 5, 3}, {7, 2, 8}, {1, 4, 6}};

    int smallest = arr[0][0];
    int second_smallest = arr[0][0];

    // Find the smallest element
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            if(arr[i][j] < smallest) {
                second_smallest = smallest;
                smallest = arr[i][j];
            } else if(arr[i][j] < second_smallest && arr[i][j] != smallest) {
                second_smallest = arr[i][j];
            }
        }
    }

    std::cout << "The second smallest element in the 2D array is: " << second_smallest << std::endl;

    return 0;
}
