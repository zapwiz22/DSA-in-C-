#include <iostream>
#include <climits>
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

Node* ceil(Node* root,int val) {
	Node* res = root;
	Node* ans = NULL;
	int diff = INT_MAX;
	while (res!=NULL) {
		if (res->data==val) return res;
		if (res->data<val) res = res->right;
		else {
			ans = res;
			res = res->left;
		}
	}
	return ans;
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
	// root->left->right = new Node(5);
	// root->right->right = new Node(6);

	if (ceil(root,5)) {
		cout << ceil(root,5)->data << endl;
	} else {
		cout << "NULL" <<endl;
	}
	return 0;
}