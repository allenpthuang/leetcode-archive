class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int cur_left_tallest = height[left];
    int cur_right_tallest = height[right];
    int trapped_rain = 0;
    
    while (left < right) {
      if (cur_left_tallest <= cur_right_tallest) {
        left++;
        if (cur_left_tallest - height[left] > 0) {
          trapped_rain += cur_left_tallest - height[left];
        } else {
          cur_left_tallest = height[left];
        }
      } else {
        right--;
        if (cur_right_tallest - height[right] > 0) {
          trapped_rain += cur_right_tallest - height[right];
        } else {
          cur_right_tallest = height[right];
        }
      }
    }
    return trapped_rain;
  }
};

/* Runtime: 28 ms, faster than 54.92% of C++ online submissions for Trapping Rain Water.
 * Memory Usage: 19.8 MB, less than 81.97% of C++ online submissions for Trapping Rain Water.
 */

