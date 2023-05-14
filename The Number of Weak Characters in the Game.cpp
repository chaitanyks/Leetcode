// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// 1996. The Number of Weak Characters in the Game

class Solution {
public:
    
    static bool custom(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& pr) {
        sort(pr.begin(),pr.end(),custom);
        
        int n = pr.size();
        int ans = 0;
        int maxV = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(pr[i][1]<maxV)
                ans++;
            maxV = max(pr[i][1],maxV);
            // cout<<pr[i][0]<<" "<<pr[i][1]<<endl;
        }        
        return ans;
    }
};
