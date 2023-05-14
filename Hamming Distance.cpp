class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int val = x ^y;
        while (val) {
            ans++;
            val = val & (val - 1);
        }
        return ans;
    }
};
