class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        
        int i=0;
        int j=0;
        int ans = 0;
        int len = 0; 
        while(j<s.size())
        {         
            if(mp[s[j]] >= 1)
            {
                // cout<<"if"<<endl;
                mp[s[i]]--;
                i++;
                len--;
            }
            else
            {
                // cout<<"else"<<endl;
                mp[s[j]]++;
                j++;
                len++;
            }
            
            if(ans<len)
                ans = len;
        }
        return ans;
        
    }
};
