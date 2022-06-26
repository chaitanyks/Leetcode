// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// 1337. The K Weakest Rows in a Matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            int one = 0;
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                    break;
                
                one++;
            }
            pq.push({-one,-i});
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
