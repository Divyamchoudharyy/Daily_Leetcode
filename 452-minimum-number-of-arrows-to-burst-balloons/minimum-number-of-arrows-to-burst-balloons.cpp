class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), count = 1;
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        for (int i = 1; i < n; i++) {
            int currSP = points[i][0], currEP = points[i][1];
            int prevSP = prev[0], prevEP = prev[1];

            if (currSP > prevEP) {
                count++;
                prev = points[i];
            } else {
                prev[0] = max(prevSP, currSP);
                prev[1] = min(prevEP, currEP);
            }
        }
        return count;
    }
};