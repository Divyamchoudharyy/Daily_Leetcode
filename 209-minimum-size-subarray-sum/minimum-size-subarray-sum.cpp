class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = 1e8 , n = nums.size();
        int l = 0 , sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];

            while(sum >= target){
                if(mini > i - l + 1)
                    mini = i-l+1;

                sum -= nums[l];
                l++;
            }
        }
        return mini >= 1e8 ? 0 : mini;
    }
};