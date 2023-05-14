// https://leetcode.com/problems/jump-game-ii/
// 45. Jump Game II

class Solution {
public:
    int bfs(vector<int> &nums) {
        int n = nums.size() - 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = 0;
        int range = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int count = q.front().second;
            q.pop();
            int maxReach = index + nums[index];
            if (index == n) {
                ans = count;
                break;
            }

            if (maxReach > range) {
                while (range < maxReach) {
                    range++;
                    q.push({range, 1 + count});
                }
            }
        }
        return ans;
    }

    int jump(vector<int> &nums) {
        return bfs(nums);
    }
};
