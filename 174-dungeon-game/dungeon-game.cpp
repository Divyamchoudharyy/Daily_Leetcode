class Solution {
private:
    int f(int i , int j , vector<vector<int>>& dungeon , vector<vector<int>>& dp){
        int n = dungeon.size() , m = dungeon[0].size();

        if(i >= n || j >=m)
            return 1e8;
        
        if(i == n-1 && j == m-1)
            return max(1,1 - dungeon[i][j]);
        
        if(dp[i][j] != -1) return dp[i][j];
        int right =  f(i + 1 , j , dungeon,dp);
        int down =f(i , j + 1, dungeon,dp);

        int ans = min(right , down);

        return dp[i][j] = max(1 , ans - dungeon[i][j]);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size() , m = dungeon[0].size();

        vector<vector<int>> dp(n , vector<int>(m,-1));
        return f(0,0,dungeon,dp);
    }
};