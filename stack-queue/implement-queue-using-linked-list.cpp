#include <iostream>
using namespace std;

class QueueNode {
public:
  int val;
  QueueNode *next;
  QueueNode(int data) {
    val = data;
    next = nullptr;
  }
};

QueueNode *front = nullptr, *rare = nullptr;

class Queue {
public:
  int size = 0;
  bool Empty();
  void Enqueue(int val);
  void Dequeue();
  int Peek();
};

bool Queue::Empty() { return front == nullptr; }
int Queue::Peek() {
  if (Empty()) {
    cout << "Queue is empty!\n";
    return -1;
  } else {
    return front->val;
  }
}
void Queue::Enqueue(int x) {
  QueueNode *temp;
  temp = new QueueNode(x);
  if (temp == nullptr) {
    cout << "Queue is full!\n";
  } else {
    if (front == nullptr) {
      front = temp;
      rare = temp;
    } else {
      rare->next = temp;
      rare = temp;
    }
    cout << x << " inserted into queue\n";
    size++;
  }
}
void Queue::Dequeue() {
  if (front == nullptr) {
    cout << "Queue is empty!\n";
  } else {
    cout << front->val << " removed from queue" << endl;
    QueueNode *temp = front;
    front = front->next;
    delete temp;
    size--;
  }
}

int main() {
  Queue Q;
  Q.Enqueue(10);
  Q.Enqueue(20);
  Q.Enqueue(30);
  Q.Enqueue(40);
  Q.Enqueue(50);
  Q.Dequeue();
  cout << "The size of the Queue is " << Q.size << endl;
  cout << "The Peek element of the Queue is " << Q.Peek() << endl;
  return 0;
}
