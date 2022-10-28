class Solution {
 public:
  int smallestRangeII(vector<int>& nums, int k) {
    // nums = [6, 3, 7, 9, 1, 2, 10]
    sort(nums.begin(), nums.end());
    // nums = [1, 2, 3, 6, 7, 9, 10]
    //         ^-- add here       ^-- substract here
    
    // init. score
    int score = nums[nums.size() - 1] - nums[0];
    
    // substract all first, and add 2 * k on the left
    for (int& n : nums) {
      n -= k;
    }
    
    int cur_min = nums[0];
    int cur_max = nums[nums.size() - 1];
    // compare and update the score
    for (int i = 0; i < nums.size() - 1; i++) {
      cur_min = min(nums[0] + 2 * k, nums[i + 1]);
      cur_max = max(cur_max, nums[i] + 2 * k);
      score = min(score, cur_max - cur_min);
    }
    return score;
  }
};

/* Runtime: 28 ms, faster than 70.80% of C++ online submissions for Smallest Range II.
 * Memory Usage: 15.5 MB, less than 71.35% of C++ online submissions for Smallest Range II.
 */

