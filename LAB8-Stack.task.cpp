//Implement a stack-based system where books are added and removed in LIFO manner.The
//program allow users to dynamically add,remove and view books.
#include <iostream>
using namespace std;

#define MAX 5

//char array for book names
char books[MAX][50];
int top = -1;

// Push a book into stack
void pushBook() {
    if (top == MAX - 1) {
        cout << "Stack is full! Cannot add more books."<<endl;
    } else {
        top++;
        cout << "Enter book name: ";
        cin >> books[top];   // simple input (no spaces)
        cout << "Book added successfully."<<endl;
    }
}

// Pop a book from stack
void popBook() {
    if (top == -1) {
        cout << "Stack is empty! No book to remove."<<endl;
    } else {
        cout << "Book removed: " << books[top] << endl;
        top--;
    }
}

// Peek top book
void peekBook() {
    if (top == -1) {
        cout << "Stack is empty! No book to view."<<endl;
    } else {
        cout << "Top book: " << books[top] << endl;
    }
}

// Display all books
void displayBooks() {
    if (top == -1) {
        cout << "No books in stack."<<endl;
    } else {
        cout << "Books in stack (Top to Bottom):"<<endl;
        for (int i = top; i >= 0; i--) {
            cout << books[i] << endl;
        }
    }
}

// Main function with menu
int main() {
    int choice;

    do {
        cout << "\n=== Library Stack Menu ===\n";
        cout << "1. Add Book (Push)"<<endl;
        cout << "2. Remove Book (Pop)"<<endl;
        cout << "3. View Top Book (Peek)"<<endl;
        cout << "4. Display All Books"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pushBook();
                break;
            case 2:
                popBook();
                break;
            case 3:
                peekBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                cout << "Exiting program..."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 5);

    return 0;
}
