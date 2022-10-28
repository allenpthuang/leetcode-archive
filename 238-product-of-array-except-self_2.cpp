class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
      result[i] *= prefix;
      prefix *= nums[i];
    }
    int postfix = 1;
    for (int i = result.size() - 1; i >= 0; i--) {
      result[i] *= postfix;
      postfix *= nums[i];
    }
    return result;
  }
};

/* Runtime: 28 ms, faster than 87.34% of C++ online submissions for Product of Array Except Self.
 * Memory Usage: 24 MB, less than 69.16% of C++ online submissions for Product of Array Except Self.
 */

