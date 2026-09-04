class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int lf = intervals[0][1] , cnt = 0;
        for(int i = 1;i<n;i++){
            if(intervals[i][0] < lf) cnt++;
            else lf = intervals[i][1];
        }
        return cnt;
    }
};