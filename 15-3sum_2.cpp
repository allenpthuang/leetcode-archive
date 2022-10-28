class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    
    if (nums.size() < 3) {
      return result;
    }
    
    int target = 0;
    sort(nums.begin(), nums.end());
    
    // go thru nums; i is the pivoted, fixed leftmost element
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int rem = target - nums[i];
      int left = i + 1;
      int right = nums.size() - 1;
      
      while (left < right) {
        int cur_sum = nums[left] + nums[right];
        if (cur_sum == rem) {
          result.push_back(vector<int> {nums[i], nums[left], nums[right]});
          while (left < right && left + 1 < nums.size() && nums[left] == nums[left + 1]) {
            left++;
          }
          while (left < right && right - 1 > 0 && nums[right] == nums[right - 1]) {
            right--;
          }
          left++;
          right--;
        } else if (cur_sum < rem) {
          left++;
        } else if (cur_sum > rem) {
          right--;
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 77 ms, faster than 88.73% of C++ online submissions for 3Sum.
 * Memory Usage: 19.9 MB, less than 87.04% of C++ online submissions for 3Sum.
 */

