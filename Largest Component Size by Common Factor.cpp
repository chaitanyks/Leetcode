class Solution {
public:

    int root(int x, int parents[]) {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    void unionGraph(int x, int y, int parents[]) {
        int p1 = root(x, parents);
        int p2 = root(y, parents);
        if (p1 != p2) {
            parents[p1] = p2;
        }
        // parents[root(x, parents)] = parents[root(y, parents)];
    }

    int largestComponentSize(vector<int> &nums) {

        int n = nums.size();
        int maxV = 0;
        vector<int> graph[n];
        for (int i = 0; i < n; i++) {
            if (maxV < nums[i])
                maxV = nums[i];
        }
        int parent[maxV + 1];

        for (int i = 0; i <= maxV; i++)
            parent[i] = i;

        // sort(nums.begin(),nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= sqrt(nums[i]); j++) {

                if (nums[i] % j == 0) {
                    // cout<<nums[i]<<" "<<j<<endl;
                    // maxV++;
                    unionGraph(nums[i], j, parent);
                    unionGraph(nums[i], nums[i] / j, parent);
                }
            }
        }

        // for(int i=0;i<=maxV;i++)
        // {
        //     cout<<parent[i]<<" ";
        // }

        int cnt = 0;
        unordered_map<int, int> mp;

        for (auto &val : nums) {
            int x = root(val, parent);
            mp[x]++;
            cnt = max(cnt, mp[x]);
        }

        return cnt;
    }
};
