class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left(nums.size(), 1);
    vector<int> right(nums.size(), 1);
    
    for (int i = 1; i < left.size(); i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = right.size() - 2; i >= 0; i--) {
      right[i] = right[i + 1] * nums[i + 1];
    }
    vector<int> result(nums.size(), 0);
    for (int i = 0; i < result.size(); i++) {
      result[i] = left[i] * right[i];
    }
    return result;
  }
};

/* Runtime: 55 ms, faster than 28.47% of C++ online submissions for Product of Array Except Self.
 * Memory Usage: 25.1 MB, less than 29.54% of C++ online submissions for Product of Array Except Self.
 */

