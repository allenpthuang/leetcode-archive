class Solution {
 private:
  int calc_sq_sum(int num) {
    int sum = 0;
    while (num != 0) {
      sum += pow((num % 10), 2);
      num /= 10;
    }
    return sum;
  }
 public:
  bool isHappy(int n) {
    unordered_set<int> seen;
    int cur_sum = n;
    while (true) {
      cur_sum = calc_sq_sum(cur_sum);
      if (cur_sum == 1) {
        return true;
      }
      if (seen.count(cur_sum) > 0) {
        return false;
      }
      seen.insert(cur_sum);
    }
    return false;
  }
};

/* Runtime: 6 ms, faster than 28.22% of C++ online submissions for Happy Number.
 * Memory Usage: 6.4 MB, less than 27.17% of C++ online submissions for Happy Number.
 */

