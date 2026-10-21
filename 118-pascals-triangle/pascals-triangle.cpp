class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0;i<numRows;i++){
            vector<int> a(i+1);
            a[0] = a[i] = 1;
            for(int j = 1;j<i;j++){
                a[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans[i] = a;
        }
        return ans;
    }
};