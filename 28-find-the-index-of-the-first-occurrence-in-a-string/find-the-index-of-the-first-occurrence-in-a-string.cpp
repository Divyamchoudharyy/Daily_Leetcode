class Solution {
private:
    vector<int> buildLPS(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, len = 0;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    int strStr(string haystack, string needle) {
        vector<int> lps = buildLPS(needle);
        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        while (i < n && j < m) {
            if (haystack[i] == needle[j]){
                i++, j++;
                if (j == needle.size())
                    return  i - j;
            }
            else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};