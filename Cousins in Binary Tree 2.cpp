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
    
    bool parent(TreeNode * root,int x,int y) {
        if(root == NULL)
            return false;
        if(root->left!=NULL && root->right !=NULL)
        {
            if(root->left->val == x && root->right->val == y)
                return true;
            if(root->left->val == y && root->right->val == x)
                return true;
        }
        return parent(root->left,x,y) || parent(root->right,x,y);
    }
    
    
    int depth(TreeNode * root,int x,int level)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->val == x)
            return level;
        int ldepth = depth(root->left,x,level+1);
        if(ldepth!=0)
            return ldepth;
        int rdepth = depth(root->right,x,level+1);
        return rdepth;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(depth(root,x,0) == depth(root,y,0) && !(parent(root,x,y)))
            return true;
        else
            return false;
    }
};
