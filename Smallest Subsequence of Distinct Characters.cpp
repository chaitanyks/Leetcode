// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// 1081. Smallest Subsequence of Distinct Characters

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> mp(26,0);
        vector<bool> visited(26,false);
        
        int n= s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            int index = s[i] - 'a';
            mp[index]++;
        }
        
        for(int i=0;i<n;i++)
        {
            int vi = s[i] - 'a';
            mp[vi]--;
            
            if(visited[vi])
                continue;            
            
            if(!st.empty() && st.top()>=s[i])
            {   
                int index = st.top()-'a';
                while(!st.empty() && st.top()>=s[i] && mp[st.top()-'a']>=1)
                {
                    index = st.top() - 'a';
                    visited[index] = false;
                    st.pop();
                }
            }            
            
            st.push(s[i]);
            visited[vi] = true;
        }
        
        string ans = "";
        while(!st.empty()) {
            ans =  st.top() + ans;
            st.pop();
        }
        
        return ans;        
    }
};
