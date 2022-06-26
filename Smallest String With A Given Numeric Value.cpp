https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
1663. Smallest String With A Given Numeric Value

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        int val = k;
        int len = n;
        while(val!=0)
        {
            val = k/26;
            int rem = k%26;
            
            if(val+rem >= len)
            {
                int na = len - val;
                while(val!=0)
                {
                    val--;
                    ans += "z";
                }

                if(na != rem)
                {
                    char i = 'a';
                    i=i+rem-na;
                    ans+=i;
                }
            }
            else
            {
                // pre = "a" + pre;
                int diff = len - val - rem;
                k = k - diff;
                len = len - diff;
            }
        }
        
        while(ans.length()!=n)
            ans += "a";
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
