#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> &vec) {
    int n = vec.size();
    sort(vec.begin(),vec.end());
    int freq=1;
    int ans=vec[0];
    for(int i=1;i<n;i++){
        if(vec[i]==vec[i-1]){
            freq++;
        }
        else{
            freq=1;
            ans=vec[i];
            }
            if(freq>n/2){
                return ans;
              }  }
    return ans; // Return -1 if no majority element is found
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