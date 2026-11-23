class Solution {
private:
    int f(int ind ,vector<int>& dp){
        if(ind == 0 || ind == 1)
            return 1;
        
        if(dp[ind]!=-1) return dp[ind];

        int t = f(ind-1,dp);
        int nt = f(ind-2,dp);

        return dp[ind] = t + nt;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);      
    }
};