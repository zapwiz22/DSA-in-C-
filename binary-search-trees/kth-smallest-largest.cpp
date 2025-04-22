#include <iostream>
using namespace std;

/* 230. Kth Smallest Element in a BST leetcode problem solution */
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
    int k = 0;
    int ans = -1;
private:
    void inorder(TreeNode* root,int target) {
        if (!root) return;
        inorder(root->left,target);
        k++;
        if (k==target) {
            ans = root->val;
            return;
        }
        inorder(root->right,target);
    }
/** 
	* For finding the kth largest element in the bst use the below function instead of inorder

    * void reverseInorder(TreeNode* root,int target) {
    	if (!root) return;
     	reverseInorder(root->right,target);
     	k++;
     	if (k==target) {
			ans = root->val;
			return;
     	}
     	reverseInorder(root->left,target);
    * }
*/
    
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};

int main() {

}