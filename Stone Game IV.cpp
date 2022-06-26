// https://leetcode.com/problems/stone-game-iv/
// 1510. Stone Game IV

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> square;
        for (int i = 1; i * i <= n; i++) {
            square.push_back(i * i);
        }
        
        vector<bool> dp (n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            
            int sr = sqrt(i);
            int rem = i - sr * sr;

            if (rem == 0)
                dp[i] = true;
            else {
                int j = 0;
                bool ans = false;
                while (j < square.size() && square[j] <= i) {
                    // cout<<i<<" "<<j<<" "<<square[j]<<endl;
                    ans = ans | !dp[i - square[j]];
                    j++;
                }
                dp[i] = ans;
            }
        }

        return dp[n];
    }
};
