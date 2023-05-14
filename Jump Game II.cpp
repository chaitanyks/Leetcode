// https://leetcode.com/problems/jump-game-ii/
// 45. Jump Game II

class Solution {
public:
    int jump(vector<int> &nums) {
        int i = 0;
        int n = nums.size() - 1;
        int count = 0;
        while (i < n) {
            count++;

            if (i + nums[i] >= n)
                break;
            int mr = i + nums[i];
            int temp = 0;
            int index = i + nums[i];
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if (mr < j + nums[j]) {
                    mr = j + nums[j];
                    index = j;
                }
            }
            i = index;
        }

        return count;
    }
};
