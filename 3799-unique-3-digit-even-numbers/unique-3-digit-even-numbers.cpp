class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int x : digits)
            freq[x]++;
        
        int cnt = 0;
        for(int i = 1;i<10;i++){
            for(int j = 0;j<10;j++){
                for(int k = 0;k<9;k+=2){
                    cnt += freq[i] > 0 && freq[j] > (i == j) && freq[k] > (i == k) + (j == k);
                }
            }
        }
        return cnt;
    }
};