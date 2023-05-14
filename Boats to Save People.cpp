// https://leetcode.com/problems/boats-to-save-people/
// 881. Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(),people.end());
        int n = people.size();
        
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            int val = people[high]+people[low];
            ans++;
            high--;            
            if(val<=limit)
                low++;
        }
        
        return ans;        
    }
};
