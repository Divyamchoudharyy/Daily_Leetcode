class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int r = trust.size();
        vector<vector<int>> adj(n+1);
        for(auto it : trust){
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
        }
        vector<int> ind(n+1,0);
        for(int i = 1;i<=n;i++){
            for(auto it : adj[i])
                ind[it]++;
        }
        for(int i = 1;i<=n;i++){
            if(adj[i].empty() && ind[i] == n-1)
                return i;
        }
        return -1;
    }
};