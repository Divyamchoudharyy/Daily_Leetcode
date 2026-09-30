class Solution {
private:
    bool f(int i  , int j , string& s){
        if(i >= j) return true;

        if(s[i] == s[j])
            return f(i+1,j-1,s);
        
        return false;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0 , start = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(f(i,j,s)){
                    int len = j-i+1;
                    if(len > maxi){
                        maxi = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxi);
    }
};