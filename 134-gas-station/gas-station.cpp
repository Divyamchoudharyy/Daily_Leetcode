class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int asum = accumulate(gas.begin(),gas.end(),0) , bsum = accumulate(cost.begin(),cost.end(),0);
        if(asum<bsum) 
            return -1;
        int currgas = 0 , start = 0;
        for(int i = 0;i<gas.size();i++){
            currgas += gas[i] - cost[i];
            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }
        return start;
    }
};