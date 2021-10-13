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
    TreeNode *newNode(TreeNode *root, vector<int> &preorder, int ind, int n) {
        int ri = ind + 1, li = ind + 1;

        while (ri < n && root->val > preorder[ri]) {
            ri++;
        }

        if (ri != n) {
            root->right = new TreeNode(preorder[ri]);
            newNode(root->right, preorder, ri, n);
        }

        if (li < n && root->val > preorder[li]) {
            root->left = new TreeNode(preorder[li]);
            newNode(root->left, preorder, li, ri);
        }
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        root = newNode(root, preorder, 0, preorder.size());
        return root;
    }
};