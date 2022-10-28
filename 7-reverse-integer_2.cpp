class Solution {
 public:
  int reverse(int x) {
    int result = 0;
    while (x != 0) {
      int digit = x % 10;
      if ((result > 0 && result > (INT_MAX - digit) / 10)
          || (result < 0 && result < (INT_MIN - digit) / 10)) {
        return 0;
      }
      result = result * 10 + digit;
      x /= 10;
    }
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
 * Memory Usage: 5.9 MB, less than 32.56% of C++ online submissions for Reverse Integer.
 */

