// https://leetcode.com/problems/combination-sum/
// 39. Combination Sum

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> temp,int index,vector<vector<int>> &ans)
    {
        if(target == 0)
            ans.push_back(temp);

        if(target<0)
            return ;

        int n = candidates.size();

        for(int i=index; i<n; i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,i,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,temp,0,ans);
        return ans;
    }
};
