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
        vector<int> dp(nums.size()+1,-1);
        return f(0,nums,dp);

    }
};