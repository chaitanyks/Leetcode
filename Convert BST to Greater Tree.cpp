// https://leetcode.com/problems/convert-bst-to-greater-tree/
// 538. Convert BST to Greater Tree

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
    void inOrder(TreeNode * root,int &sum)
    {
       if(!root)
           return ;
        inOrder(root->right, sum);
        root->val += sum;
        sum = root->val;
        inOrder(root->left, sum); 
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inOrder(root,sum);
        return root;
    }
};
