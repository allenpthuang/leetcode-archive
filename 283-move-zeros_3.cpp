class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int zero_counter = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zero_counter++;
      } else if (zero_counter > 0) {
        nums[i - zero_counter] = nums[i];
        nums[i] = 0;
      }
    }
  }
};

/* Runtime: 33 ms, faster than 54.57% of C++ online submissions for Move Zeroes.
 * Memory Usage: 19.3 MB, less than 13.90% of C++ online submissions for Move Zeroes.
 */

// Snow ball
//
