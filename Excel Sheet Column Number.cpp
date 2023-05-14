// https://leetcode.com/problems/excel-sheet-column-number/
// 171. Excel Sheet Column Number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int index = columnTitle[n-i-1] - 'A' + 1;
            ans = ans + pow(26,i) * index;
        }
        
        return ans;
    }
};
