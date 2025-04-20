#include <iostream>
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

int minBST(Node* root) {
	if (!root) return -1;
	int mne = root->data;
	Node* p = root;
	while (p->left!=NULL) {
		mne = min(mne,p->data);
		p = p->left;
	}
	return mne;
}

int maxBST(Node* root) {
	if (!root) return -1;
	int mxe = root->data;
	Node* p = root;
	while (p->right != NULL) {
		mxe = max(p->data,mxe);
		p = p->right;
	}
	return mxe;
}

int main() {

	return 0;
}