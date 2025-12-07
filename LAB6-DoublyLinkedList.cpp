//You are required to implement a menu driven C++ program using doubly linked list that supports,
//Insertion,Deletion and Display operations.
#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int semester;
    float gpa;

    Student* next;
    Student* prev;

    Student(int i, string n, int s, float g) {
        id = i;
        name = n;
        semester = s;
        gpa = g;
        next = prev =NULL;
    }
};

class DoublyLinkedList {
private:
    Student* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int id, string name, int sem, float gpa) {
        Student* newNode = new Student(id, name, sem, gpa);

        if (isEmpty()) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Student added at beginning."<<endl;
    }

    // Insert at end
    void insertAtEnd(int id, string name, int sem, float gpa) {
        Student* newNode = new Student(id, name, sem, gpa);

        if (isEmpty()) {
            head = newNode;
            cout << "Student added at end."<<endl;
            return;
        }

        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        cout << "Student added at end."<<endl;
    }

    // Insert at position
    void insertAtPosition(int pos, int id, string name, int sem, float gpa) {
        if (pos < 1) {
            cout << "Invalid position!"<<endl;
            return;
        }

        if (pos == 1) {
            insertAtBeginning(id, name, sem, gpa);
            return;
        }
        
        Student* newNode = new Student(id, name, sem, gpa);
        Student* temp = head;

        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range!"<<endl;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        cout << "Student inserted at position " << pos << ".\n"<<endl;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty!"<<endl;
            return;
        }

        Student* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;

        cout << "Deleted first record."<<endl;
    }

    // Delete from end
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty!"<<endl;
            return;
        }

        Student* temp = head;

        if (temp->next == NULL) {
            delete temp;
            head = NULL;
            cout << "Deleted last record."<<endl;
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;

        cout << "Deleted last record."<<endl;
    }

    // Delete from position
    void deleteFromPosition(int pos) {
        if (isEmpty()) {
            cout << "List is empty!"<<endl;
            return;
        }

        if (pos < 1) {
            cout << "Invalid position!"<<endl;
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Student* temp = head;

        for (int i = 1; temp != NULL && i < pos; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range!"<<endl;
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;

        cout << "Deleted record from position " << pos << ".\n"<<endl;
    }

    // Display forward
    void displayForward() {
        if (isEmpty()) {
            cout << "List is empty!"<<endl;
            return;
        }

        Student* temp = head;
        cout << "--- Student Records (Start to End) ---"<<endl;

        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Semester: " << temp->semester
                 << ", GPA: " << temp->gpa << endl;
            temp = temp->next;
        }
    }

    // Display backward
    void displayBackward() {
        if (isEmpty()) {
            cout << "List is empty!"<<endl;
            return;
        }

        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "--- Student Records (End to Start) ---"<<endl;

        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Semester: " << temp->semester
                 << ", GPA: " << temp->gpa << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, id, sem, pos;
    float gpa;
    string name;

    while (true) {
        cout << "\n===== STUDENT MANAGEMENT MENU ====="<<endl;
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete from Beginning"<<endl;
        cout << "5. Delete from End"<<endl;
        cout << "6. Delete from Position"<<endl;
        cout << "7. Display Forward"<<endl;
        cout << "8. Display Backward"<<endl;
        cout << "9. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 9) break;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name, Semester, GPA: ";
            cin >> id >> name >> sem >> gpa;
            list.insertAtBeginning(id, name, sem, gpa);
            break;

        case 2:
            cout << "Enter ID, Name, Semester, GPA: ";
            cin >> id >> name >> sem >> gpa;
            list.insertAtEnd(id, name, sem, gpa);
            break;

        case 3:
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter ID, Name, Semester, GPA: ";
            cin >> id >> name >> sem >> gpa;
            list.insertAtPosition(pos, id, name, sem, gpa);
            break;

        case 4:
            list.deleteFromBeginning();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "Enter Position: ";
            cin >> pos;
            list.deleteFromPosition(pos);
            break;

        case 7:
            list.displayForward();
            break;

        case 8:
            list.displayBackward();
            break;

        default:
            cout << "Invalid choice!"<<endl;
        }
    }

    return 0;
}
