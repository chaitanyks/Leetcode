// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<long long> rH(26,0);
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        int M = pow(10,9)+7;
        
        if(n<m)
            return ans;
        
        // create rolling Hash
        rH[0] = 1;
        for(int i=1;i<26;i++)
        {
            rH[i]=(26*rH[i-1])%M;
        }  
        
        long long val = 0;
        long long tempVal = 0;
        int index = 0;
        int tIndex = 0;
        
        for(int i=0;i<m;i++)
        {
            index = p[i] - 'a';
            tIndex = s[i] - 'a';
            val = (val + rH[index])%M;
            tempVal = (tempVal + rH[tIndex])%M;
        }
        
        int low = 0;
        int high = m-1;
        
        while(high<n)
        {
            // cout<<tempVal<<" ";            
            if(tempVal == val)
                ans.push_back(low);
                
            index = s[low] - 'a';
            tempVal = tempVal - rH[index];
            low++;
            
            high++;
            index = s[high] - 'a';
            if(high<n)
                tempVal = (tempVal + rH[index])%M;
            
            if(tempVal<0)
                tempVal = tempVal+M;
        }
        return ans;
    }
};
