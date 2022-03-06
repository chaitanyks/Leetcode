// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// 1359. Count All Valid Pickup and Delivery Options

class Solution {
public:
      int M = pow(10, 9) + 7;
    
      int countOrders(int n) {
          
         long long twoInverse = 500000004;
         long long ans = 1;
          
         for (int i = 1; i <= 2 * n; i++)
            ans = i <= n ? (((ans * i) % M) * twoInverse) % M : (ans * i) % M;
          
         return ans;
      }
};
