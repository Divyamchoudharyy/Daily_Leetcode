class Solution {
private:    
    bool f(int ind , int tar , vector<vector<int>>& dp , vector<int>& nums){
        if(tar == 0)
            return true;
        if(ind == 0)
            return nums[0] == tar;
        
        if(dp[ind][tar] != -1) return dp[ind][tar];

        int nt = f(ind-1,tar,dp,nums);
        int t = 0;
        if(nums[ind] <= tar)
            t = f(ind-1,tar-nums[ind],dp,nums);

        return dp[ind][tar] = t || nt;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2 != 0) return false;

        int tar = sum /2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(tar+1,-1));
        return f(nums.size()-1,tar,dp,nums);
    }
};