class Solution {
private:
    int f(int ind , vector<int>& nums , vector<int>& dp){
        if(ind >= nums.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int t = nums[ind] + f(ind+2,nums,dp);
        int nt = f(ind+1,nums,dp);

        return dp[ind] = max(t,nt);
    }
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);

        return f(0,nums,dp);
    }
};