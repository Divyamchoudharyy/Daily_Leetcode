class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char x : tasks)
            freq[x-'A']++;
        int maxfreq = *max_element(freq.begin(),freq.end());
        int maxcount = count(freq.begin(),freq.end(),maxfreq);

        int ans = (maxfreq-1)*(n+1) + maxcount;

        return max((int)tasks.size(),ans);
    }
};