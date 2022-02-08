
// https://leetcode.com/problems/add-digits/submissions/
// 258. Add Digits

class Solution {
public:
    int addDigits(int num) {

        if (num % 9 == 0 && num != 0)
            return 9;
        else
            return num % 9;
    }
};