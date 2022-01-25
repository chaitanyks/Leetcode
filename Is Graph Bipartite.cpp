// https://leetcode.com/problems/is-graph-bipartite/
// 785. Is Graph Bipartite?

class Solution {
public:

    bool bfs(vector<vector<int>> &graph) {
        int n = graph.size();
        set<int> a;
        set<int> b;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        a.insert(0);

        for (int i = 1; i < n; i++) {
            q.push(i);
        }

        bool ans = true;
        int count = 0;
        while (!q.empty() && ans) {
            count++;
            int u = q.front();
            cout << u << endl;
            q.pop();
            visited[u] = true;
            if (a.find(u) != a.end()) {
                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];
                    if (a.find(v) != a.end()) {
                        // cout<<u<<" "<<v<<" l1";
                        ans = false;
                        break;
                    } else {
                        if (!visited[v]) {
                            // cout<<u<<" "<<v<<" l1"<<endl;
                            q.push(v);
                            b.insert(v);
                        }
                    }
                }
            } else if (b.find(u) != b.end()) {
                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];
                    if (b.find(v) != b.end()) {
                        // cout<<" l2";
                        ans = false;
                        break;
                    } else {
                        if (!visited[v]) {
                            // cout<<u<<" "<<v<<" l2"<<endl;
                            q.push(v);
                            a.insert(v);
                        }
                    }
                }
            } else {
                if (graph[u].size() != 0) {

                    bool p1 = false;
                    bool p2 = false;

                    for (int i = 0; i < graph[u].size(); i++) {
                        int v = graph[u][i];
                        if (a.find(v) != a.end())
                            p1 = true;
                        if (b.find(v) != b.end())
                            p2 = true;
                    }

                    if (p1 && p2) {
                        // cout<<" l";
                        ans = false;
                        break;
                    } else if (p1) {
                        b.insert(u);
                    } else if (p2)
                        a.insert(u);

                    // if(!p1 && !p2 && graph[u].size()==1){
                    //     a.insert(u);
                    // }

                    // cout<<u<<" "<<p1<<" "<<p2<<" "<<endl;
                    if (count >= n * 2) {
                        a.insert(u);
                        count = 0;
                    }
                    q.push(u);
                    visited[u] = false;
                }
            }
        }

        return ans;
    }


    bool isBipartite(vector<vector<int>> &graph) {
        return bfs(graph);
    }
};
