#include <iostream>
#include <vector>

#include "doubly-linked-list.hpp"
using namespace std;

// class Node {
//    public:
//     int data;
//     Node* next;
//     Node* back;

//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// // building doubly linked list from vector
// Node* vectorToDLL(vector<int>& vec) {
//     Node* head = new Node(vec[0]);
//     Node* prev = head;
//     for (int i = 1; i < vec.size(); i++) {
//         Node* temp = new Node(vec[i], nullptr, prev);
//         prev->next = temp;
//         prev = temp;
//     }
//     return head;
// }

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    head = head->next;
    head->back = nullptr;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* reverseDLL(Node* head) {
    Node* temp = head;
    Node* prev = head;
    while (temp != NULL) {
        Node* nxt = temp->next;
        temp->next = temp->back;
        temp->back = nxt;
        prev = temp;
        temp = nxt;
    }
    return prev;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = vectorToDLL(arr);
    printDLL(head);
    head = insertTail(head, 6);
    printDLL(head);
    head = deleteHead(head);
    printDLL(head);
    head = deleteTail(head);
    printDLL(head);
    head = reverseDLL(head);
    printDLL(head);
    return 0;
}