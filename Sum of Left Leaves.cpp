class Solution {
public:
    int ans = 0;

    int dfs(TreeNode *root) {
        if (root == NULL)
            return 0;


        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            // cout<<root->val<<" ";
            return root->left->val + dfs(root->right);
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        return (left + right);

    }

    int sumOfLeftLeaves(TreeNode *root) {
        return dfs(root);

    }
};
