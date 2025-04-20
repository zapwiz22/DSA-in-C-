#include <iostream>
#include <vector>
#include <stack>
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

// preorder traversal using stack
void preOrder(Node* root) {
	if (!root) return;
	stack<Node*> st;
	st.push(root);
	while (!st.empty()) {
		Node* curr = st.top();
		st.pop();
		cout << curr->data << " ";
		if (curr->right) st.push(curr->right);
		if (curr->left) st.push(curr->left);
	}
	cout << endl;
}

// inorder traversal using stack
void inOrder(Node* root) {
	Node* curr = root;
	stack<Node*> st;
	while (curr!=NULL || !st.empty()) {
		while (curr!=NULL) {
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top(); st.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}
	cout << endl;
}

// postOrder traversal usign 2 stacks
void postOrder2Stacks(Node* root) {
	if (!root) return; 

	stack<Node*> st1,st2;
	st1.push(root);
	while (!st1.empty()) {
		Node* curr = st1.top();
		st1.pop();
		st2.push(curr);
		if (curr->left) st1.push(curr->left);
		if (curr->right) st1.push(curr->right);
	}
	while (!st2.empty()) {
		Node* curr = st2.top();
		st2.pop();
		cout << curr->data << " ";
	}
	cout << endl;
}

// postorder traversal using single stack 
void postOrder(Node* root) {
	if (!root) return;

	stack<Node*> st;
	Node* curr = root;
	Node* prev = NULL;
	while (!st.empty() || curr!=NULL) {
		if (curr!=NULL) {
			st.push(curr);
			curr = curr->left;
		} else {
			Node* topMost = st.top();
			if (topMost->right!=NULL && prev!=topMost->right) {
				curr = topMost->right;
			} else {
				cout << topMost->data << " ";
				st.pop();
				prev = topMost;
			}
		}
	}
	cout << endl;
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
	root->right->right = new Node(6);

	preOrder(root);
	inOrder(root);
	postOrder2Stacks(root);
	postOrder(root);
	return 0;
}