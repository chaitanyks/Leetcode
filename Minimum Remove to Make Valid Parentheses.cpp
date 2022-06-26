// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// 1249. Minimum Remove to Make Valid Parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int ob = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            char val = s[i];
            if(s[i] == '(')
                ob++;
            else if(s[i]==')')
            {
                if(ob==0)
                    continue;
                ob--;
            }
            
            ans += val;
        }
        if(ob!=0)
        {
            string fans="";
            int n = ans.length();
            for(int i=n-1;i>=0;i--)
            {
                char val = ans[i];
                if(ans[i] == '(' && ob!=0)
                {
                    ob--;
                    continue;
                }
                fans +=  ans[i];
            }
            reverse(fans.begin(), fans.end());
            return fans;
        }
        
        return ans;
    }
};
