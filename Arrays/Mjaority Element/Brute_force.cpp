#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &vec) {
    int n = vec.size();
    for (int val : vec) {
        int freq = 0;
        for (int ele : vec) {
            if (ele == val) {
                freq++;
            }
        }
        if (freq > n / 2) {
            return val; // Return the majority element
        }
    }
    return -1; // Return -1 if no majority element is found
}

int main() {
    vector<int> vec = {1,2,1,1,2};
    int result = majorityElement(vec);
    if (result != -1) {
        cout << "The Majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }
    return 0;
}