class Solution {
public:
    int M = pow(10, 9) + 7;


//     int solve(int n, int a, int b) {
//         set<int> s;
//         map<int, int> mp;
//         int count = 0;
//         int ans;
//         int i = 1;
//         int j = 1;
//         while (count < n) {
//             int p1 = (a * i) % M;
//             int p2 = (b * j) % M;


//             if (p1 > p2) {
//                 if (mp[p2] == 0) {
//                     mp[p2] = 1;
//                     count++;
//                     ans = p2;
//                 }
//                 // s.insert(p2);
//                 j++;
//             } else {
//                 if (mp[p1] == 0) {
//                     mp[p1] = 1;
//                     count++;
//                     ans = p1;
//                 }
//                 // s.insert(p1);
//                 i++;
//             }
//         }
//         // auto itr = s.rbegin();
//         // return *itr;
//         return ans;
//     }

    

//     int bs(int n, int a, int b) {
//         long long ans;
//         if (a % b == 0 || b % a == 0) {
//             long long val = min(a, b);
//             ans = (val * n) % M;
//         } else {
//             long long lval = lcm(a, b);


//             long long val = a * b * lval;
//             long long val1 = lval * a + lval * b - a * b;

//             val = val * n;
//             val = val / val1;
//             cout << val << " ";
//             long long ans1 = val;
//             long long ans2 = val;
//             while (ans1 % a != 0 && ans1 % b != 0)
//                 ans1++;
//             while (ans2 % a != 0 && ans2 % b != 0)
//                 ans2--;

//             // cal n
//             long long n1 = ans1 / a + ans1 / b - ans1 / lval;
//             long long n2 = ans2 / a + ans2 / b - ans2 / lval;

//             if (n1 == n)
//                 ans = ans1 % M;
//             else
//                 ans = ans2 % M;
//         }
//         return ans;
//     }
    
    long long gcd(long long int a, long long int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // Function to return LCM of two numbers
    long long lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int binaryS(int n, int a, int b) {

        long long low = min(a, b);
        long long high = pow(2, 62) - 1 - low;
        long long lval = lcm(a, b);
        long long ele = high / a + high / b - high / lval;
        long long ans = low;
        while (low < high) {
            long long mid = (high + low) / 2;
            ele = mid / a + mid / b - mid / lval;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if (ele == n) {
                ans = mid;
                // break;
                high = mid;
            } else if (ele < n)
                low = mid + 1;
            else
                high = mid;

        }
        return ans % M;
    }

    int nthMagicalNumber(int n, int a, int b) {
        if (n == 1)
            return min(a, b);

        return binaryS(n, a, b);
    }
};
