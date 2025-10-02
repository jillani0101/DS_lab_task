


#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head = nullptr;

public:
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);
        if (head == nullptr || pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        int counter = 1;
        while (temp != nullptr && counter < pos - 1) {
            temp = temp->next;
            counter++;
        }
        if (temp == nullptr) return; // position out of bounds
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* del = head;
        head = head->next;
        delete del;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l1;
    // phely 3 bnde last mai 
    
    l1.insertAtEnd(101);
    l1.insertAtEnd(102);
    l1.insertAtEnd(103);
    
    cout<<"3 passenger at the end normal  boarding: "<<endl;
    l1.print();
    cout<<endl;
    
    //  phir 1 start mai
    l1.insertAtBeginning(201);
    
    cout<<"1 passenger at the start  emergency   hai : "<<endl;
    l1.print();
     cout<<endl;
     
     
    l1.insertAtPosition(301, 2);
    cout<<"1 passenger at any position special : "<<endl;
    cout << "Current list : "<<endl;
    l1.print();
    cout<<endl;

    l1.deleteFromBeginning();
    cout<<"phela passenger delete : "<<endl;
    

    cout << "After delete : ";
    l1.print();

    return 0;
}


