// https://leetcode.com/problems/palindromic-substrings/submissions/
// 647. Palindromic Substrings

class Solution {
public:
    int countPalindrome(int start,int end,string s)
    {
        int count = 0;
        int n = s.length();
        while(start >=0 && end < n && s[start] == s[end])
        {
            count++;
            start--;
            end++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            ans += countPalindrome(i,i,s) + countPalindrome(i,i+1,s);
        }
        
        return ans;
    }
};
