class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int k = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        k++;
      }
    }
    return k;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
 * Memory Usage: 8.8 MB, less than 36.91% of C++ online submissions for Remove Element.
 */

