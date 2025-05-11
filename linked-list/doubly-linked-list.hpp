#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// building doubly linked list from vector
Node* vectorToDLL(vector<int>& vec) {
    Node* head = new Node(vec[0]);
    Node* prev = head;
    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}