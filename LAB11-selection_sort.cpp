//Selection sort
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {64, 25, 12, 22, 11};
    int i, j, minIndex, temp;

    for (i = 0; i < 4; i++) {
        minIndex = i;

        for (j = i + 1; j < 5; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted Array (Selection Sort): ";
    for (i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
