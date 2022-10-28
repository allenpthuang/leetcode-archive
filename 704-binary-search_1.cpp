class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int result = -1;
    int left = 0;
    int right = nums.size() - 1;
    
    int mid = 0;
    
    
    while (left <= right) {
      mid = (right - left) / 2 + left;
      if (nums[mid] == target) {
        return mid;
      }
      if (target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return result;
  }
};

/* Runtime: 71 ms, faster than 28.29% of C++ online submissions for Binary Search.
 * Memory Usage: 27.6 MB, less than 63.73% of C++ online submissions for Binary Search.
 */

