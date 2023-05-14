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
    int dp[10004][2] = {0};
    map<pair<TreeNode *, bool>, int> mp;

    int findM(TreeNode *root, bool check) {
        if (root == NULL) {
            return 0;
        }
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int max4 = 0;
        int ans1 = 0;
        int ans2 = 0;

        if (check) {
            if (mp[{root->left, !check}] == 0)
                mp[{root->left, !check}] = findM(root->left, !check);

            if (mp[{root->right, !check}] == 0)
                mp[{root->right, !check}] = findM(root->right, !check);

            max1 = mp[{root->left, !check}];
            max2 = mp[{root->right, !check}];
            // max1 = findM(root->left,!check);
            // max2 = findM(root->right,!check);
            ans1 = max1 + max2;
        } else {
            // max1 = findM(root->left,check);
            // max2 = findM(root->right,check);
            if (mp[{root->left, check}] == 0)
                mp[{root->left, check}] = findM(root->left, check);

            if (mp[{root->right, check}] == 0)
                mp[{root->right, check}] = findM(root->right, check);

            max1 = mp[{root->left, check}];
            max2 = mp[{root->right, check}];
            ans1 = max1 + max2;


            if (mp[{root->left, !check}] == 0)
                mp[{root->left, !check}] = findM(root->left, !check);

            if (mp[{root->right, !check}] == 0)
                mp[{root->right, !check}] = findM(root->right, !check);

            max3 = mp[{root->left, !check}];
            max4 = mp[{root->right, !check}];
            // max3 = findM(root->left,!check);
            // max4 = findM(root->right,!check);
            ans2 = max4 + max3 + root->val;

        }

        return max(ans1, ans2);
    }

    int rob(TreeNode *root) {
        int max1 = findM(root, true);
        int max2 = findM(root, false);
        // cout<<max1<<" "<<max2<<endl;        
        return max(max1, max2);
    }
};
