class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> st;
        for(int i = 0;i<nums.size();i++){

            int first = nums[i];
            int second = target - first;

            if(st.find(second)!=st.end()){
                ans.push_back(i);
                ans.push_back(st[second]);
                break;
            }
            st[first] = i;
        }
        return ans;
    }
};