class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size() , l = 0 , r = 0 , cnt = 0;
        long long ans = 1;
        while(r < n){
            ans*=nums[r];
            while(ans >= k){
                ans/=nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};