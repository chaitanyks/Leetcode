class Solution {
public:
    int arrangeCoins(long long n) {
        return (sqrt(1 + 8 * n) - 1) / 2;
    }
};
