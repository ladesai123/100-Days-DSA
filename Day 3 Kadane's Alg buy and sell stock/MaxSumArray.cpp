class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i=0; i<nums.size(); i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};