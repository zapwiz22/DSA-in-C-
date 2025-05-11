#include <iostream>
#include <vector>

#include "linked-list.hpp"
using namespace std;

// Node* insertHead(int val, Node* head) {
//     Node* temp = new Node(val, head);
//     return temp;
// }

// void printLL(Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// bool searchElement(int val, Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         if (temp->data == val) {
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

// int lengthLL(Node* head) {
//     Node* temp = head;
//     int cnt = 0;
//     while (temp != NULL) {
//         cnt += 1;
//         temp = temp->next;
//     }
//     return cnt;
// }

// // code to delete the tail and return the new head
// Node* deleteTail(Node* head) {
//     if (head == NULL || head->next == NULL) return NULL;
//     Node* temp = head;
//     while (temp->next->next != NULL) {
//         temp = temp->next;
//     }
//     delete temp->next;
//     temp->next = nullptr;
//     return head;
// }

// // code to delete any node present in the linked list provided the address of the node
// void deleteNode(Node* node) {
//     node->data = node->next->data;
//     node->next = node->next->next;
// }

int main() {
    // Sample array and value for insertion
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertHead(val, head);

    // Printing the linked list
    printLL(head);
    cout << searchElement(5, head) << endl;
    cout << searchElement(6, head) << endl;
    cout << lengthLL(head) << endl;
    deleteNode(head->next->next);
    printLL(head);
    head = deleteTail(head);
    printLL(head);
    return 0;
}