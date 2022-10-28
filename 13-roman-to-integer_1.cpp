class Solution {
 public:
  int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'I') {
        if (i + 1 < s.size() && s[i + 1] == 'V') {
          result += 4;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'X') {
          result += 9;
          i++;
        } else {
          result += 1;
        }
      } else if (s[i] == 'X') {
        if (i + 1 < s.size() && s[i + 1] == 'L') {
          result += 40;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'C') {
          result += 90;
          i++;
        } else {
          result += 10;
        }
      } else if (s[i] == 'C') {
        if (i + 1 < s.size() && s[i + 1] == 'D') {
          result += 400;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'M') {
          result += 900;
          i++;
        } else {
          result += 100;
        }
      } else if (s[i] == 'V') {
        result += 5;
      } else if (s[i] == 'L') {
        result += 50;
      } else if (s[i] == 'D') {
        result += 500;
      } else {
        result += 1000;
      }
    }
    return result;
  }
};

/* Runtime: 19 ms, faster than 55.18% of C++ online submissions for Roman to Integer.
 * Memory Usage: 6 MB, less than 69.50% of C++ online submissions for Roman to Integer.
 */

