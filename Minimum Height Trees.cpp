class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> adj(n + 1);
        int e = edges.size();
        vector<int> visited(n + 1, false);

        for (int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                q.push(i);
            }
        }

        int remain = n;
        while (remain > 2) {
            int len = q.size();
            remain = remain - len;
            //check leaf in queue
            for (int i = 0; i < len; i++) {
                int index = q.front();
                // travers all node in adj
                for (int j = 0; j < adj[index].size(); j++) {
                    // check and remove all leaf
                    for (auto &itr:adj[index]) {
                        adj[itr].erase(index);
                        if (adj[itr].size() == 1) {
                            q.push(itr);
                        }
                    }
                }
                q.pop();
            }
        }

        vector<int> ans;

        if (q.empty()) {
            ans.push_back(0);
        }

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }

};
