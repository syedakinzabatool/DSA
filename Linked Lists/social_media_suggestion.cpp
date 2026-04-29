//Task#02:
#include <iostream>
#include <string>
using namespace std;

struct UserProfile {
    int userID;
    string name;
    int mutualFriends;
    string status;  // "Suggested" or "Not Suggested"
    UserProfile* next;
};

UserProfile* profileList = nullptr;

// Create a new user profile
UserProfile* createProfile(int id, string name, int mutualFriends, string status) {
    UserProfile* newProfile = new UserProfile;
    newProfile->userID = id;
    newProfile->name = name;
    newProfile->mutualFriends = mutualFriends;
    newProfile->status = status;
    newProfile->next = nullptr;
    return newProfile;
}

// Add a new user profile
void addProfile(int id, string name, int mutualFriends) {
    UserProfile* newProfile = createProfile(id, name, mutualFriends, "Suggested");
    if (profileList == nullptr) {
        profileList = newProfile;
    } else {
        UserProfile* temp = profileList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newProfile;
    }
    cout << "Profile added: " << name << "\n";
}

// Display all suggested friends
void displaySuggestions() {
    UserProfile* temp = profileList;
    cout << "Friend Suggestions:\n";
    while (temp != nullptr) {
        if (temp->status == "Suggested") {
            cout << "ID: " << temp->userID << ", Name: " << temp->name << ", Mutual Friends: " << temp->mutualFriends << "\n";
        }
        temp = temp->next;
    }
}

// Mark a user as "Not Suggested" after adding as a friend
void addAsFriend(int id) {
    UserProfile* temp = profileList;
    while (temp != nullptr) {
        if (temp->userID == id && temp->status == "Suggested") {
            temp->status = "Not Suggested";
            cout << "Added as friend: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Profile not found or already added as friend.\n";
}

// Display top N profiles with the most mutual friends
void displayTopSuggestions(int n) {
    UserProfile* temp = profileList;
    for (int i = 0; i < n && temp != nullptr; ++i) {
        int maxFriends = -1;
        UserProfile* maxProfile = nullptr;
        UserProfile* maxPrev = nullptr;
        UserProfile* prev = nullptr;
        temp = profileList;
        
        while (temp != nullptr) {
            if (temp->mutualFriends > maxFriends && temp->status == "Suggested") {
                maxFriends = temp->mutualFriends;
                maxProfile = temp;
                maxPrev = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        if (maxProfile != nullptr) {
            cout << "ID: " << maxProfile->userID << ", Name: " << maxProfile->name << ", Mutual Friends: " << maxProfile->mutualFriends << "\n";
            if (maxPrev != nullptr) {
                maxPrev->next = maxProfile->next;
            } else {
                profileList = maxProfile->next;
            }
            delete maxProfile; // Remove from list
        }
    }
}

// Remove a profile by User ID
void removeProfile(int id) {
    UserProfile* prev = nullptr;
    UserProfile* temp = profileList;
    
    while (temp != nullptr && temp->userID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Profile not found.\n";
        return;
    }

    if (prev == nullptr) {
        profileList = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Profile removed.\n";
}

// Update the number of mutual friends for a specific profile
void updateMutualFriends(int id, int newMutualFriends) {
    UserProfile* temp = profileList;
    while (temp != nullptr) {
        if (temp->userID == id) {
            temp->mutualFriends = newMutualFriends;
            cout << "Updated mutual friends for " << temp->name << " to " << newMutualFriends << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Profile not found.\n";
}

int main() {
    addProfile(1, "Alice", 10);
    addProfile(2, "Bob", 5);
    addProfile(3, "Charlie", 15);
    
    displaySuggestions();
    addAsFriend(2);
    displaySuggestions();
    
    displayTopSuggestions(2);
    
    updateMutualFriends(3, 20);
    removeProfile(1);
    displaySuggestions();

    return 0;
}