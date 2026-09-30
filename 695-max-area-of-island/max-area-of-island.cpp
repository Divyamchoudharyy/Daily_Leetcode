class Solution {
private:
    int bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int n = grid.size() , m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            cnt++;
            q.pop();

            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};

            for(int i = 0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] ==1){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , maxi = 0;

        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int ans = bfs(i,j,grid,vis);
                    maxi = max(maxi,ans);
                }
            }
        }
        return maxi;
    }
};
