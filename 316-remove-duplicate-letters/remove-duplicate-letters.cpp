class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> lastind;
        for(int i = 0;i<s.size();i++)
            lastind[s[i]] = i;
        vector<char> stack;
        unordered_set<char> st;

        for(int i = 0;i<s.size();i++){
            char ch = s[i];

            if(st.count(ch)) continue;

            while(!st.empty() && stack.back() > ch && lastind[stack.back()] > i){
                st.erase(stack.back());
                stack.pop_back();
            }
            stack.push_back(ch);
            st.insert(ch);
        }
        return string(stack.begin(),stack.end());
    }
};