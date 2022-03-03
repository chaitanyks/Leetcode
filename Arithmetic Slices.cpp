// https://leetcode.com/problems/arithmetic-slices/
// 413. Arithmetic Slices

class Solution {
public:

      int numberOfArithmeticSlices(vector < int > & nums) {

         int n = nums.size();

         int start, diff, len, ans;
         start = diff = len = ans = 0;

         for (int i = 1; i < n; i++) {
            int currD = nums[i] - nums[i - 1];

            if (diff != currD) {
               len = i - start;
               ans += (len * (len - 3)) / 2 + 1;
               start = i - 1;
               diff = currD;
            }

            //last index
            if (i == n - 1) {
               cout << len << " ";
               len = n - start;
               ans += (len * (len - 3)) / 2 + 1;
            }
         }

         return ans;
      }
};
