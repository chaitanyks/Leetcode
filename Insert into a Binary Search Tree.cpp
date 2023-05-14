// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// 701. Insert into a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* insertBST(TreeNode *root, int val) {
        
        if (root == NULL) {
            return new TreeNode(val);
        }

        if (root -> val > val) {
            root -> left = insertBST(root -> left, val);
        }

        if (root -> val < val) {
            root -> right = insertBST(root -> right, val);
        }

        return root;
    }

    TreeNode* insertIntoBST(TreeNode*root, int val) {
        return insertBST(root, val);
    }
};
