class Solution {
private:
    bool f(vector<int>& nums, vector<vector<int>>& dp, int sum) {
        int n = nums.size();
        dp[0][0] = 1;
        if (nums[0] <= sum)
            dp[0][nums[0]] = 1;
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= sum; tar++) {
                bool notake = dp[ind - 1][tar];
                bool take = false;
                if (nums[ind] <= tar) {
                    take = dp[ind - 1][tar - nums[ind]];
                }
                dp[ind][tar] = take || notake;
            }
        }
        return dp[n - 1][sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1, 0));
        return f(nums, dp, sum / 2);
    }
};