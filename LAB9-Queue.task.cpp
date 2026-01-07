//costumers submit service tickets when they need assistance.since multiple tickets can be
//submitted at the same time. the system must be process requests in the order they arrive.
//(FIFO)
#include <iostream>
using namespace std;

#define MAX 5   // Maximum number of tickets

// Queue variables
char tickets[MAX][50];
int front = -1;
int rear = -1;

// Function to add a ticket (Enqueue)
void addTicket() {
    if (rear == MAX - 1) {
        cout << "Queue is full! Cannot add more tickets."<<endl;
    } else {
        if (front == -1)
            front = 0;

        rear++;
        cout << "Enter customer ticket name: ";
        cin >> tickets[rear];
        cout << "Ticket added successfully."<<endl;
    }
}

// Function to process ticket (Dequeue)
void processTicket() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty! No ticket to process."<<endl;
    } else {
        cout << "Processing ticket: " << tickets[front] << endl;
        front++;

        if (front > rear) {   // Reset queue
            front = rear = -1;
        }
    }
}

// Function to display all tickets
void displayTickets() {
    if (front == -1) {
        cout << "No pending tickets."<<endl;
    } else {
        cout << "Pending Tickets:"<<endl;
        for (int i = front; i <= rear; i++) {
            cout << tickets[i] << endl;
        }
    }
}

// Function to cancel a ticket (Advanced)
void cancelTicket() {
    if (front == -1) {
        cout << "Queue is empty! No ticket to cancel."<<endl;
        return;
    }

    char name[50];
    cout << "Enter ticket name to cancel: ";
    cin >> name;

    int found = 0;
    for (int i = front; i <= rear; i++) {
        int j = 0;
        while (tickets[i][j] == name[j] && tickets[i][j] != '\0')
            j++;

        if (tickets[i][j] == '\0' && name[j] == '\0') {
            found = 1;
            for (int k = i; k < rear; k++) {
                // Shift tickets
                int x = 0;
                while (tickets[k + 1][x] != '\0') {
                    tickets[k][x] = tickets[k + 1][x];
                    x++;
                }
                tickets[k][x] = '\0';
            }
            rear--;
            cout << "Ticket cancelled successfully."<<endl;
            break;
        }
    }

    if (!found) {
        cout << "Ticket not found."<<endl;
    }

    if (rear < front) {
        front = rear = -1;
    }
}

// Main function with menu
int main() {
    int choice;

    do {
        cout << "\n=== Customer Service Ticket System ===\n";
        cout << "1. Add Ticket (Enqueue)"<<endl;
        cout << "2. Process Ticket (Dequeue)"<<endl;
        cout << "3. Display Tickets"<<endl;
        cout << "4. Cancel Ticket"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTicket();
                break;
            case 2:
                processTicket();
                break;
            case 3:
                displayTickets();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                cout << "Exiting system..."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 5);

    return 0;
}
