class Solution {
public:

    int count(int mid, int n, int m) {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = ans + min(mid / i, n);
        }
        return ans;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = n * m;
        // int ans = 0;
        while (low < high) {
            int mid = (low + high) / 2;
            int c = count(mid, n, m);
            if (c < k) {
                low = mid + 1;
            } else
                high = mid;
        }
        return low;
    }
};
