class Solution {
private:
    bool f(string s, string t , int l , int r){
        if(l == s.size()) return true;
        if(r == t.size()) return false;

        if(s[l] == t[r])
            return f(s,t,l+1,r+1);
        else
            return f(s,t,l,r+1);
    }
public:
    bool isSubsequence(string s, string t) {
        return f(s,t,0,0);
    }
};