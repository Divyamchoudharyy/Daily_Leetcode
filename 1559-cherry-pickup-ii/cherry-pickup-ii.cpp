class Solution {
private:
    int f(int i , int j1 , int j2 ,vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){

        int n = grid.size() , m = grid[0].size();

        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e8;

        if(i == n-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        int curr = j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];

        for(int a =-1;a<=1;a++){
            for(int b = -1; b<=1;b++){
                int ans = f(i+1,j1+a,j2+b,grid,dp);
                maxi = max(maxi,ans);
            }
        }
        return dp[i][j1][j2] = maxi + curr;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int> (m+1,-1)));

        return f(0,0,m-1,grid,dp);
    }
};