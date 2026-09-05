class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
        int profit = 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                
                if(buy)
                    profit = max(dp[ind+1][1],-prices[ind]+dp[ind+1][0]);
                else
                    profit = max(dp[ind+1][0],prices[ind]+dp[ind+1][1]);
                
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};