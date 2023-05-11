//Implement an insertion sort algorithm for an array of integers.

/*Insertion sort is a simple sorting algorithm that sorts an array by building a sorted subarray one element at a time. The algorithm maintains two subarrays in the given array:

The sorted subarray, which is initially the first element of the array.
The unsorted subarray, which is initially the remaining elements of the array.
The algorithm works by iterating over the unsorted subarray, and for each element, it compares it with the elements in the sorted subarray from right to left, shifting elements in the sorted subarray to the right until it finds the correct position to insert the current element.

Here is an example of how insertion sort works on an array of integers in ascending order:
Initial array: 5 2 7 1 3

Pass 1:        2 5 7 1 3
Pass 2:        2 5 7 1 3
Pass 3:        1 2 5 7 3
Pass 4:        1 2 3 5 7

Sorted array:  1 2 3 5 7
Insertion sort has a time complexity of O(n^2), where n is the size of the array. This means that the time taken to sort the array increases quadratically with the size of the array. However, insertion sort is efficient for small arrays and is often used in practice for small inputs or as a subroutine in more complex sorting algorithms.*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


/*In this implementation, we first take the input of the number of elements in the array and the elements themselves from the user. Then, we call the insertionSort function with the array and the number of elements as parameters. Inside the insertionSort function, we use a loop to iterate through the array and compare the current element with the previous elements. If the current element is smaller than the previous element, we shift the previous element to the right and insert the current element in its correct position. This process is repeated for each element until the entire array is sorted. Finally, we print the sorted array.*/