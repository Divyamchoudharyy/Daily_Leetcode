class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> m;
        int l = 0 , r = 0 , maxi = 0;

        while(r < n){
            m[fruits[r]]++;
            while(m.size() > 2){
                m[fruits[l]]--;
                if(m[fruits[l]] == 0){
                    m.erase(fruits[l]);
                }
                l++;

            }
        
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};