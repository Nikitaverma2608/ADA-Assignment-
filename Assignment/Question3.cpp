//Implement a selection sort algorithm for an array of integers.


/*Selection sort is a simple sorting algorithm that sorts an array by repeatedly finding the minimum (or maximum) element from the unsorted part of the array and putting it at the beginning (or end) of the sorted part of the array. The algorithm maintains two subarrays in the given array:

The sorted subarray, which is initially empty.
The unsorted subarray, which is initially the entire input array.
The algorithm works by iterating over the unsorted subarray multiple times. In each iteration, it finds the minimum (or maximum) element in the unsorted subarray and swaps it with the first element in the unsorted subarray.

Here is an example of how selection sort works on an array of integers in ascending order:

Initial array: 5 2 7 1 3

Pass 1:        1 2 7 5 3
Pass 2:        1 2 7 5 3
Pass 3:        1 2 3 5 7
Pass 4:        1 2 3 5 7

Sorted array:  1 2 3 5 7


Selection sort has a time complexity of O(n^2), where n is the size of the array. This means that the time taken to sort the array increases quadratically with the size of the array. Selection sort is not very efficient for large arrays, but it is simple to understand and implement.*/

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

/*
In this implementation, we first take the input of the number of elements in the array and the elements themselves from the user. Then, we call the bubbleSort function with the array and the number of elements as parameters. Inside the bubbleSort function, we use two nested loops to iterate through the array and compare adjacent elements. If the element on the left is greater than the element on the right, we swap them. This process is repeated for each pair of adjacent elements until the entire array is sorted. Finally, we print the sorted array.
*/