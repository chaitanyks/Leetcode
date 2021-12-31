// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/submissions/

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

    int solve(TreeNode *root, TreeNode *MinAn, TreeNode *MaxAn) {
        if (root == NULL)
            return 0;

        if (MinAn == NULL)
            MinAn = root;

        if (MaxAn == NULL)
            MaxAn = root;

        int diff = max(abs(root->val - MinAn->val), abs(root->val - MaxAn->val));
        // cout<<diff<<" ";
        if (root->val > MaxAn->val) {
            MaxAn = root;
        }

        if (root->val < MinAn->val) {
            MinAn = root;
        }

        int left = solve(root->left, MinAn, MaxAn);
        int right = solve(root->right, MinAn, MaxAn);

        return max(diff, max(left, right));
    }

    int maxAncestorDiff(TreeNode *root) {
        return solve(root, NULL, NULL);
    }
};
