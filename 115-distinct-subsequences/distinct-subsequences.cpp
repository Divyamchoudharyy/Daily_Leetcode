class Solution {
int Find(int i , int j , string& s , string& t,  vector<vector<int>>& dp){
    if(j == t.size()) return 1;
    if(i == s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        int take = Find(i+1,j+1,s,t,dp);
        int nottake = Find(i+1,j,s,t,dp);
        return dp[i][j] = take+nottake;
    }else{
        return dp[i][j] = Find(i+1,j,s,t,dp);
    }
}
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp (n+1 , vector<int> (m+1 , -1));
        return Find(0,0,s,t,dp);
    }
};