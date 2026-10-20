class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size() , n2 = t.size();
        if(n2 > n1) return "";
        unordered_map<char,int> need;
        for(char c : t)
            need[c]++;
        int req = need.size() , curr = 0 , l = 0 , start = 0 , mini=1e8;

        unordered_map<char,int> win;
        for(int r = 0;r<n1;r++){
            char c = s[r];
            win[c]++;

            if(need.count(c) && need[c] == win[c])
                curr++;
            
            while(curr == req){
                int len = r-l+1;
                if(mini > len){
                    mini = len;
                    start = l;
                }
                win[s[l]]--;
                if(need.count(s[l]) && win[s[l]] < need[s[l]])
                    curr--;
                l++;
            }


        }
        if(mini >= 1e8) return "";

        return s.substr(start,mini);
    }
};