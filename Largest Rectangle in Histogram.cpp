// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n= heights.size();
        int ans = 0;
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        //left
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty())
                left[i] = (i-s.top())*heights[i];
            else
                left[i] = (i+1)*heights[i];
            s.push(i);
            // cout<<left[i]<<" ";
        }
        
        while(!s.empty())
            s.pop();
        
        //right
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty())
                right[i] = (s.top()-i)*heights[i];
            else
                right[i] = (n-i)*heights[i];
            s.push(i);
            // cout<<right[i]<<" ";
        }
        
        for(int i=0;i<n;i++)
        {
            int prod = left[i] + right[i] -heights[i];
            ans = max(ans,prod);
        }
        
        return ans;
    }
};
