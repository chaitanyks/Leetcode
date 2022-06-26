class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int minValue = 0;
        int sum = 0;
        for (auto &i:nums) {
            sum += i;
            minValue = min(minValue, sum);
        }
        return 1 - minValue;
    }
};
