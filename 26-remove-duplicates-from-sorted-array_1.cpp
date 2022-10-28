class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int k = nums.size();
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i-1]) {
        nums.erase(nums.begin() + i);
        i--;
        k--;
      }
    }
    return k;
  }
};

/* Runtime: 460 ms, faster than 8.29% of C++ online submissions for Remove Duplicates from Sorted Array.
 * Memory Usage: 18.5 MB, less than 36.64% of C++ online submissions for Remove Duplicates from Sorted Array.
 */
