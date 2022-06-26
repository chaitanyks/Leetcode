
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

    int maxH(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left = maxH(root->left);
        int right = maxH(root->right);

        return 1 + max(left, right);
    }

    queue<TreeNode *> bfs(TreeNode *root, int h) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        queue<TreeNode *> nodes;
        while (!q.empty()) {
            TreeNode *temp = q.front().first;
            int tempH = q.front().second;
            q.pop();
            if (tempH == h)
                nodes.push(temp);
            if (temp->left != NULL)
                q.push({temp->left, 1 + tempH});
            if (temp->right != NULL)
                q.push({temp->right, 1 + tempH});
        }
        return nodes;

    }

    TreeNode *lcm(TreeNode *root, TreeNode *a, TreeNode *b) {
        if (root == NULL || root == a || root == b)
            return root;
        TreeNode *left = lcm(root->left, a, b);
        TreeNode *right = lcm(root->right, a, b);
        if (left != NULL && right != NULL)
            return root;
        if (left != NULL)
            return left;
        return right;
    }


    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        // return root;
        int height = maxH(root);
        cout << height;
        queue<TreeNode *> nodes;
        nodes = bfs(root, height);

        TreeNode *ans = root;
        while (!nodes.empty()) {
            if (nodes.size() == 1) {
                ans = nodes.front();
                nodes.pop();
                break;
            }

            TreeNode *a = nodes.front();
            nodes.pop();
            TreeNode *b = nodes.front();
            nodes.pop();
            TreeNode *ancestor = lcm(root, a, b);
            nodes.push(ancestor);
        }

        return ans;
    }
};
