class Solution {
 public:
  int reverse(int x) {
    int input = 0;
    if (x >= 0) {
      input = x;
    } else {
      if (x == INT_MIN) return 0;
      input = -x;
    }
    int result = 0;
    while (input > 0) {
      if (result > (INT_MAX - (input % 10)) / 10) return 0;
      result = result * 10 + input % 10;
      input /= 10;
    }
    if (x >= 0) {
       return result;
    } else {
       return -result;
    }
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
 * Memory Usage: 6 MB, less than 32.56% of C++ online submissions for Reverse Integer.
 */

