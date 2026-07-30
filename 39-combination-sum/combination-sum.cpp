class Solution {
private:
    void f(vector<int> arr , vector<vector<int>>& ans , vector<int>& ds , int target , int ind){
        if(ind == arr.size()){
            if(target == 0)
                ans.push_back(ds);
            return;
        }

        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            f(arr,ans,ds,target-arr[ind],ind);
            ds.pop_back();
        }
        f(arr,ans,ds,target,ind+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();
        vector<vector<int>> ans;
        f(candidates,ans,ds,target,0);
        return ans;
    }
};