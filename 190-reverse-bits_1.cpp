class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
      result = result << 1;
      result = result + (n & 1);
      n = n >> 1;
    }
    return result;
  }
};

/* Runtime: 3 ms, faster than 63.03% of C++ online submissions for Reverse Bits.
 * Memory Usage: 5.8 MB, less than 81.29% of C++ online submissions for Reverse Bits.
 */

