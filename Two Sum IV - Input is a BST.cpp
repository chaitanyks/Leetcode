
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

    bool findV(TreeNode *root, int sum, TreeNode *q) {
        if (root == NULL)
            return false;

        if (root != q && root->val == sum)
            return true;

        if (root->val > sum)
            return findV(root->left, sum, q);

        return findV(root->right, sum, q);
    }


    bool findSum(TreeNode *p, int k, TreeNode *root) {
        if (p == NULL)
            return false;


        bool check = findV(root, k - p->val, p);

        if (!check) {
            bool left = findSum(p->left, k, root);
            bool right = false;
            if (!left)
                right = findSum(p->right, k, root);
            check = left | right;
        }

        return check;
    }

    bool findTarget(TreeNode *root, int k) {
        return findSum(root, k, root);

    }
};
