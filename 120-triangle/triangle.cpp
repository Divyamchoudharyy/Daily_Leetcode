class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() , m = triangle[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(n,0));

        for(int j = 0;j<n;j++)
            dp[n-1][j] = triangle[n-1][j];

        
        for(int i = n-2;i>=0;i--){
            for(int j=i;j>=0;j--){

                int dw = dp[i+1][j];
                int da = dp[i+1][j+1];

                dp[i][j] = min(da,dw) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};