class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int actualSum = 0;

        for(int i=0; i<n; i++){
            actualSum += nums[i];
        }

        int sum = (n*(n+1))/2;

        return sum-actualSum;
    }
};
