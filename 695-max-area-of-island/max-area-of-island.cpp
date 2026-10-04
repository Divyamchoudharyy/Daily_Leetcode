class Solution {
private:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vis[i][j] = 1;
        q.push({i, j});
        int cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;


            for (int i = 0; i < 4; i++) {
                int dr = r + drow[i];
                int dc = c + dcol[i];

                if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] == 1 && !vis[dr][dc]) {
                    vis[dr][dc] = 1;
                    q.push({dr, dc});
                }
            }
        }
        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() , maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]){
                    int d = f(i,j,grid,vis);
                    if(d > maxi)
                        maxi = d;
                }
            }
        }
        return maxi;
    }
};