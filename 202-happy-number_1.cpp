class Solution {
 public:
  bool isHappy(int n) {
    int cur_n = n;
    unordered_set<int> sums;
    
    while (true) {
      if (cur_n == 1) return true;
      vector<int> digits;

      while (cur_n > 0) {
        digits.push_back(cur_n % 10);
        cur_n = cur_n / 10;
      }

      int sum = 0;
      for (int digit : digits) {
        sum += (digit * digit);
      }
      if (sums.find(sum) != sums.end()) {
        return false;
      } else {
        sums.insert(sum);
      }
      
      cur_n = sum;
    }
  }
};

/* Runtime: 4 ms, faster than 39.64% of C++ online submissions for Happy Number.
 * Memory Usage: 6.9 MB, less than 5.71% of C++ online submissions for Happy Number.
 */

