class Solution {
private:
    int f(int ind , int buy ,int t , vector<int>& prices , vector<vector<vector<int>>>& dp){
        if(ind == prices.size() || t == 0) return 0;

        if(dp[ind][buy][t] != -1) return dp[ind][buy][t];
        int profit = 0;
        if(buy)
            profit = max(f(ind+1,1,t,prices,dp),-prices[ind]+f(ind+1,0,t-1,prices,dp));
        else
            profit = max(f(ind+1,0,t,prices,dp),prices[ind]+f(ind+1,1,t-1,prices,dp));
        
        return dp[ind][buy][t] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2,vector<int>(5,-1)));

        return f(0,1,4,prices,dp);
    }
};