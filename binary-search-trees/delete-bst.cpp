#include <iostream>
using namespace std;

/* 450. Delete Node in a BST leetcode problem solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
	TreeNode* successor(TreeNode* root) {
		TreeNode* p = root;
		while (p->left!=NULL) {
			p = p->left;
		}
		return p;
	}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val < key) {
        	root->right = deleteNode(root->right,key);
        } else if (root->val > key) {
        	root->left = deleteNode(root->left,key);
        } else {
        	if(root->left==NULL && root->right==NULL) {
        		return NULL;
        	} else if (root->left == NULL) {
        		return root->right;
        	} else if (root->right == NULL) {
        		return root->left;
        	} else {
        		TreeNode* succ = successor(root->right);
        		root->val = succ->val;
        		root->right = deleteNode(root->right,succ->val);
        	}
        }
        return root;
    }
};

int main() {

}