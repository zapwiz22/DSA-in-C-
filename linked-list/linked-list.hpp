#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

    Node(int val, Node* nextPtr) {
        data = val;
        next = nextPtr;
    }
};

Node* insertHead(int val, Node* head) {
    Node* temp = new Node(val, head);
    return temp;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool searchElement(int val, Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int lengthLL(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt += 1;
        temp = temp->next;
    }
    return cnt;
}

// code to delete the tail and return the new head
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

// code to delete any node present in the linked list provided the address of the node
void deleteNode(Node* node) {
    node->data = node->next->data;
    node->next = node->next->next;
}

// int main() {
//     Node* head = new Node(5);
//     cout << head << endl;
//     cout << head->data << endl;
//     cout << head->next << endl;  // since nullptr
//     return 0;
// }
