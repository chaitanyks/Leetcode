class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int initialCost = 0;
        int currFuel = 0;
        int currCost = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            currFuel = currFuel + gas[i];
            currCost = cost[i];

            if (currFuel >= currCost) {
                currFuel = currFuel - currCost;
            } else {
                initialCost += currFuel - currCost;
                currFuel = 0;
                index = i;
            }
        }
        // cout<<initialCost<<" "<<currFuel<<endl;
        if (currFuel + initialCost >= 0) {
            index++;
        } else
            index = -1;

        return index;
    }
};
