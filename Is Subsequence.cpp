// https://leetcode.com/problems/is-subsequence/
// 392. Is Subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int index = 0;
        
        for(int i = 0;i<m;i++)
        {
            if(index<n && t[i] == s[index])
                index++;
        }
        
        if(index == n)
            return true;
        return false;
    }
};
