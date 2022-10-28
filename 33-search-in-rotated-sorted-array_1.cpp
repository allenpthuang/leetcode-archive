class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // find the real head index first
    // look for anomly: nums[mid] > nums[right]!
    int left = 0;
    int right = nums.size() - 1;
    int head = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    head = left;
    
    // use binary search with wrapped lower and upper indices
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int mid_rot = (mid + head) % nums.size();
      if (nums[mid_rot] == target) {
        return mid_rot;
      } else if (nums[mid_rot] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

/* Runtime: 5 ms, faster than 49.86% of C++ online submissions for Search in Rotated Sorted Array.
 * Memory Usage: 11.1 MB, less than 75.66% of C++ online submissions for Search in Rotated Sorted Array.
 */

