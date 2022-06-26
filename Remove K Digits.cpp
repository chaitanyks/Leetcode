// https://leetcode.com/problems/remove-k-digits/
// 402. Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack < char > st;
        
        // forward
        for (int i = 0; i < n; i++) {
            
            while (!st.empty() && num[i] < st.top() &&k != 0) {
                k--;
                st.pop();
            }
            
            st.push(num[i]);
        }
        
        // backward
        while (k != 0) {
            st.pop();
            k--;
        }
        
        string ans = "";
        string zero = "";
        
        //remove leading zero
        while (!st.empty()) {
            
            if (st.top() != '0') {
                ans = st.top() + zero + ans;
                zero = "";
            }
            
            if (st.top() == '0')
                zero += st.top();
            st.pop();
        }
        
        //corner case
        if (ans == "")
            return "0";
        return ans;
    }
};
