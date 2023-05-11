//Implement a linear search algorithm for an array of integers

/*
Linear search algorithm is a simple and basic search algorithm used to find an element in a list or an array of elements. It works by traversing through the array or list sequentially from the beginning to the end and comparing each element with the target element until it finds a match. If the target element is found, it returns the index of the element; otherwise, it returns -1 to indicate that the element is not present in the list.

The time complexity of the linear search algorithm is O(n), where n is the size of the array or list. This means that in the worst-case scenario, the algorithm will have to search through all the elements in the array or list to find the target element.*/


#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    int index = linearSearch(arr, n, x);
    if (index == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << index << "." << endl;
    }
    return 0;
}


/*
This program first prompts the user to enter the size of the array and the elements of the array. It then prompts the user to enter the element to search for, and passes the array, its size, and the search element to the linearSearch function. The linearSearch function performs a linear search on the array, comparing each element with the search element until a match is found or the end of the array is reached. If the element is found, the function returns its index in the array. If the element is not found, the function returns -1. Finally, the program prints whether the element was found and its index if it was found, or a message indicating that the element was not found if it was not found.
*/