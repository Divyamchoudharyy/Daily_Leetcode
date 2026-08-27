class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
            dp[0][j] = mat[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = dp[i - 1][j];

                int left = 1e8;
                if (j > 0)
                    left = dp[i - 1][j - 1];

                int right = 1e8;
                if (j < n - 1)
                    right = dp[i - 1][j + 1];

                dp[i][j] = mat[i][j] + min({up, left, right});
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};