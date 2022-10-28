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
      if (i > 0 && nums[i] == 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int rem = target - nums[i];
      int left = i + 1;
      int right = nums.size() - 1;
      
      while (left < right) {
        int cur_sum = nums[left] + nums[right];
        if (cur_sum == rem) {
          result.push_back(vector<int> {nums[i], nums[left], nums[right]});
          break;
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

/* wrong answer */

