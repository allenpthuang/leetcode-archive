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
    while (zero_counter > 0) {
      nums.push_back(0);
      zero_counter--;
    }
  }
};

/* Runtime: 128 ms, faster than 11.18% of C++ online submissions for Move Zeroes.
 * Memory Usage: 19.3 MB, less than 58.29% of C++ online submissions for Move Zeroes.
 */

