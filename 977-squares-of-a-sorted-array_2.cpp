class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = pow(nums[i], 2);
    }
    vector<int> result(nums.size(), 0);
    int left = 0;
    int right = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[left] > nums[right]) {
        result[i] = nums[left];
        left++;
      } else {
        result[i] = nums[right];
        right--;
      }
    }
    return result;
  }
};

/* Runtime: 21 ms, faster than 99.74% of C++ online submissions for Squares of a Sorted Array.
 * Memory Usage: 26 MB, less than 54.51% of C++ online submissions for Squares of a Sorted Array.
 */


