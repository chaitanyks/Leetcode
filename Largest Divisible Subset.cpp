class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> lis(1001, 1);
        vector<int> len[1001];
        
        len[0].push_back(nums[0]);
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            index = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    // cout<<nums[i]<<" "<<lis[i]<<" "<<lis[j]<<endl;
                    if (lis[i] < (1 + lis[j])) {
                        lis[i] = 1 + lis[j];
                        index = j;
                        // prod[i] = nums[i]*prod[j];
                    }

                    // lis[i] = max(lis[i],1+lis[j]);                    
                }
            }
            // cout<<nums[i]<<" "<<index<<endl;
            vector<int> temp;
            if (index != -1)
                temp = len[index];
            temp.push_back(nums[i]);
            len[i] = temp;
        }

        int maxV = 0;
        int val = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            // cout<<lis[i]<<" "<<nums[i]<<" "<<len[i].size()<<" "<<endl;
            if (maxV < lis[i]) {
                maxV = lis[i];
                index = i;
            }
        }

        return len[index];
    }
};
