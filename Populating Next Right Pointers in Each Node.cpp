/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node *root) {
        queue<pair<Node *, int>> q;
        q.push({root, 1});
        int level = 1;
        Node *last = NULL;
        while (!q.empty()) {
            Node *top = q.front().first;
            int l = q.front().second;
            q.pop();
            if (l == level) {
                if (last == NULL)
                    last = top;
                else {
                    last->next = top;
                    last = top;
                }
            } else {
                last->next = NULL;
                last = top;
                level = l;
            }

            if (top->left != NULL)
                q.push({top->left, 1 + l});
            if (top->right != NULL)
                q.push({top->right, 1 + l});

        }
    }


    Node *connect(Node *root) {
        if (root == NULL)
            return root;

        bfs(root);
        return root;
    }
};
