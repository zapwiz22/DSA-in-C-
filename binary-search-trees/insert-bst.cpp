#include <iostream>
using namespace std;

/* 701. Insert into a Binary Search Tree leetcode problem solution */
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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;
        TreeNode* p = root,*q = root;
        while (p!=NULL) {
        	q = p;
        	if (p->val < val) p=p->right;
        	else p = p->left;
        }
        if (val<q->val) q->left = newNode;
        else q->right = newNode;
        return root;
    }
};

int main() {

}