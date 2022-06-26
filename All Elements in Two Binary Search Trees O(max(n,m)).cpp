// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// 1305. All Elements in Two Binary Search Trees

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
    void inorder(TreeNode * root, vector<int> &ans)
    {
        if(root==NULL)
            return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    void merge(vector<int> temp1,vector<int> temp2,vector<int> &ans)
    {
        int n = temp1.size();
        int m = temp2.size();
        
        int i=0;
        int j=0;
        
        while(i<n&&j<m)
        {
            if(temp1[i]>temp2[j])
            {
                ans.push_back(temp2[j]);
                j++;
            }
            else
            {
                ans.push_back(temp1[i]);
                i++;
            }
        }
        
        while(i<n)
        {
            ans.push_back(temp1[i]);
            i++;
        }
        
        while(j<m)
        {
            ans.push_back(temp2[j]);
            j++;
        }
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> temp1;
        vector<int> temp2;
        inorder(root1,temp1);
        inorder(root2,temp2);
        // sort(ans.begin(),ans.end());
        merge(temp1,temp2,ans);
        return ans;
    }
};
