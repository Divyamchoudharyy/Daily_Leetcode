class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), total = 0;
        for (int a : nums)
            total += a;
        int target = total - x;

        if (target < 0)
            return -1;
        if (target == 0)
            return n;

        int left = 0, sum = 0, maxi = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target)
                maxi = max(maxi, right - left + 1);
        }
        if (maxi == 0)
            return -1;
        return n - maxi;
    }
};