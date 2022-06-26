// 476. Number Complement
// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask)
            mask = mask << 1;
        return num ^ (~mask);
    }
};
