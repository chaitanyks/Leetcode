class Solution {
public:
    int singleNonDuplicate(vector<int> &a) {
        if (a.size() == 1)
            return a[0];

        int low = 0;
        int high = a.size() - 1;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (low == high) {
                ans = mid;
                break;
            } else if (mid % 2 == 0) {
                if (a[mid] == a[mid + 1]) {
                    low = mid + 1;
                } else
                    high = mid;
            } else {
                if (a[mid + 1] != a[mid]) {
                    low = mid + 1;
                } else
                    high = mid;
            }
        }

        return a[ans];
    }
};
