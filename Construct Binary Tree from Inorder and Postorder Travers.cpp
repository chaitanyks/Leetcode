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

    TreeNode *ct(vector<int> &inorder, vector<int> &postorder, int il, int ih, int pl, int ph) {
        int n = ih - il + 1;

        TreeNode *root = new TreeNode(postorder[ph]);

        int rindex;

        for (int i = ih; i >= il; i--) {
            if (inorder[i] == postorder[ph]) {
                rindex = i;
                break;
            }
        }

        int cir = ih - rindex;
        int cil = rindex - il;

        // cout<<rindex<<" "<<cir<<" "<<cil<<" "<<postorder[ph]<<endl;

        if (cir != 0) {
            root->right = ct(inorder, postorder, rindex + 1, ih, ph - cir, ph - 1);
        }
        if (cil != 0) {
            root->left = ct(inorder, postorder, il, rindex - 1, pl, ph - cir - 1);
        }

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size() - 1;
        return ct(inorder, postorder, 0, n, 0, n);
    }
};
