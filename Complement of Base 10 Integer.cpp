// https://leetcode.com/problems/complement-of-base-10-integer/

// 1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int n) {
        //corner case
        if(n==0)
            return 1;
        
        unsigned mask = ~0;
        while (n & mask)
            mask = mask << 1;
        return n ^ (~mask);
    }
};
