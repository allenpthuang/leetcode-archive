class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int one_cnt = 0;
    while (n != 0) {
      if (n & 1 > 0) one_cnt++;
      n = n >> 1;
    }
    return one_cnt;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
 * Memory Usage: 5.9 MB, less than 48.22% of C++ online submissions for Number of 1 Bits.
 */

