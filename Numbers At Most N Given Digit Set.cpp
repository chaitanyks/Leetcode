class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        int m = digits.size();
        int ans = 0;

        vector<int> num;

        int temp = n;
        while (temp) {
            int val = temp % 10;
            num.push_back(val);
            temp /= 10;
        }

        int numSize = num.size();

        for (int i = 0; i < numSize - 1; i++) {
            ans = ans + pow(m, i + 1);
        }

        cout << ans << endl;

        // last combination
        int product = 1;
        int val = 0;
        bool find = true;
        for (int i = numSize - 1; i >= 0 && find; i--) {
            find = false;
            val = num[i];
            int count = 0;
            for (int j = 0; j < m; j++) {
                // cout<<digits[j]<<" ";
                // string str = digits[j];
                // int number = str[0] - '0';
                int number = digits[j][0] - '0';
                if (number < val)
                    count++;

                if (number == val)
                    find = true;
            }
            // product*=count; 
            ans = ans + count * pow(m, i);
            cout << ans << " ";
        }
        if (find)
            ans += 1;
        // ans += product;
        return ans;
    }
};
