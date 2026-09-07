class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if(1LL * m * k > bloomDay.size())
            return -1;

        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r = *max_element(bloomDay.begin(),bloomDay.end());

        int  ans = r;
        while(l <= r){

            int mid = l + (r-l)/2;
            int cnt = 0 , bo = 0 ;
            for(int x : bloomDay){
                if(x <= mid){
                    cnt++;

                    if(cnt == k){
                        bo++;
                        cnt =0;
                    }
                }else
                    cnt = 0;
            }
            if(bo >= m){
                ans = mid;
                r = mid -1;
            }else
                l = mid + 1;
        }
        return ans;
    }
};