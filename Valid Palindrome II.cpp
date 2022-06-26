// https://leetcode.com/problems/valid-palindrome-ii/
// 680. Valid Palindrome II

class Solution {
public:
    
    bool check(int low, int high, string s) {
        while(low<high && s[low] == s[high])
        {
            low++;
            high--;
        }
        
        if(low>=high)
            return true;
        return false;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        bool ans = true;
        
        int low = 0;
        int high = n-1;
        
        while(low<high)
        {
            if(s[low] != s[high]) {
                 ans = check(low+1,high,s)|| check(low,high-1,s);
                break;
            }
            
            low++;
            high--;
        }
        
        return ans;
    }
};
