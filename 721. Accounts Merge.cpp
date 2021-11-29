class Solution {
public:

    int find(int x, int parents[]) {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    void unionGraph(int x, int y, int parents[]) {
        int p1 = find(x, parents);
        int p2 = find(y, parents);
        if (p1 != p2) {
            parents[p1] = p2;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> ans;
        map<string, int> mp;
        int n = accounts.size();

        // set parents
        int parents[n + 1];
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int index = i + 1;
            for (int j = 1; j < accounts[i].size(); j++) {
                string str = accounts[i][j];
                if (mp[str] == 0) {
                    mp[str] = index;
                } else {
                    unionGraph(mp[str], i + 1, parents);
                }
            }
        }       

        vector<int> adj[1001];
        int ind = 0;
        for (int i = 1; i <= n; i++) {
            int root = find(i, parents);
            adj[root].push_back(i);
        }
        
        map<string, bool> repeat;
        for (int i = 1; i <= 1000; i++) {
            if (adj[i].size() != 0) {
                vector<string> temp;
                temp.push_back(accounts[adj[i][0] - 1][0]);
                for (int j = 0; j < adj[i].size(); j++) {
                    for (int k = 1; k < accounts[adj[i][j] - 1].size(); k++) {
                        if (!repeat[accounts[adj[i][j] - 1][k]]) {
                            repeat[accounts[adj[i][j] - 1][k]] = true;
                            temp.push_back(accounts[adj[i][j] - 1][k]);
                        }
                    }
                }
                ans.push_back(temp);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            sort(ans[i].begin() + 1, ans[i].end());
        }

        return ans;
    }
};
