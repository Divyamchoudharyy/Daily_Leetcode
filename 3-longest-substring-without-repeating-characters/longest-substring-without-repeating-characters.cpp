class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 , maxi = 0;
        int n = s.size();
        unordered_set<int> st;
        for(int r = 0;r<n;r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxi = max(maxi,r - l + 1);
        }
        return maxi;
    }
};