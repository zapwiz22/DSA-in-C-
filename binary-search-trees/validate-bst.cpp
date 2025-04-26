#include <climits>
#include <iostream>
using namespace std;

/* 98. Validate Binary Search Tree leetcode problem solution */
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
    long long int prev = LLONG_MIN;
    bool ok = true;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (root->val <= prev) {
            ok = false;
            return;
        }
        prev = root->val;
        inorder(root->right);
    }

   public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ok;
    }
};

int main() {
}