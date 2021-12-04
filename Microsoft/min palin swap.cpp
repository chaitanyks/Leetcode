#include <iostream>

using namespace std;

int minSwap(string str) {
    string temp = str;

    int ans = 0;
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        int l = i;
        int r = n - l - 1;
        if (str[l] == str[r]) {
            continue;
        } else {
            int ml = i;
            int mr = r;

            while (ml <= r && str[ml] != str[r])
                ml++;
            while (mr >= l && str[mr] != str[l])
                mr--;

//            odd check
            if (ml == r && mr == l) {
                ans = -1;
                break;
            }

            if (ml > (r - mr)) {
                ans = ans + r - mr;
                while (mr < r) {
                    swap(str[mr], str[mr + 1]);
                    mr++;
                }
            } else {
                ans = ans + ml;
                while (ml > l) {
                    swap(str[ml], str[ml - 1]);
                    ml--;
                }
            }
        }
    }

//    cout << str << endl;
    return ans;
}

int main() {
    // your code goes here
    string str = "mamad";
//    cin>>str;
    cout << minSwap(str);
    return 0;
}
