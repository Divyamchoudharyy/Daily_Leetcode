class Solution {
private:
    int f(int ind , int buy , vector<vector<int>>& dp , vector<int>& prices){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy)
            profit = max(f(ind+1,1,dp,prices),-prices[ind]+f(ind+1,0,dp,prices));
        else
            profit = max(f(ind+1,0,dp,prices),prices[ind]+f(ind+1,1,dp,prices));
        
        return dp[ind][buy] = profit;
    
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return f(0,1,dp,prices);
    }
};