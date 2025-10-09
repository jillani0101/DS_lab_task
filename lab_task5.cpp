#include<iostream>
using namespace std;
//1.Add Student: A new student arrives and joins the end of the queue. The system should ask for the student's name and a unique student ID (an integer).
//2.Serve Student: The student at the front of the queue receives their T-shirt and is removed from the line. The system should display the name of the student who was served. If the queue is empty, it should report that.
//3.Student Leaves: A student needs to leave the queue unexpectedly. The organizer must be able to remove a student from any position in the queue by entering their unique student ID.
//4.Display Queue: Show the current list of all students in the queue, from front to back, along with their student IDs.
//5.Count Students: Display the total number of students currently waiting in the queue.
struct student{
	string name;
	int id;
	student *next;
	
	student(string name , int id){
		this->name = name;
		this->next = nullptr;
		this->id = id;
	}
	
};

class linklist{
	public:
		student* head = nullptr;
		student* tail = nullptr;
	
	
    void insertAtEnd(string name, int id) {
    	
        student* newstudent = new student(name,id);
        if (head == nullptr) {
            head = tail = newstudent;
            return;
        }
        else{
        	tail->next = newstudent;
			tail = newstudent;
		}
    }
    
    void deleteFromBeginning() {
    	
        if (head == nullptr){
        	cout<<"list is empty"<<endl;
        	return;
		}
        student* del = head;
        head = head->next;
        delete del;
    }
    
    void deletion(int id){
    	student* temp = head;
    	if (head->id == id) {
    		
            student* del = head;
            cout << "Student name : " << del->name << "    :      id  : "<< del->id<<endl;
            head = head->next;
            if (head == nullptr){
            	tail = nullptr;
				
			}
			
			delete del;
            return;
        }
		while (temp->next != nullptr){
			
			if (temp->next->id == id){
				student* del = temp->next;
				cout << "Student name : " << del->name << "    :      id  : "<< del->id<<endl;
				temp->next = temp->next->next;
				
				if(temp->next == nullptr){
					
					tail = temp;
				}
				
				delete del;
				return;
			}
			temp = temp->next;
		}
		cout<<"Student not found  "<<endl;
		
	}
	int countStudents() {
		int count = 0;
		student* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
    }
    return count;
}

		

	
	void display(){
		student* temp = head;
		while(temp!=nullptr){
			cout<<" name : "<<temp->name<<"           :        id : "<<temp->id<<endl;
			temp = temp->next;
			
		}
	}
	
};


int main (){
	linklist q;
	string name;
	int id;
	int choice;
	while (true) {
		cout << "1. Add Student    "<<endl;
		cout<<"  2. Serve Student  "<<endl;
		cout<<"  3. Student Leaves "<<endl;
		cout<<"  5. count student  "<<endl;
		cout<<"  4. Display Queue  "<<endl; 
		cout<<"  6.    Exit        "<<endl;
		cout<<"  Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter student name: ";
			cin >> name;
			cout << "Enter student ID: ";
			cin >> id;
			q.insertAtEnd(name, id);
		}
		else if (choice == 2) {
			q.deleteFromBeginning();
		}
		else if (choice == 3) {
			cout << "Enter ID to remove: ";
			cin >> id;
			q.deletion(id);
		}
		else if (choice == 4) {
			q.display();
		}
		else if (choice == 6) {
			break;
		}
		else if (choice == 5){
			q.countStudents();
		}
		else {
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}
