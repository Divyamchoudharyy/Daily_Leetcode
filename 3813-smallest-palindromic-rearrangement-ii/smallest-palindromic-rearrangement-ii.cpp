class Solution {
public:
    static constexpr long long LIM = 1000001;

    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return ans;
    }

    long long countPerm(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;
            ways *= C(rem, x);
            if (ways > LIM) ways = LIM;
            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];

            if (freq[i] & 1)
                mid += char('a' + i);
        }

        if (countPerm(half) < k)
            return "";

        string left;

        while (len--) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countPerm(half);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};