 //Implement a divide-and-conquer algorithm for sorting a linked list.

/*To implement a divide-and-conquer algorithm for sorting a linked list, we can use merge sort. The merge sort algorithm can be implemented recursively as follows:

Divide the linked list into two halves.
Sort each half recursively.
Merge the two sorted halves.
*/


#include <iostream>

// Define the linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->data <= l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Split the linked list into two halves
Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;
    return mid;
}

// Sort the linked list using merge sort
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* mid = split(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}

// Print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Driver code
int main() {
    // Create a sample linked list
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Sort the linked list
    head = mergeSort(head);

    // Print the sorted linked list
    printList(head);

    return 0;
}

/*
The time complexity of this implementation is O(nlogn) because each merge operation takes O(n) time and there are logn levels of recursion. The space complexity is O(logn) because of the recursion stack.*/