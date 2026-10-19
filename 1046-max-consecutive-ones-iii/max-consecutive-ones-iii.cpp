class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() , zero = 0 , left = 0 , maxi = 0;
        for(int r = 0;r<n;r++){
            if(nums[r] == 0)
                zero++;
            while(zero > k){
                if(nums[left] == 0) zero--;
                left++;
            }
            maxi = max(maxi,r-left+1);
        }
        return maxi;
    }
};