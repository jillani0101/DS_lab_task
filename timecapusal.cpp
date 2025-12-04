#include <iostream>
using namespace std;

class TimeCap {
public:
    int year;
    string eventname;
    TimeCap* left;
    TimeCap* right;

    TimeCap(int data, string name) {
        year = data;
        eventname = name;
        left = nullptr;
        right = nullptr;
    }
};

TimeCap* insertEvent(TimeCap* root, int year, string eventName) {

    if (root == nullptr) {
        return new TimeCap(year, eventName);
    }

    if (year < root->year) {
        root->left = insertEvent(root->left, year, eventName);
    }
    else if (year > root->year) {
        root->right = insertEvent(root->right, year, eventName);
    }
    else {
        cout << "Paradox! Event in this year already exists.\n";
    }

    return root;
}

TimeCap* findMin(TimeCap* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TimeCap* deleteEvent(TimeCap* root, int year) {
    if (root == nullptr) {
        cout << "No event found in this year.\n";
        return nullptr;
    }

    if (year < root->year) {
        root->left = deleteEvent(root->left, year);
    }
    else if (year > root->year) {
        root->right = deleteEvent(root->right, year);
    }
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            TimeCap* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TimeCap* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        TimeCap* temp = findMin(root->right);
        root->year = temp->year;
        root->eventname = temp->eventname;

        root->right = deleteEvent(root->right, temp->year);
    }

    return root;
}

void display(TimeCap* root) {
    if (root == nullptr) return;

    display(root->left);
    cout << root->year << " - " << root->eventname << endl;
    display(root->right);
}

int main() {

    TimeCap* root = nullptr;

    root = insertEvent(root, 2000, "Y2K");
    root = insertEvent(root, 1990, "Windows Release");
    root = insertEvent(root, 2020, "COVID-19");

    cout << "\nTimeline:\n";
    display(root);

    cout << "\nDeleting year 1990...\n";
    root = deleteEvent(root, 1990);

    cout << "\nUpdated Timeline:\n";
    display(root);

    return 0;
}

