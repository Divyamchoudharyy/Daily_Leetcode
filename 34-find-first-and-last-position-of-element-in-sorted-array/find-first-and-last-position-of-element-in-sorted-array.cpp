class Solution {
private:
    int lb(vector<int>& nums, int target){
        int l = 0 , h = nums.size()-1;
        int ans = -1;

        while(l <= h){

            int m = l + (h-l)/2;

            if(nums[m] >= target){
                ans = m;
                h = m-1;
            }else
                l = m + 1;
        }
        return ans;
    }
    int ub(vector<int>& nums, int target){
        int l = 0 , h = nums.size()-1;
        int ans = nums.size();

        while(l <= h){

            int m = l + (h-l)/2;

            if(nums[m] > target){
                ans = m;
                h = m-1;
            }else
                l = m + 1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lb(nums,target);
        int u = ub(nums,target);

        if(l == -1 || nums[l] != target)
            return {-1,-1};
        
        return {l,u-1};
    }
};