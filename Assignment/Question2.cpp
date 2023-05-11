//Implement a bubble sort algorithm for an array of integers.

/*Bubble sort is a simple sorting algorithm that repeatedly steps through a list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

The algorithm works by iterating over the array multiple times. In each iteration, it compares adjacent elements and swaps them if they are in the wrong order. By the end of each iteration, the largest (or smallest, depending on the sorting order) element in the array is moved to the end (or beginning) of the array.

Initial array: 5 2 7 1 3

Pass 1:        2 5 7 1 3
Pass 2:        2 5 1 7 3
Pass 3:        2 5 1 3 7
Pass 4:        2 1 5 3 7
Pass 5:        2 1 3 5 7

Sorted array:  1 2 3 5 7

Bubble sort has a time complexity of O(n^2), where n is the size of the array. This means that the time taken to sort the array increases quadratically with the size of the array. Bubble sort is not very efficient for large arrays, but it is simple to understand and implement.*/


#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*In this implementation, we first take the input of the number of elements in the array and the elements themselves from the user. Then, we call the bubbleSort function with the array and the number of elements as parameters. Inside the bubbleSort function, we use two nested loops to iterate through the array and compare adjacent elements. If the element on the left is greater than the element on the right, we swap them. This process is repeated for each pair of adjacent elements until the entire array is sorted. Finally, we print the sorted array.*/