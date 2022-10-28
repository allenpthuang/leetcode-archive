class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
      result = result << 1;
      result = result | (n & 1);
      n = n >> 1;
    }
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
 * Memory Usage: 6 MB, less than 51.03% of C++ online submissions for Reverse Bits.
 */

