class Solution {
private:
    int f(int i , int j , vector<vector<char>>& mat , vector<vector<int>>& dp){
        int n = mat.size() , m = mat[0].size();
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(mat[i][j] == '0') return dp[i][j] = 0;

        int r = f(i,j+1,mat,dp);
        int down = f(i+1,j,mat,dp);
        int dg = f(i+1,j+1,mat,dp);

        return dp[i][j] = 1 + min({r,down,dg});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n ,vector<int>(m,-1));
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                maxi = max(maxi,f(i,j,matrix,dp));
            }
        }
        return maxi*maxi;
    }
};