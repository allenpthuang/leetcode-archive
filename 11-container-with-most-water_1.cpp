class Solution {
 public:
  int maxArea(vector<int>& height) {
    int cur_max = 0;
    for (int i = 0; i < height.size(); i++) {
      for (int j = i + 1; j < height.size(); j++) {
        cur_max = max(cur_max, min(height[i], height[j]) * (j - i));
      }
    }
    return cur_max;
  }
};

/* TLE */

