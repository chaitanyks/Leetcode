// https://leetcode.com/problems/all-paths-from-source-to-target/
// 797. All Paths From Source to Target

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    void dfs(vector<vector<int>> &graph, int start) {

        if (start == graph.size() - 1) {
            ans.push_back(temp);
        } else {
            int n = graph[start].size();
            for (int i = 0; i < n; i++) {
                int index = graph[start][i];
                temp.push_back(index);
                dfs(graph, index);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int start = 0;
        int end = graph.size() - 1;
        temp.push_back(start);
        dfs(graph, start);
        return ans;
    }
};
