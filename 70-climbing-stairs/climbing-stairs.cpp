class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;

        for(int i = 2;i<=n;i++){
            int l = dp[i - 1];
            int r = dp[i-2];

            dp[i] = l+r;
        }
        return dp[n];
    }
};