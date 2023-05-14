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
    TreeNode * pA = NULL;
    TreeNode * pB = NULL;
    int calD(TreeNode * root,int x,int d,int &ans,TreeNode * parent, int fl)
    {
        if(root == NULL)
            return 0;
        if(root->val == x) {
            ans = d;
            if(fl)
                pA = parent;
            else
                pB= parent;
            return ans;
        }
        calD(root->left,x,d+1,ans,root,fl);
        calD(root->right,x,d+1,ans,root,fl);
        return ans;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* parent=root;
        int Dx = 0;
        // TreeNode * pA = root;        
        Dx = calD(root,x,0,Dx,parent,0);
        int Dy = 0;
        // TreeNode * pB = root;
        Dy = calD(root,y,0,Dy,parent,1);
        // cout<<Dx<<" "<<Dy<<endl;
        // cout<<pA->val<<" "<<pB->val<<endl;
        if(Dx == Dy && pA!=pB)
            return true;
        else
            return false;
    }
};
