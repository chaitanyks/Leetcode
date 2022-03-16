// https://leetcode.com/problems/validate-stack-sequences/submissions/
// 946. Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // stack<int> st;
        int n = pushed.size();
        int j = 0;
        int index = 0;
        
        for(int i=0;i<n;i++)
        {
            // st.push(pushed[i]);
            // cout<<index<<" ";
            pushed[index] = pushed[i];            
            while(j<n && index>=0 && pushed[index]==popped[j])
            {
                j++;
                // st.pop();
                index--;
            }
            index++;
        }
        
        return index==0?true:false;
    }
};
