class Solution {
private:
    void f(int ind , string digits , string output , string map[] , vector<string>& ans){
        if(ind >= digits.size()){
            ans.push_back(output);
            return;
        }
        int val = digits[ind]-'0';
        string a = map[val];
        for(int i = 0;i<a.size();i++){
            output.push_back(a[i]);
            f(ind+1,digits,output,map,ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output = "";

        f(0,digits,output,map,ans);
        return ans;
    }
};