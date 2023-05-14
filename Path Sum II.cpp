// https://leetcode.com/problems/path-sum-ii/
// 113. Path Sum II

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
    vector<vector<int>> ans;
    int ts;
    void inorder(TreeNode * root, vector<int> &tans,int sum)
    {
        if(root == NULL)
            return ;
        tans.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==ts)
            {
                ans.push_back(tans);
            }
            tans.pop_back();
            return ;
        }       
        
        inorder(root->left,tans,sum+root->val);
        inorder(root->right,tans,sum+root->val);
        tans.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ts = targetSum;
        vector<int> temp;
        inorder(root,temp,0);
        return ans;
    }
};
