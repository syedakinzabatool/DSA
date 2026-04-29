//Task #03
#include <iostream>
#include <string>
using namespace std;

struct WebPage {
    string url;
    string title;
    string timestamp;
    WebPage* prev;
    WebPage* next;
};

WebPage* currentPage = nullptr;

WebPage* createPage(string url, string title, string timestamp) {
    WebPage* newPage = new WebPage;
    newPage->url = url;
    newPage->title = title;
    newPage->timestamp = timestamp;
    newPage->prev = nullptr;
    newPage->next = nullptr;
    return newPage;
}

void visitPage(string url, string title, string timestamp) {
    WebPage* newPage = createPage(url, title, timestamp);
    if (currentPage != nullptr) {
        currentPage->next = newPage;
        newPage->prev = currentPage;
    }
    currentPage = newPage;
    cout << "Visited: " << title << "\n";
}

void goBack() {
    if (currentPage != nullptr && currentPage->prev != nullptr) {
        currentPage = currentPage->prev;
        cout << "Back to: " << currentPage->title << "\n";
    } else {
        cout << "No previous page.\n";
    }
}

void goForward() {
    if (currentPage != nullptr && currentPage->next != nullptr) {
        currentPage = currentPage->next;
        cout << "Forward to: " << currentPage->title << "\n";
    } else {
        cout << "No forward page.\n";
    }
}

void viewHistory() {
    if (currentPage == nullptr) {
        cout << "No history.\n";
        return;
    }
    
    WebPage* temp = currentPage;
    cout << "Browsing History:\n";
    while (temp != nullptr) {
        cout << "Title: " << temp->title << ", URL: " << temp->url << ", Timestamp: " << temp->timestamp << "\n";
        temp = temp->prev;
    }
}

void deletePage(string url) {
    WebPage* temp = currentPage;
    while (temp != nullptr) {
        if (temp->url == url) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            if (temp == currentPage) {
                currentPage = temp->prev;  // Move current page back if needed
            }
            delete temp;
            cout << "Deleted page: " << url << "\n";
            return;
        }
        temp = temp->prev;
    }
    cout << "Page not found in history.\n";
}

void clearHistory() {
    while (currentPage != nullptr) {
        WebPage* temp = currentPage;
        currentPage = currentPage->prev;
        delete temp;
    }
    cout << "History cleared.\n";
}

int main() {
    visitPage("https://example.com", "Example", "2024-10-09 12:00");
    visitPage("https://openai.com", "OpenAI", "2024-10-09 12:05");
    visitPage("https://github.com", "GitHub", "2024-10-09 12:10");

    viewHistory();
    
    goBack();
    goBack();
    goForward();
    
    deletePage("https://openai.com");
    viewHistory();

    clearHistory();
    viewHistory();

    return 0;
}