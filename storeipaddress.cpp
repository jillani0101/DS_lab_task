#include <fstream>
#include <string>
#include <sstream> // use to read and write data in string
#include<iostream>
using namespace std;


struct node{
	string data;
	node*  next;
	node*  prev;
	
	node(string value){
		data   = value;
		next   = nullptr;
		prev   = nullptr; 
		
	}
	
};
class linklist{
	public:
		node* head = nullptr;
		node* tail = nullptr;
	
	void insert_at_end(string value){
		node* newnode = new node(value);
		
		if(head == nullptr){// list empty hai
			head = tail = newnode;
		}
		else{
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode; 
		}
	}
	void display(){
		node* temp = head;
		while(temp!=nullptr){
			cout<<temp->data<<"    |   Next node address  -> "<<temp->next;
			temp=temp->next;
		}
	} 
};


int main() {
	linklist* obj1 = new linklist; 
	
	
	ifstream file("ipaddress.txt");
	if (!file.is_open()) {
		cout << "File not found!" << endl;
		return 0;
	}
	
    string line;
	while (getline(file, line)) {
		stringstream ss(line);     
		string ip;
		while (getline(ss, ip, ',')) {
			obj1->insert_at_end(ip);
    }
    obj1->display();
}

}

