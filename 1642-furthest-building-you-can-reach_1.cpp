class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    // use up the ladder first
    // keep a min heap along the way
    // when ladders are all used
    // try pop the top of the min heap
    // and use bricks to do that round
    
    priority_queue<int, vector<int>, greater<int> > height_diffs;
    for (int i = 0; i < heights.size() - 1; i++) {
      int diff = heights[i + 1] - heights[i];
      if (diff <= 0) {
        continue;
      }
      height_diffs.push(diff);
      if (ladders > 0) {
        ladders--;
      } else if (! height_diffs.empty() && height_diffs.top() <= bricks) {
        bricks -= height_diffs.top();
        height_diffs.pop();
      } else {
        return i;
      }
    }
    return heights.size() - 1;
  }
};

/* Runtime: 274 ms, faster than 23.58% of C++ online submissions for Furthest Building You Can Reach.
 * Memory Usage: 53.7 MB, less than 83.96% of C++ online submissions for Furthest Building You Can Reach.
 */

