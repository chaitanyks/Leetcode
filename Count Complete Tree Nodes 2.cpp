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

    int lenL(TreeNode *root) {
        if (root == NULL)
            return 0;
        return 1 + lenL(root->left);
    }

    int lenR(TreeNode *root) {
        if (root == NULL)
            return 0;
        return 1 + lenR(root->right);
    }

    int solve(TreeNode *root) {
        int ll = lenL(root->left);
        int rr = lenR(root->right);
        if (ll == rr) {
            return pow(2, ll + 1) - 1;
        } else {
            int rl = lenL(root->right);
            if (rl == ll) {
                return pow(2, ll) + solve(root->right);
            } else {
                return pow(2, rr) + solve(root->left);
            }
        }
    }


    int countNodes(TreeNode *root) {
        if (root == NULL)
            return 0;

        return solve(root);
    }
};
