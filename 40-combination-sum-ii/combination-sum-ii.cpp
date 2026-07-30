class Solution {
private:
    void f(vector<int> arr, int target, int ind, vector<int>& ds,
           vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            f(arr, target - arr[i], i + 1, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        f(candidates, target, 0, ds, ans);
        return ans;
    }
};