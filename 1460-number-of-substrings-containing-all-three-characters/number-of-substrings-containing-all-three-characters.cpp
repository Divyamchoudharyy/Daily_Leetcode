class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() , cnt = 0 , mini = 0;
        vector<int> hash(3,-1);
        for(int i = 0;i<n;i++){
            hash[s[i]-'a'] = i;
            int mini = min({hash[0],hash[1],hash[2]});

            if(mini != -1)
                cnt += 1 + mini;
        }
        return cnt;
    }
};