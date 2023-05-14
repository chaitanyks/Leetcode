class Solution {
public:
    void sortColors(vector<int> &a) {
        int low = 0, mid = 0, high = a.size() - 1, temp;
        while (mid <= high) {
            int i = mid;
            if (a[i] == 0) {
                temp = a[i];
                a[i] = a[low];
                a[low] = temp;
                low++;
                mid++;
            } else if (a[i] == 1) {
                mid++;
            } else if (a[i] == 2) {
                temp = a[i];
                a[i] = a[high];
                a[high] = temp;
                high--;
            }
        }
    }
};
