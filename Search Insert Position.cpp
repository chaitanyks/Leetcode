class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        if (nums[high] < target)
            return high + 1;

        if (nums[0] >= target)
            return 0;


        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        // cout<<high<<endl;
        return high;
    }
};
