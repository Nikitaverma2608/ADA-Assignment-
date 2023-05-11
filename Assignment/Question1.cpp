// Implement a binary search algorithm for an array of integers.

/*Binary search is a search algorithm that works by repeatedly dividing the search interval in half. It is a very efficient algorithm for finding a specific value in a sorted list or array.

 The algorithm works by first comparing the target value to the middle element of the array. If the target value is equal to the middle element, the search is successful and the index of the middle element is returned. If the target value is less than the middle element, the search continues in the lower half of the array. If the target value is greater than the middle element, the search continues in the upper half of the array. The search interval is repeatedly divided in half until the target value is found or the search interval is empty.

 Binary search has a time complexity of O(log n), where n is the size of the array. This means that the time taken to find the target value increases logarithmically with the size of the array. Binary search is a very efficient algorithm for searching large sorted arrays.*/


#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
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
    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}


/*In this implementation, we first take the input of the number of elements in the array and the elements themselves from the user. Then, we take the input of the element to be searched. Finally, we call the binarySearch function with the array, starting index, ending index, and the element to be searched as parameters. If the element is found in the array, the function returns its index, otherwise it returns -1. We then print the appropriate message based on the value returned by the function.*/