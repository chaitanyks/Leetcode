// https://leetcode.com/problems/koko-eating-bananas/
// 875. Koko Eating Bananas

class Solution {
public:
    int minEatingSpeed(vector<int>&piles, int h) {
        int n = piles.size();
        int high = pow(10, 9);
        int low = 1;
        int hours = 0;
        
        while (low <= high) {
            int mid = (high + low) / 2;
            hours = 0;
            
            for (int i = 0; i < n; i++) {
                hours += piles[i] / mid;
                if (piles[i] % mid != 0)
                    hours++;
            }

            if (low == high)
                break;
            else if (hours > h)
                low = mid + 1;
            else
                high = mid;
        }
        return high;
    }
};
