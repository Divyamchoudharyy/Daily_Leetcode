class Solution {
private:
    void f(int ind , vector<char>& s){
        if(ind >= s.size()/2) return;

        swap(s[ind],s[s.size()-ind-1]);

        return f(ind+1,s);
    }
public:
    void reverseString(vector<char>& s) {
        f(0,s);
    }
};