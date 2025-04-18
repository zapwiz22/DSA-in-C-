#include <iostream>
#include <vector>
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

/* preOrder traversal for binary trees */
void preOrder(Node* root) {
	if (root==NULL) return;	
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

/* inOrder traversal for binary trees */
void inOrder(Node* root) {
	if (root==NULL) return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

/* postOrder traversal for binary trees */
void postOrder(Node* root) {
	if (root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}


int main() {
	Node* root = new Node(5);
	cout << root->data << endl << root->left << endl << root->right << endl;
	return 0;
}