//you are working as a software developer for a company that manages employee record for
//payroll processing.The company requires you to sort employee salaries data sorted in two
//different formats: Array format and sort array in ascending order.
#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int salary[], int size) {
    int temp;

    // Bubble Sort logic
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (salary[j] > salary[j + 1]) {
                // Swap salaries
                temp = salary[j];
                salary[j] = salary[j + 1];
                salary[j + 1] = temp;
            }
        }
    }
}

// Function to display salary array
void displaySalaries(int salary[], int size) {
    for (int i = 0; i < size; i++) {
        cout << salary[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Array of employee salaries (at least 10 values)
    int salaries[10] = {45000, 32000, 58000, 41000, 36000,
                        50000, 29000, 62000, 47000, 39000};

    int size = 10;

    cout << "Employee Salaries Before Sorting:"<<endl;
    displaySalaries(salaries, size);

    // Sorting salaries using Bubble Sort
    bubbleSort(salaries, size);

    cout << "\nEmployee Salaries After Sorting (Ascending Order):"<<endl;
    displaySalaries(salaries, size);

    return 0;
}
