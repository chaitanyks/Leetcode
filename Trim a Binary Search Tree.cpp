// https://leetcode.com/problems/trim-a-binary-search-tree/
// 669. Trim a Binary Search Tree

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
    
    TreeNode * search(TreeNode * root,int low,int high) {
        
        if(root==NULL)
            return root;
        
        if(root->val>=low && root->val<=high)
        {
            root->right = search(root->right,low,high);
            root->left = search(root->left,low,high);
        }
        else if(root->val>low)
            return search(root->left,low,high);
        else          
            return search(root->right,low,high);
        
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return search(root,low,high);
    }
};
