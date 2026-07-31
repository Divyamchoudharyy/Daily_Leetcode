class Solution {
private:
    int f(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int l = f(n - 1, dp);
        int r = f(n - 2, dp);

        return dp[n] = l + r;
    }

public:
    int climbStairs(int n) {
        if (n == 1 )
            return 1;
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};