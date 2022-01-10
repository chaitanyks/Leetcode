// https://leetcode.com/problems/add-binary/
// 67. Add Binary

class Solution {
public:
        
    string addBinary(string a, string b) {       
        char c = '0';
        string ans = "";
        
        int i = a.length();
        int j = b.length();
        
        while(i>=0 || j>=0)
        {
            char val1 = i>=0?a[i]:'0';
            char val2 = j>=0?b[j]:'0';
            
            if(val1=='0' && val2=='0'){
                ans = c + ans;
                c='0';
            }
            
            else if(val1=='1' && val2=='1')
            {
                ans = c + ans;
                if(c=='0')
                    c = '1';
            }
            
            else if(val1=='1' || val2=='1')
            {
                if(c=='0')
                    ans = '1' + ans;
                else
                {
                    ans = '0' + ans;
                    c = '1';
                }
            }            
            i--;
            j--;
        }
   
        if(c=='1')
            ans = c + ans;
        
        return ans;
    }
};
