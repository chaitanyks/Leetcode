// https://leetcode.com/problems/remove-k-digits/
// 402. Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        
        // forward
        for(int i=0;i<n;i++)
        {
            while(ans.size()!=0 && num[i]<ans.back() && k!=0)
            {
                k--;
                ans.pop_back();
            }
            
            // leading zero
            if(ans.size()!=0 || num[i]!='0')
                ans.push_back(num[i]);
        }
        
        // backward
        while(ans.size()!=0 && k!=0)
        {
            ans.pop_back();
            k--;
        }
        
        if(ans=="")
            return "0";
        
        return ans;
    }
};
