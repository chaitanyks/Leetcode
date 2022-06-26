// https://leetcode.com/problems/permutation-in-string/
// 567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (m < n)
            return false;
        
        vector<long long> hash(26, 0);
        int M = pow(10, 9) + 7;

        hash[0] = 1;
        for (int i = 1; i < 26; i++) {
            hash[i] = (26 * hash[i - 1]) % M;
        }

        int val = 0;
        int val2 = 0;
        int index;
        
        for (int i = 0; i < n; i++) {
            
            index = s1[i] - 'a';
            val = (val + hash[index]) % M;
            
            index = s2[i] - 'a';
            val2 = (val2 + hash[index]) % M;
        }
        
        int low = 0;
        int i = n - 1;
        
        while (i < m) {

            if (val2 < 0)
                val2 = val2 + M;

            if (val == val2)
                return true;
            
            //low 
            index = s2[low] - 'a';
            val2 = (val2 - hash[index]) % M;
            low++;

            //high
            i++;
            index = s2[i] - 'a';
            if (i < m)
                val2 = (val2 + hash[index]) % M;
        }

        return false;
    }
};
