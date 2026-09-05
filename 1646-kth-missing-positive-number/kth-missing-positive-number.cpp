class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0 , r= arr.size()-1;

        while(l <= r){
            int m = l + (r -l)/2;

            int miss = arr[m] - (m+1);

            if(miss < k)
                l = m + 1;
            else
                r = m -1;
        }
        return l + k;
    }
};