class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int val = -1;
            int pos = nums2.size();
            for(int j=0;j<nums2.size();j++)
            {
                if(nums2[j] == nums1[i])
                {
                    pos = j;
                    break;
                }
            }
            for(int j=pos+1;j<nums2.size();j++)
            {
                if(nums2[j]>nums1[i])
                {
                    val = nums2[j];
                    break;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};
