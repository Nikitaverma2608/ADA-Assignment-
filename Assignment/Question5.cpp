//Implement a merge sort algorithm for an array of integers.

/*Merge sort is a divide-and-conquer algorithm that works by recursively dividing an input array into two halves, sorting the two halves independently, and then merging them back into a sorted whole. The steps of the algorithm are as follows:

Divide the input array into two halves, a left half and a right half.
Recursively apply merge sort to the left half and the right half.
Merge the two sorted halves into a single sorted array.
The merging step is the most important part of the algorithm. It works by comparing the first element of each half and selecting the smaller one to be added to the sorted array. The process is repeated until all elements have been added to the sorted array.

Here is an example of how merge sort works on an array of integers in ascending order:
Initial array: 5 2 7 1 3

Pass 1:        2 5   1 3 7
Pass 2:        1 2 3 5 7

Sorted array:  1 2 3 5 7

Merge sort has a time complexity of O(n log n), where n is the size of the array. This means that the time taken to sort the array increases logarithmically with the size of the array. Merge sort is an efficient sorting algorithm and is often used in practice. It is also a stable sorting algorithm, which means that it preserves the relative order of equal elements in the input array.
*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
In this implementation, we first take the input of the number of elements in the array and the elements themselves from the user. Then, we call the mergeSort function with the array, the left index (0), and the right index (n-1) as parameters. Inside the mergeSort function, we first check if the left index is greater than or equal to the right index, in which case we simply return. Otherwise, we calculate the middle index and recursively call mergeSort on the left half and the right half of the array. Finally, we call the merge function to merge the two sorted halves into a single sorted array.

The merge function takes in the array, the left index, the middle index, and the right index as parameters. It first creates two temporary arrays to store the left and right halves of the array. Then, it iterates through both arrays, comparing the current elements and merging them into a single sorted array. Finally, it copies any remaining elements from the left or right arrays into the final sorted array.

Finally, we print the sorted array.
*/