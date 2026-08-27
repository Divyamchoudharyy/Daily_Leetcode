class Solution {
private:
    int f(int ind, vector<int>& nums, int end) {
        int n = end - ind + 1;
        vector<int> dp(n+2,0);
        dp[0] = 0;
        dp[1] = nums[ind];

        for(int i = 2 ; i <=n ;i++){
            int take = nums[ind + i -1] + dp[i -2];
            int notake = dp[i-1];

            dp[i] = max(take , notake);
        }
        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int a = f(0, nums, n - 2);
        int b = f(1, nums, n - 1);

        return max(a, b);
    }
};