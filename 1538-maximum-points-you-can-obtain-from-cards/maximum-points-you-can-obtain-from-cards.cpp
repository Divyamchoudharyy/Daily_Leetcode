class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int wsize = n-k , total = 0 , wsum = 0 ;
        for(int x : cardPoints)
            total+=x;
        for(int i = 0;i<wsize;i++)
            wsum+=cardPoints[i];
        int mini = wsum;

        for(int right = wsize;right<n;right++){
            wsum += cardPoints[right];
            wsum -= cardPoints[right - wsize];
            mini = min(mini , wsum);
        }
        return total - mini;
    }
};