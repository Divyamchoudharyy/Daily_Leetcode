class Solution {
private:
    void mergeSort(vector<int>& nums , int l , int m , int h ){
        vector<int> temp ;
        int low = l  , r = m +1;
        while(low <= m && r <= h){
            if(nums[low]<=nums[r])
                temp.push_back(nums[low++]);
            else 
                temp.push_back(nums[r++]);
        }
        while(low <= m)
            temp.push_back(nums[low++]);
        while(r <= h)
            temp.push_back(nums[r++]);
        for(int i = l;i<=h;i++)
            nums[i] = temp[i-l];       
    }
    void merge(vector<int>& nums ,int l , int h){
        if(l>=h) return ;
        int mid = l + (h - l) / 2;

        merge(nums,l,mid);
        merge(nums,mid+1,h);
        mergeSort(nums,l,mid,h);
    }   

public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0 , h = nums.size()-1;
        int m = l + (h - l) /2;

        merge(nums,l,h);
        return nums;
    }
};