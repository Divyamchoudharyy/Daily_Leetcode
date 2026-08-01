class Solution {
private:
    int f(int ind, vector<int>& coins, int am, vector<vector<int>>& dp) {
        if(am == 0) return 0;
        if (ind == 0) {
            if (am % coins[0] == 0)
                return am / coins[0];
            else
                return 1e8;
        }
        if (dp[ind][am] != -1)
            return dp[ind][am];
        int notake = f(ind - 1, coins, am, dp);
        int take = 1e8;
        if (coins[ind] <= am)
            take = 1 + f(ind, coins, am - coins[ind], dp);

        return dp[ind][am] = min(take, notake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = f(coins.size() - 1, coins, amount, dp);
        return (ans >= 1e8) ? -1 : ans;
    }
};