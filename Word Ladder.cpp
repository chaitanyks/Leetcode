// https://leetcode.com/problems/word-ladder/
// 127. Word Ladder

static auto _speedupMagic=[]{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 0;
        }();

class Solution {
public:
    int minEdgeBFS(vector<int> edges[], int u, int v, int n) {
        vector<bool> visited (n, 0);
        int distance = 0;

        queue<pair<int, int>> q;

        q.push({u, 1});
        visited[u] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int dis = q.front().second;
            q.pop();

            if (x == v) {
                distance = dis;
                break;
            }

            for (int i = 0; i < edges[x].size(); i++) {
                if (visited[edges[x][i]])
                    continue;

                q.push({edges[x][i], dis + 1});
                visited[edges[x][i]] = 1;
            }
        }
        return distance;
    }

    void addEdge(vector<int> adj[], int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    int ladderLength(string beginWord, string endWord, vector<string>&wordList) {
        bool isPresent = false;
        int n = wordList.size();
        int source = -1;
        int dest = -1;
        int m = beginWord.length();

        for (int i = 0; i < n; i++) {
            if (endWord == wordList[i]) {
                isPresent = true;
                dest = i;
            }

            if (beginWord == wordList[i])
                source = i;
        }

        if (!isPresent)
            return 0;

        // create graph
        if (source == -1) {
            wordList.push_back(beginWord);
            source = n;
            n = n + 1;
        }

        vector<int> adj[ n];
        int diff;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diff = 0;
                for (int k = 0; k < m; k++) {
                    if (wordList[i][k] != wordList[j][k])
                        diff++;
                }

                if (diff == 1)
                    addEdge(adj, i, j);
            }
        }

        int ans = minEdgeBFS(adj, source, dest, n);

        return ans;
    }
};
