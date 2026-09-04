class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0 , ans = 0;
        for(int x : nums){
            sum+=x;
            
            int rem = sum % k;
            if(rem < 0){
                rem += k;

            }
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};