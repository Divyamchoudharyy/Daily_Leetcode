class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0 , end = 0 , cnt = 0;
        for(int i = 0;i<nums.size()-1;i++){
            maxi = max(maxi , i + nums[i]);
            if(i == end){
                cnt++;
                end = maxi;
            }
        }
        return cnt;
    }
};