// https://leetcode.com/problems/number-of-matching-subsequences/
// 792. Number of Matching Subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        map<string,bool> mp;
        
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            if(mp.find(str) != mp.end())
            {
                if(mp[str])
                    ans++;
                continue;
            }
            
            string match = "";
            int index = 0;
            
            int n=s.length();
            int m=str.length();
            
            for(int j=0; j<n && index<m; j++)
            {
                if(s[j]==str[index]) {
                    match = match + str[index];
                    index++;                        
                }
            }
            
            mp[match] = true;
            
            if(match == str)
                ans++;
            else
                mp[str] = false;
        }
        return ans;
    }
};
