
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

    int count(TreeNode *root, int maxV) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;

        if (maxV <= root->val) {
            maxV = root->val;
            ans++;
        }

        return ans + count(root->left, maxV) + count(root->right, maxV);
    }

    int goodNodes(TreeNode *root) {

        if (root == NULL)
            return 0;

        return count(root, root->val);
    }
};
