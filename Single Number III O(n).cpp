class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int a = 0;
        int b = 0;
        long long xorVal = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorVal = xorVal ^ nums[i];
        }

        long long mask = xorVal & ~(xorVal - 1);

        for (int i = 0; i < nums.size(); i++) {
            if (mask & nums[i]) {
                a = a ^ nums[i];
            } else {
                b = b ^ nums[i];
            }
        }
        return {a, b};
    }
};
