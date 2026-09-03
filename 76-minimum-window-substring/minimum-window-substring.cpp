class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size() , n2 = t.size();
        
        if(n1 < n2) return "";

        unordered_map<char,int> need;
        for(char c : t)
            need[c]++;

        int req = need.size();
        int curr = 0;

        unordered_map<char,int> window;

        int blen = 1e8 , bstart = 0;
        int l = 0;

        for(int r = 0;r<n1;r++){
            char c = s[r];
            window[c]++;

            if(need.count(c) && window[c] == need[c]) curr++;

            while(curr == req){
                if(r - l + 1 < blen){
                    blen = r-l+1;
                    bstart = l;
                }
                char lc = s[l];
                window[lc]--;
                if(need.count(lc) && window[lc] < need[lc])
                    curr--;
                l++;
            }
        }
        return blen >= 1e8 ? "" : s.substr(bstart,blen);


        
            
    }
};