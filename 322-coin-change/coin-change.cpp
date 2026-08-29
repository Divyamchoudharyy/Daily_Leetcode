class Solution {
private:
    int f(int ind , vector<int>& arr , int tar,vector<vector<int>>& dp){
        if(ind == 0){
            if(tar % arr[ind] == 0)
                return tar / arr[ind];
            else
                return 1e8;
        }

        if(dp[ind][tar]!= -1) return dp[ind][tar];

        int notake = f(ind-1,arr,tar,dp);
        int take = 1e8;
        if(arr[ind]<=tar)
            take = 1 + f(ind,arr,tar-arr[ind],dp);
    
        return dp[ind][tar] = min(take,notake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = f(coins.size()-1,coins,amount,dp);
        return (ans>=1e8 ? -1 : ans);
    }
};