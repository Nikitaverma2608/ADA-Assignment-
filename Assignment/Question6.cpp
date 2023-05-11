//Implement a quick sort algorithm for an array of integers.

/*Quick sort algorithm is a popular sorting algorithm that uses the divide-and-conquer strategy to sort an array of elements. It is a comparison-based sorting algorithm that recursively divides the input array into two smaller sub-arrays (called "partitions"), according to a chosen pivot element, such that the elements in the left sub-array are smaller than the pivot, and the elements in the right sub-array are greater than the pivot. The sub-arrays are then recursively sorted using the same procedure until the base case is reached (i.e., the sub-arrays have zero or one element), and then merged to obtain the final sorted array.

The key steps in the quick sort algorithm are:

Choose a pivot element from the array (usually the first or the last element, but can be chosen randomly or using other methods).
Partition the array into two sub-arrays, such that all elements in the left sub-array are less than or equal to the pivot, and all elements in the right sub-array are greater than the pivot.
Recursively apply steps 1-2 to the left and right sub-arrays until the base case is reached (i.e., the sub-arrays have zero or one element).
Merge the sorted sub-arrays to obtain the final sorted array.
Quick sort has an average time complexity of O(n*log n), making it one of the fastest sorting algorithms for large datasets. However, its worst-case time complexity is O(n^2) when the pivot is chosen poorly, leading to unbalanced partitions. This can be avoided by using various pivot selection methods, such as choosing the median element as the pivot or using randomized pivoting.*/

#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n-1);
    
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
The quickSort function takes an array arr, a starting index low, and an ending index high. It first checks if low is less than high, and if so, it selects a pivot index p using the partition function. It then recursively calls quickSort on the subarray to the left of p and the subarray to the right of p.

The partition function takes an array arr, a starting index low, and an ending index high. It first selects the last element of the array as the pivot. It then scans the subarray from low to high-1, moving all elements less than the pivot to the left side of the subarray and all elements greater than or equal to the pivot to the right side of the subarray. It then places the pivot in its correct position and returns its index.

The swap function takes two integer pointers and swaps their values.
*/