class Solution {
private:
    void f(vector<char>& s , int ind){
        int n = s.size();
        if(ind>=n/2) return;

        swap(s[ind],s[n-ind-1]);
        f(s,ind+1);         
    }
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        f(s,0);
    }
};