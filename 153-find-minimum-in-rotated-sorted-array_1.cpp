class Solution {
 public:
  int findMin(vector<int>& nums) {
    // binary search with more conditions
    // consider A[L], A[R], A[mid]
    // check the left and right and mid conditions
    // to know to which direction we go
    
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }
      if (nums[left] < nums[mid]) {
        if (nums[left] < nums[right]) {
          // go left
          right = mid - 1;
        } else {
          // go right
          left = mid + 1;
        }
      } else if (nums[mid] > nums[right]) {
        // go right
        left = mid + 1;
      } else {
        // go left
        right = mid - 1;
      }
    }
    return nums[left];
  }
};

/* Runtime: 4 ms, faster than 75.69% of C++ online submissions for Find Minimum in Rotated Sorted Array.
 * Memory Usage: 10.1 MB, less than 95.52% of C++ online submissions for Find Minimum in Rotated Sorted Array.
 */

