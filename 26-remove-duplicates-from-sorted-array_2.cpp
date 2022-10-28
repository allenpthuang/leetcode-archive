class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int left = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[left]) {
        left++;
        nums[left] = nums[i];
      }
    }
    return left + 1;
  }
};

/* Runtime: 11 ms, faster than 83.89% of C++ online submissions for Remove Duplicates from Sorted Array.
 * Memory Usage: 18.4 MB, less than 36.64% of C++ online submissions for Remove Duplicates from Sorted Array.
 */

