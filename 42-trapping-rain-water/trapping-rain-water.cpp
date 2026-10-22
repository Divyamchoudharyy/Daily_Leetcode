class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n <= 2)
            return 0;
        vector<int> pre(n,0), suff(n,0);
        pre[0] = heights[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], heights[i]);
        suff[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = max(suff[i + 1], heights[i]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(pre[i], suff[i]) - heights[i];
        }
        return ans;
    }
};