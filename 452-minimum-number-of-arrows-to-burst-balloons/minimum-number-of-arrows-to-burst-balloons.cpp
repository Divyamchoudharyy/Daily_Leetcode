class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        vector<int> prev = points[0];
        int cnt = 1;
        for(int i = 1;i<n;i++){
            int currSP = points[i][0] , currEP = points[i][1];
            int prevSP = prev[0] , prevEP = prev[1];

            if(currSP > prevEP){
                cnt++;
                prev = points[i];
            }else{
                prev[0] = max(currSP,prevSP);
                prev[1] = min(currEP,prevEP);
            }
        }
        return cnt;
    }
};