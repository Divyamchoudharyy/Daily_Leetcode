class Solution {
private:
    bool f(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = f(i + 1, j - 1, s, dp);

        return dp[i][j] = false;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int start = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                if (f(i, j, s , dp)) {
                    int len = j - i + 1;
                    if (len > maxi) {
                        maxi = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxi);
    }
};