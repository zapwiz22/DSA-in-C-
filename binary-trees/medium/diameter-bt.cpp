#include <iostream>
using namespace std;

// 543. Diameter of Binary Tree
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
	int getHeight(TreeNode* root) {
		if (!root) return 0;
		int leftHeight = getHeight(root->left);
		int rightHeight = getHeight(root->right);
    	diameter = max(leftHeight+rightHeight,diameter);
		return max(leftHeight,rightHeight)+1;
	}
public:
	int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
    	if (!root) return 0;
    	getHeight(root);
    	return diameter;
    }
};

int main() {

}