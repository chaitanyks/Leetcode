class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        bool ans = false;
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            if (arr[index] == 0) {
                ans = true;
                break;
            }

            visited[index] = true;

            if (index + arr[index] < n && !visited[index + arr[index]]) {
                q.push(index + arr[index]);
            }

            if (index - arr[index] >= 0 && !visited[index - arr[index]]) {
                q.push(index - arr[index]);
            }

        }

        return ans;
    }
};
