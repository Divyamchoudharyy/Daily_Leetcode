class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(char ch : s1)
            freq[ch-'a']++;
        int l = 0;
        for(int r = 0;r<s2.size();r++){
            freq[s2[r]-'a']--;

            while(freq[s2[r]-'a'] < 0)
                freq[s2[l++]-'a']++;
            
            if(r - l + 1 == s1.size())
                return true;
        }
        return false;   
    }
};