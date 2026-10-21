
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        int n = s.size();
        string ans = "";
        int charInSec = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {
            int ind = i;

            while (ind < n) {
                ans += s[ind];  

                if (i != 0 && i != numRows - 1) {
                    int charInBw = charInSec - (2 * i);
                    int sind = ind + charInBw;

                    if (sind < n)
                        ans += s[sind]; 
                }

                ind += charInSec;
            }
        }

        return ans;
    }
};
