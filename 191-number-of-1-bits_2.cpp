class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int one_cnt = 0;
    while (n != 0) {
      one_cnt++;
      n = n & (n - 1);
    }
    return one_cnt;
  }
};

/* Runtime: 6 ms, faster than 16.12% of C++ online submissions for Number of 1 Bits.
 * Memory Usage: 5.8 MB, less than 79.50% of C++ online submissions for Number of 1 Bits.
 *
 * (pintsung): it should be faster than going for every bit...
 */
