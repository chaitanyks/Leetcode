// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// 1007. Minimum Domino Rotations For Equal Row

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> mp;
        int n = tops.size();
        for(int i=0;i<n;i++)
        {
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }
        
        for(int i=1;i<=6;i++)
        {
            if(mp[i]>=n)
            {
                int uc = 0;
                int bc = 0;
                
                for(int j=0;j<n;j++)
                {
                    if(tops[j]!=i && bottoms[j]!=i)
                        return -1;
                    
                    if(tops[j]==i && bottoms[j]==i)
                        continue;
                    
                    if(tops[j]==i)
                        bc++;
                    if(bottoms[j]==i)
                        uc++;
                }
                
                return min(bc,uc);
            }
        }
        
        return -1;
    }
};
