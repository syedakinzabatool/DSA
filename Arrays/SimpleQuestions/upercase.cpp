#include <iostream>
using namespace std;
int main() {
    const int MAX_SIZE = 100; // Maximum size for the character array

    char inputString[MAX_SIZE]; // Character array to store the string

    // Prompt user for input
    cout << "Enter a string: ";
    cin.getline(inputString, MAX_SIZE);

    // Convert each character to uppercase
    for (int i = 0; inputString[i] != '\0'; ++i) {
        if (inputString[i] >= 'a' && inputString[i] <= 'z') {
            // Convert lowercase to uppercase
            inputString[i] = inputString[i] - 'a' + 'A';
        }
    }

    // Output the string in uppercase
    cout << "String in uppercase: " << inputString << endl;
    return 0;
}
