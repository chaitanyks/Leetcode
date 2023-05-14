// https://leetcode.com/problems/evaluate-division/
// 399. Evaluate Division

typedef pair<string,string> pr;

class Solution {
public:
    
    void store(map<pr,bool> &visited,queue<pr> &q,map<pr,double> &mp,pr &one,double value)
    {
        if(!visited[one])
        {
            q.push(one);
            mp[one] = value;
            visited[one] = !visited[one];
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        pr two,one;
        queue<pr> q;
        map<pr,double> mp;        
        vector<double> ans;
        map<pr,bool> visited;
        
        int m = queries.size();
        int n = equations.size();
        
        for(int i=0;i<n;i++)
        {
            one = {equations[i][0],equations[i][1]};
            store(visited,q,mp,one,values[i]);
            
            two = {equations[i][1],equations[i][0]};
            store(visited,q,mp,two,1/values[i]);
        }
        
        
        while(!q.empty())
        {
            one = q.front();
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                
                if(equations[i][0] == one.second)
                {
                    two = {one.first,equations[i][1]};
                    store(visited,q,mp,two,mp[one]*values[i]);
                }
                
                if(equations[i][1] == one.second)
                {
                    two = {one.first,equations[i][0]};
                    store(visited,q,mp,two,mp[one]/values[i]);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            pr one = {queries[i][0],queries[i][1]};
            if(visited[one])
                ans.push_back(mp[one]);
            else
                ans.push_back(-1.0);
        }
        return ans;
    }
};
