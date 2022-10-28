class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
      if (tx > ty) {
        if (sy == ty) {
          return ((tx - sx) % ty == 0);
        }
        tx = tx % ty;
      } else {
        if (sx == tx) {
          return ((ty - sy) % tx == 0);
        }
        ty = ty % tx;
      }
    }
    return false;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reaching Points.
 * Memory Usage: 5.8 MB, less than 87.50% of C++ online submissions for Reaching Points.
 */

