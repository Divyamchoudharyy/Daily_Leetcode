class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxi = 1 , count = 0;
        int last = -1e8;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]-1 == last){
                count++;
                last = nums[i];
            }else if(last != nums[i]){
                last = nums[i];
                count = 1;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }

};