class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n = max(num1.size(), num2.size());
        n = n * 2;
        string a = num1;
        string b = num2;
        string ans;
        vector<int> sum(n, 0);
        int digit = 0;
        int pos = 0;
        int carry = 0;
        for (int i = b.size() - 1; i >= 0; i--) {
            pos = digit;
            for (int j = a.size() - 1; j >= 0; j--) {
                int val1 = b[i] - 48;
                int val2 = a[j] - 48;
                int prod = val1 * val2;
                // cout<<sum[pos]<<" "<<prod<<" "<<carry<<endl;
                int tempS = sum[pos] + prod % 10 + carry;
                // cout<<sum[pos]<<" "<<prod<<" "<<carry<<endl;
                sum[pos] = tempS % 10;
                carry = prod / 10 + tempS / 10;
                pos++;
            }
            sum[pos] = sum[pos] + carry;
            carry = 0;
            digit++;
        }
        
        int last = sum.size() - 1;
        
        while (sum[last] == 0)
            last--;

        for (int i = 0; i <= last; i++) {
            char c = sum[i] + 48;
            ans = c + ans;
        }
        return ans;
    }
};
