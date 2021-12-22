/*1819 · Longest Semi Alternating Substring

Description
You are given a string SSS of length NNN containing only characters a and b.
A substring (contiguous fragment) of SSS is called a semi-alternating substring,
if it does not contain three identical consecutive characters.
In other words, it does not contain either aaa or bbb substrings.
Note that whole SSS is its own substring.

Write a function, which given a string SSS, returns the length of the longest semi-alternating substring of SSS.

Example 1

Input: "baaabbabbb"

Output: 7
*/

class Solution {
public:
    /**
     * @param s: the string
     * @return: length of longest semi alternating substring
     */
    int longestSemiAlternatingSubstring(string &s) {
        // write your code here
        int n = s.length();
        if (n <= 2)
            return n;

        int low = 0;
        int count = 2;
        int ans = 2;
        for (int i = 2; i < n; i++) {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
                low = i - 1;
                count = 2;
            } else {
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};