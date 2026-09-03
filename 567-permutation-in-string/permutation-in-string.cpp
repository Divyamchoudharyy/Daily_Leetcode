class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size() , n2 = s2.size();
        if(n1 > n2) return false;

        vector<int> n(26,0) , a(26,0);
        for(char c : s1)
            n[c-'a']++;
        
        for(int r = 0;r<n2;r++){
            a[s2[r]-'a']++;
            int l = r - n1 + 1; 
            if(l > 0) a[s2[l-1]-'a']--;
            if(l>=0 && n == a) return true;
        }
        return false;
    }
};