class Solution {
private:
    void f(vector<char>& s , int l , int r ){
        if(l>r) return;

        swap(s[l],s[r]);
        f(s,l+1,r-1);         
    }
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        f(s,0,n-1);
    }
};