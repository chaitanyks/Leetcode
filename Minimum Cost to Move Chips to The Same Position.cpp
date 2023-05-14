class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {

        int cost1 = 0;
        int cost2 = 0;

        for (int i = 0; i < position.size(); i++) {
            //even cost
            int coin = position[i];
            if (coin % 2 == 0)
                cost1++;
            else
                cost2++;
        }
        return min(cost1, cost2);
    }
};
