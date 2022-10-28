class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int zero_counter = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        nums.erase(nums.begin() + i);
        zero_counter++;
        i--;
      }
    }
    vector<int> tmp(zero_counter, 0);
    nums.insert(nums.end(), tmp.begin(), tmp.end());
  }
};

/* Runtime: 131 ms, faster than 10.99% of C++ online submissions for Move Zeroes.
 * Memory Usage: 19.4 MB, less than 7.96% of C++ online submissions for Move Zeroes.
 */

