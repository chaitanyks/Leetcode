#include <bits/stdc++.h>

using namespace std;

// O(N) with map
int largestK1(vector<int> &v) {
    map<int, int> mp;

    for (int i = 0; i < v.size(); i++) {
        mp[v[i]] = 1;
    }
    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        if (mp[v[i]] == 1 && mp[-v[i]] == 1) {
            if (abs(v[i]) > ans)
                ans = abs(v[i]);
        }
    }

    return ans;

}

// nlog(n) with two pointer
int largestK2(vector<int> &v) {
    int ans = 0;
    sort(v.begin(), v.end());

    int l = 0;
    int r = v.size() - 1;

    while (l < r) {
        if (v[l] + v[r] == 0) {
            ans = v[r];
            break;
        } else if (v[l] + v[r] > 0)
            r--;

        else
            l++;
    }

    return ans;
}

int main() {
    // your code goes here
    vector<int> v = {-5, 2, -2, 5, -3, 86, 9, 7, 36, 2};
    cout << largestK1(v) << endl;
    cout << largestK2(v) << endl;
    return 0;
}
