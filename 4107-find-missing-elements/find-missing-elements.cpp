class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> ans;
        unordered_set<int> m(nums.begin(),nums.end());

        for(int i = mini+1 ; i < maxi ; i++){
            if(!m.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};