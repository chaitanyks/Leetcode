// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// 1022. Sum of Root To Leaf Binary Numbers

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode *root, int ans) {
        // base case
        if (root == NULL)
            return 0;

        ans = ans * 2;
        if (root -> val == 1)
            ans++;

        if (root -> left == NULL && root -> right == NULL)
            return ans;

        return solve(root -> left, ans) + solve(root -> right, ans);
    }

    int sumRootToLeaf(TreeNode*root) {
        return solve(root, 0);
    }
};
