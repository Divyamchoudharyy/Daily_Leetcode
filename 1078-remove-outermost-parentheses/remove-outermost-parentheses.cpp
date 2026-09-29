class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0 ;
        string ans = "";
        int start = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                if(cnt == 0)
                    start = i;
                cnt++;
            }else{ 
                cnt--;
                if(cnt == 0)
                    ans += s.substr(start + 1, i - start - 1);
            }
        }
        return ans;
    }
};