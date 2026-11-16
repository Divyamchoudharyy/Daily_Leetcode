class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);

        for(int it : s)
            freq[it - 'a']++;
        for(int it : t)
            freq[it-'a']--;
        
        for(auto it : freq){ 
            if(it != 0)
                return false;
        }
        return true;
    }
};