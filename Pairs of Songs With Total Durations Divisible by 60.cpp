// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// 1010. Pairs of Songs With Total Durations Divisible by 60

class Solution {
    public:

    int numPairsDivisibleBy60(vector<int>&time) {
        int count = 0;
        int n = time.size();
        if (n == 1)
            return 0;
        map<int, int> mp;
        sort(time.begin(), time.end());

        for (int i : time)
            mp[i]++;

        // max2
        int max1 = time[0];
        int max2 = time[1];

        for (int i = 2; i < n; i++) {
            if (time[i] > max1) {
                max2 = max1;
                max1 = time[i];
            } else if (time[i] > max2)
                max2 = time[i];
        }

        for (int i = 0; i < n; i++) {
            int val = time[i] / 60;
            val = 60 + val * 60;
            for (int j = val; j <= max1 + max2; j = j + 60) {
                int diff = j - time[i];
                if (diff < time[i])
                    continue;
                // cout<<diff<<" "<<mp[diff]<<" / ";
                if (diff == time[i]) {
                    if (mp[diff] > 1) {
                        mp[diff]--;
                        count += mp[diff];
                    }
                    continue;
                }

//                 else 
                if (mp[diff] != 0)
                    count += mp[diff];
            }
        }

        return count;
    }
};
