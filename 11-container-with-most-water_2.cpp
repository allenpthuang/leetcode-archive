class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int cur_max = 0;
    while (left < right) {
      int lower = min(height[left], height[right]);
      cur_max = max(cur_max, (right - left) * lower);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return cur_max;
  }
};

/* Runtime: 97 ms, faster than 94.65% of C++ online submissions for Container With Most Water.
 * Memory Usage: 58.9 MB, less than 80.22% of C++ online submissions for Container With Most Water.
 */

