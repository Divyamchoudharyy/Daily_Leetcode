class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n);
        presum[0] = nums[0];
        unordered_map<int,int> m;
        for(int i = 1;i<n;i++)
            presum[i] = presum[i-1] + nums[i];
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(presum[i] == k)
                cnt++;
            int rem = presum[i] - k;
            if(m.find(rem)!=m.end()){
                cnt+=m[rem];
            }
            m[presum[i]]++;
        }
        return cnt;
    }
};