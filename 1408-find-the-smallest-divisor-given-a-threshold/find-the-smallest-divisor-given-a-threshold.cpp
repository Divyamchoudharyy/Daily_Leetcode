class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int d = r;
        while(l <=r){
            int m = l + (r-l)/2;

            long long ans = 0;
            for(int x : nums)
                ans += (x + m -1)/m;
            
            if(ans <= threshold){
                d = m;
                r = m-1;
            }else
                l = m + 1;
        }
        return d;
    }
};