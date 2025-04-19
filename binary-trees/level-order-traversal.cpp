#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
	Node(int x,Node* left,Node* right) {
		data = x;
		left = left;
		right = right;
	}
};

void levelOrderTraversal(Node* root) {
	if (!root) return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		Node* curr = q.front();
		q.pop();
		if (curr==NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << curr->data << " ";
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
	}
}

int main() {
		// Sample tree:
	//     1
	//    / \
	//   2   3
	//  / \   \
	// 4   5   6

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	// root->right->right = new Node(6);

	levelOrderTraversal(root);
	return 0;
}