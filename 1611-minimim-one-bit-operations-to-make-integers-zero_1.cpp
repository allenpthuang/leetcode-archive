class Solution {
 public:
  int minimumOneBitOperations(int n) {
    int result = 0;
    while (n > 0) {
      result = result ^ n;
      // "chop off the LSB"
      n = n >> 1;
    }
    return result;
  }
};

/* from Discussion
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum One Bit Operations to Make Integers Zero.
 * Memory Usage: 5.8 MB, less than 79.70% of C++ online submissions for Minimum One Bit Operations to Make Integers Zero.
 */
