// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// 1010. Pairs of Songs With Total Durations Divisible by 60

class Solution {
    public:

    int numPairsDivisibleBy60(vector<int>&time) {
        int n = time.size();
        int count = 0;

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int diff = (60 - time[i] % 60) % 60;

            if (mp[diff] != 0)
                count += mp[diff];

            mp[time[i] % 60]++;
        }

        return count;
    }
};
