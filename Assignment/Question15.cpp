//Implement a heap data structure and use it to sort an array of integers.

/*Sure, here's an implementation of a heap data structure in C++ along with an example of using it to sort an array of integers:*/


#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest, n);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);

        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    void sort() {
        int n = heap.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i, n);

        for (int i = n - 1; i >= 0; i--) {
            swap(heap[0], heap[i]);
            heapify(0, i);
        }
    }

    void print() {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap h;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    cout << "Before sorting: ";
    h.print();
    h.sort();
    cout << "After sorting: ";
    h.print();
    return 0;
}

/*
This program uses a max-heap to sort an array of integers. The Heap class has two main methods: insert() to insert elements into the heap, and sort() to sort the heap using a heap sort algorithm.

In the insert() method, we add an element to the heap and then move it up the tree until it's in the correct position. This is done by swapping the element with its parent as long as the parent is smaller than the element.

In the sort() method, we first build a heap from the array by calling heapify() on each non-leaf node in the tree. We then repeatedly swap the root (which is the maximum element) with the last element in the array, decrement the size of the heap, and call heapify() on the root to maintain the heap property.

We can test the program by inputting an array of integers and observing the sorted output.*/