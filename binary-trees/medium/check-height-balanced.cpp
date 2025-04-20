#include <iostream>
using namespace std;

/* 110. Balanced Binary Tree leetcode problem */
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
	// we check from the bottom the height of left and right node if height at any node differs then we return -1 
private:
	int bottomUpHeight(TreeNode* root) {
		if (!root) return 0;
		int leftHeight = bottomUpHeight(root->left);
		if (leftHeight==-1) return -1;
		int rightHeight = bottomUpHeight(root->right);
		if (rightHeight==-1) return -1;
		if (abs(leftHeight-rightHeight)>1) return -1;
		return max(leftHeight,rightHeight)+1;
	}
public:
    bool isBalanced(TreeNode* root) {
    	return (bottomUpHeight(root)==-1)?false:true;
    }
};

// brute force solution for checking balanced or not
int getHeight(TreeNode* root) {
	if (!root) return 0;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	return (1+max(leftHeight,rightHeight));
}

bool isBalanced(TreeNode* root) {
	if (!root) return true;

	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	if (abs(leftHeight-rightHeight)<=1 and isBalanced(root->left) and isBalanced(root->right)) {
		return true;
	} else {
		return false;
	}
}

int main() {

	return 0;
}