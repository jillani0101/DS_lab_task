//#include<iostream>
//using namespace std;
//
//struct node{
//	int data;
//	node* next; 
//	
//	
//	node(int data){
//		
//		this->data = data;
//		this->next = nullptr;
//		
//	}
//};
//
//
//class linklist{
//	node* head = nullptr;
//	
//	public:
//		void Insert at beginning(int value){// start mai node add kary ga 
//			node* n1 = new node(value);
//			n1->next = head;
//			head = n1;
//		}
//		void Insert at end(int value){ // last mai add kary ga 
//			node* n1 = new node(value); 
//			if(head ==  nullptr){
//				head = n1;
//				return;
//			}
//			node* temp = head;
//			
//			while(temp->next!=nullptr){
//				temp = temp->next;
//			}
//			temp->next = n1;
//			n1->next = nullptr;
//			temp = n1;
//				
//		}
//		
//		
//		void insert_at_any_position(int value , int pos){
//			node* n1 = new node(value);
//			node* temp = head;
//			if (head == nullptr){
//				head = n1;
//				return;
//				
//			}
//			if(pos == 1){
//				n1->next = head;
//				head = n1;
//				return;
//			}
//			
//			int counter = 1;
//			while(temp!=nullptr && counter<pos-1){
//				temp = temp->next;
//				counter++;
//			}
//			n1->next = temp->next;
//			temp->next = n1;
//			
//		}
//		void deletion(int pos){
//			
//			if(head == nullptr){
//				return;
//			}
//			if(pos == 1){
//				node* del = head;
//				head = head->next;
//				delete del;
//				return;
//			}
//			int counter = 1;
//			node* temp = head;
//			
//			while(temp->next!=nullptr && counter < pos-1){
//		
//				temp = temp->next;
//				counter++;
//		
//			}
//			node* del = temp->next;
//			temp->next = temp->next->next;
//			delete del;
//		}
//		
//		void print(){
//			node* temp = head; 
//			while(temp!=nullptr){
//				cout<<temp->data<<" ";
//				temp = temp->next;
//			}
//		}
//		
//	
//};
//int main(){
//	
//	linklist* l1 = new linklist;
//	l1->addnode(10);	
//	l1->addnode(20);
//	l1->addnode(30);
//	l1->addnode(40);
//	l1->addnode(50);
//	l1->addnode(60);
//	l1->addnode_last(100);
//	l1->addnode_last(200);
//	l1->addnode_last(300);
//	l1->addnode_last(400);
//	l1->insert_at_any_position(1000,2);
//	l1->print();
//
//	return 0;
//}


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

