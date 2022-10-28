class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    int left = 0;
    int right = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (pow(nums[left], 2) > pow(nums[right], 2)) {
        result[i] = pow(nums[left], 2);
        left++;
      } else {
        result[i] = pow(nums[right], 2);
        right--;
      }
    }
    return result;
  }
};

/* Runtime: 55 ms, faster than 50.84% of C++ online submissions for Squares of a Sorted Array.
 * Memory Usage: 26 MB, less than 54.51% of C++ online submissions for Squares of a Sorted Array.
 */

