class Solution {
 private:
  vector<vector<int> > result;
  vector<int> cur_res;

  void worker(int cur_num, int n, int k) {
    if (k == 0) {
      result.push_back(cur_res);
      return;
    }

    for (int i = cur_num; i <= n; i++) {
      cur_res.push_back(i);
      worker(i + 1, n, k - 1);
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> combine(int n, int k) {
    worker(1, n, k);
    return result;
  }
};

/* Runtime: 37 ms, faster than 51.13% of C++ online submissions for Combinations.
 * Memory Usage: 9.9 MB, less than 61.63% of C++ online submissions for Combinations.
 */

