
#include <bits/stdc++.h>

using namespace std;

int equalHeight(vector<int> &v) {
    int ans = 0;
    int count = 0;
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i > 0; i--) {
        count++;
        if (v[i] != v[i - 1]) {
            ans = ans + count;
        }
    }

    return ans;
}

int main() {
    // your code goes here
    vector<int> v = {1, 2, 2, 2, 2, 2, 5, 5, 7, 7};
    cout << equalHeight(v) << endl;
    return 0;
}
