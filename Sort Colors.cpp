class Solution {
public:
    void sortColors(vector<int> &a) {
        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) {
                ca++;
            } else if (a[i] == 1) {
                cb++;
            } else
                cc++;
        }

        for (int i = 0; i < a.size(); i++) {
            if (ca != 0) {
                a[i] = 0;
                ca--;
            } else if (cb != 0) {
                a[i] = 1;
                cb--;
            } else {
                a[i] = 2;
                cc--;
            }
        }
    }
};
