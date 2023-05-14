// https://leetcode.com/problems/gas-station/
// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0;
        int reqFuel = 0;
        int ans = 0;
      
        for(int i=0;i<n;i++)
        {
            if(fuel<0)
            {
                reqFuel += fuel;
                ans = i;
                fuel = 0;
            }
            
            fuel -= cost[i];
            fuel += gas[i];
        }
        
        if(fuel < abs(reqFuel))
            return -1;        
        return ans;
    }
};
