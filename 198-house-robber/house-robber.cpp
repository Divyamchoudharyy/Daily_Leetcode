class Solution {
private:
    int f(int ind , vector<int>& nums,vector<int>& dp){
        if(ind >= nums.size())
            return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = f(ind+2,nums,dp) + nums[ind];
        int notake = f(ind+1,nums,dp);

        return dp[ind] = max(take,notake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,0);
        for(int ind = n-1;ind>=0;ind--){
            int take = dp[ind+2] + nums[ind];
            int notake = dp[ind+1];

            dp[ind] = max(take,notake);
        }
        return dp[0];
    }
};