class Solution {
public:
    vector<long long> count;
    Solution()
    {
        count.push_back(0);
        for(int i=1;i<=65536;i++)
        {
            count.push_back(count[i-1]+i);
        }
    }
    int arrangeCoins(int n) {
        auto itr = lower_bound(count.begin(),count.end(), n);
        int pos = distance(count.begin(), itr);

        if(count[pos] == n)
            return pos;
        return pos-1;
    }
};
