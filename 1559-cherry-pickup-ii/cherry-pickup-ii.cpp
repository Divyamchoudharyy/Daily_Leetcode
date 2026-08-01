class Solution {
private:    
    int f(int i , int j1 , int j2 ,vector<vector<int>>&  arr , vector<vector<vector<int>>>& dp){
        int n = arr.size() ,  m = arr[0].size();

        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;

        if(i == n-1){
            if(j1 == j2) return arr[i][j1];
            else return arr[i][j1] + arr[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        int curr = (j1 == j2) ? arr[i][j1] : arr[i][j1] + arr[i][j2];

        for(int a = -1 ;a<=1;a++){
            for(int b = -1 ; b<=1;b++){
                int ans = f(i+1,j1+a,j2+b,arr,dp);
                maxi = max(maxi,ans);
            }
        }
        
        return dp[i][j1][j2] = curr + maxi;

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size() , n = grid.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
};