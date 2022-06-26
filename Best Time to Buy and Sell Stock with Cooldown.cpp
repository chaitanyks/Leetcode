class Solution {
public:
    int dp[5005][2]={0};
    
    int calP(vector<int> & prices,int ind,int buy)
    {
        if(ind>= prices.size())
            return 0;
        int sum1=0;
        if(dp[ind+1][buy] == 0)
            dp[ind+1][buy] = calP(prices,ind+1,buy);
        
        sum1 = dp[ind+1][buy];
        int sum2=0;
        
        if(dp[ind+1][0] == 0)
        {
            dp[ind+1][0] = calP(prices,ind+1,0);
        }
        if(dp[ind+2][1] == 0)
        {
            dp[ind+2][1] = calP(prices,ind+2,1);
        }
        
        if(buy==1)
            sum2 = -prices[ind] + dp[ind+1][0];
        else
            sum2 = +prices[ind] + dp[ind+2][1];
        
        return max(sum1,sum2);
    }
    int maxProfit(vector<int>& prices) {
        
        int ans = calP(prices,0,1);  
        return ans;        
    }
};
