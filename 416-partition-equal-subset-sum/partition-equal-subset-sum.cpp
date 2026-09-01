class Solution {
private:
    bool f(int ind , vector<int>& nums , int tar ,vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(ind == 0) return nums[0] == tar;
        if(dp[ind][tar] != -1) return dp[ind][tar];
        bool notake = f(ind-1,nums,tar,dp);
        bool take = false;
        if(nums[ind]<=tar)
            take = f(ind-1,nums,tar-nums[ind],dp);
        return dp[ind][tar] = take || notake ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int ans = accumulate(nums.begin(),nums.end(),0);
        if(ans % 2 != 0) return false;
        int sum = ans / 2;
        vector<vector<int>> dp(nums.size()+1,vector<int> (sum+1,-1));
        return f(nums.size()-1,nums,sum,dp);
    }
};