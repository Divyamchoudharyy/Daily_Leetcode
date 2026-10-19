class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() , mini = 1e8;
        int left = 0 , sum = 0;
        for(int right = 0;right<n;right++){
            sum += nums[right];

            while(sum >= target){
                mini = min(mini,right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if(mini >=1e8) return 0;
        return mini;
    }
};