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
    int d=0;
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lcount = height(root->left);
        if(root->left!=NULL)
        {
            lcount = lcount + 1;
        }
        
        int rcount = height(root->right);
        if(root->right!=NULL)
        {
            rcount = rcount + 1;
        }
        
        d=max(lcount+rcount,d);
        return max(lcount,rcount);
    }  
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return d;
    }
};
