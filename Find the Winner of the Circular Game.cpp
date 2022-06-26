class Solution {
public:

    int findTheWinner(int n, int k) {
        int prev = 0;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (k % i + prev) % i;
            prev = ans;
        }
        return ans + 1;
    }
};
