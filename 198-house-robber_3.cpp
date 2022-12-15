class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); i++) {
            dp[i] = max(
                nums[i] + dp[i - 2], // rob this
                dp[i - 1] // don't rob this
            );
        }
        return dp[nums.size() - 1];
    }
};

/* https://leetcode.com/problems/house-robber/submissions/859968900/ */

