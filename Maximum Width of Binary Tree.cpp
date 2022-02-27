// Took hint from video Because i am unable to reduced the size(32 bit)
//  LastIndex = LastIndex - index;
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
    int bfs(TreeNode * root) {
        
        queue<pair<TreeNode *, long long>> q;
        q.push({root,0});
        long long ans = 1;
        
        while(!q.empty())
        {
            int n = q.size();
            TreeNode * temp = q.front().first;
            long long index = q.front().second;
            
            for(int i=0;i<n;i++)
            {
                TreeNode * end = q.front().first;
                long long LastIndex = q.front().second;
                ans = max(ans,LastIndex - index + 1);
                // cout<<LastIndex<<" "<<index<<endl;
                LastIndex = LastIndex - index;
                
                if(end->left!=NULL)
                    q.push({end->left,LastIndex*2+1});
                
                if(end->right!=NULL)
                    q.push({end->right,LastIndex*2+2});
                
                q.pop();
            }
        }
        return ans;
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return bfs(root);
    }
};
