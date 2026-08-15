class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = x ; long long ans = 0;
        while(n){
            int ld = n % 10;
            ans = ans*10 + ld;
            n/=10;
        }
        return ans == x;
    }
};