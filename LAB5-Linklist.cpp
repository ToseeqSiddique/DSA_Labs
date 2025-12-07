//Write a c++ program using singly link list where each patient has patient ID,
//Insert a new patient at the end, at beginning and Display all patients.
#include <iostream>
using namespace std;

// Structure for a node (patient)
struct Node {
int patientID;
Node* next;
};

// Function to create a new node
Node* createNode(int id) {
Node* newNode = new Node;
newNode->patientID = id;
newNode->next =NULL;
return newNode;
}

// Function to insert a node at the end (regular check-in)
void insertAtEnd(Node*& head, int id) {
Node* newNode = createNode(id);
if (head == NULL) {
head = newNode;
} else {
Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
cout << "Patient " << id << " added at the end."<<endl;
}

// Function to insert a node at the beginning (emergency)
void insertAtBeginning(Node*& head, int id) {
Node* newNode = createNode(id);
newNode->next = head;
head = newNode;
cout << "Patient " << id << " added at the beginning."<<endl;
}

// Function to display all nodes (patients)
void displayPatients(Node* head) {
if (head == NULL) {
cout << "No patients currently."<<endl;
return;
}
cout << "Current Patients: ";
Node* temp = head;
while (temp != NULL) {
cout << temp->patientID << " ";
temp = temp->next;
}
cout << endl;
}

// Main function
int main() {
Node* head = NULL; // Start with an empty list
int choice, id;

do {  
    cout << "--- Hospital Patient Management ---"<<endl;  
    cout << "1. Add patient at end "<<endl;  
    cout << "2. Add patient at beginning (emergency)"<<endl;  
    cout << "3. Display all patients"<<endl;
    cout << "4. Exit"<<endl;  
    cout << "Enter your choice: ";  
    cin >> choice;  

    switch(choice) {  
        case 1:  
            cout << "Enter Patient ID: ";  
            cin >> id;  
            insertAtEnd(head, id);  
            break;  
        case 2:  
            cout << "Enter Patient ID: ";  
            cin >> id;  
            insertAtBeginning(head, id);  
            break;  
        case 3:  
            displayPatients(head);  
            break;  
        case 4:  
            cout << "Exiting program."<<endl;  
            break;  
        default:  
            cout << "Invalid choice! Try again:"<<endl;  
    }  
} while(choice != 4);  

return 0;

}
