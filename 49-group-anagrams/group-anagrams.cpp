class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> key;

        for(string& s : strs){
            vector<int> freq(26,0);
            for(char c : s)
                freq[c-'a']++;
            string d;
            for(int i = 0;i<26;i++)
                d += to_string(freq[i]) + "#";

            key[d].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [a,b] : key){
            ans.push_back(b);
        }
        return ans;
    }
};