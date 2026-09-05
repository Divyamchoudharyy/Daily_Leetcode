class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int row = 0 , maxi = 0;
        for(int i = 0;i<n;i++){
            int ones = count(mat[i].begin(),mat[i].end(),1);

            if(ones > maxi){
                maxi = ones;
                row = i;
            }
        }
        return {row,maxi};
    }
};